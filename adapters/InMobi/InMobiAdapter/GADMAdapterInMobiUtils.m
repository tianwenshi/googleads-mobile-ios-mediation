// Copyright 2019 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#import "GADMAdapterInMobiUtils.h"

#import <GoogleMobileAds/GoogleMobileAds.h>
#import <InMobiSDK/InMobiSDK-Swift.h>

#import "GADInMobiExtras.h"
#import "GADMAdapterInMobiConstants.h"

#pragma mark - Internal Utility Method Prototypes

/// Sets up additional InMobi targeting information from the specified |extras|.
void GADMAdapterInMobiSetTargetingFromExtras(GADInMobiExtras *_Nullable extras);

void GADMAdapterInMobiSetIsAgeRestricted(NSNumber *_Nullable isRestricted);

#pragma mark - Public Utility Methods

void GADMAdapterInMobiMutableArrayAddObject(NSMutableArray *_Nullable array,
                                            NSObject *_Nonnull object) {
  if (object) {
    [array addObject:object];  // Allow pattern.
  }
}

void GADMAdapterInMobiMutableSetAddObject(NSMutableSet *_Nullable set, NSObject *_Nonnull object) {
  if (object) {
    [set addObject:object];  // Allow pattern.
  }
}

void GADMAdapterInMobiMapTableSetObjectForKey(NSMapTable *_Nonnull mapTable,
                                              id<NSCopying> _Nullable key, id _Nullable value) {
  if (value && key) {
    [mapTable setObject:value forKey:key];  // Allow pattern.
  }
}

void GADMAdapterInMobiMapTableRemoveObjectForKey(NSMapTable *_Nullable mapTable, id _Nullable key) {
  if (key) {
    [mapTable removeObjectForKey:key];  // Allow pattern.
  }
}

void GADMAdapterInMobiMutableDictionarySetObjectForKey(NSMutableDictionary *_Nonnull dictionary,
                                                       id<NSCopying> _Nullable key,
                                                       id _Nullable value) {
  if (value && key) {
    dictionary[key] = value;  // Allow pattern.
  }
}

void GADMAdapterInMobiCacheSetObjectForKey(NSCache *_Nonnull cache, id<NSCopying> _Nullable key,
                                           id _Nullable value) {
  if (value && key) {
    [cache setObject:value forKey:key];  // Allow pattern.
  }
}

NSError *_Nonnull GADMAdapterInMobiErrorWithCodeAndDescription(GADMAdapterInMobiErrorCode code,
                                                               NSString *_Nonnull description) {
  NSDictionary *userInfo =
      @{NSLocalizedDescriptionKey : description, NSLocalizedFailureReasonErrorKey : description};
  NSError *error = [NSError errorWithDomain:GADMAdapterInMobiErrorDomain
                                       code:code
                                   userInfo:userInfo];
  return error;
}

NSError *_Nullable GADMAdapterInMobiValidatePlacementIdentifier(
    NSNumber *_Nonnull placementIdentifier) {
  if (placementIdentifier.longLongValue) {
    return nil;
  }

  return GADMAdapterInMobiErrorWithCodeAndDescription(
      GADMAdapterInMobiErrorInvalidServerParameters,
      @"GADMediationAdapterInMobi - Error : Placement ID not specified.");
}

void GADMAdapterInMobiSetTargetingFromExtras(GADInMobiExtras *_Nullable extras) {
  if (extras == nil) {
    return;
  }

  // The geographic location is preffered over the city-stsate-country.
  if (extras.location) {
    [IMSdk setLocation:extras.location];
  } else if (extras.city && extras.state && extras.country) {
    [IMSdk setLocationWithCity:extras.city state:extras.state country:extras.country];
  }

  if (extras.postalCode) {
    [IMSdk setPostalCode:extras.postalCode];
  }

  if (extras.areaCode) {
    [IMSdk setAreaCode:extras.areaCode];
  }

  if (extras.interests) {
    [IMSdk setInterests:extras.interests];
  }

  if (extras.age) {
    [IMSdk setAge:extras.age];
  }

  if (extras.yearOfBirth) {
    [IMSdk setYearOfBirth:extras.yearOfBirth];
  }

  if (extras.language) {
    [IMSdk setLanguage:extras.language];
  }

  if (extras.educationType) {
    [IMSdk setEducation:extras.educationType];
  }

  if (extras.ageGroup) {
    [IMSdk setAgeGroup:extras.ageGroup];
  }

  if (extras.logLevel) {
    [IMSdk setLogLevel:extras.logLevel];
  }
}

void GADMAdapterInMobiLog(NSString *_Nonnull format, ...) {
  va_list arguments;
  va_start(arguments, format);
  NSString *log = [[NSString alloc] initWithFormat:format arguments:arguments];
  va_end(arguments);

  NSLog(@"GADMediationAdapterInMobi - %@", log);
}

void GADMAdapterInMobiSetTargetingFromAdConfiguration(
    GADMediationAdConfiguration *_Nonnull adConfig) {
  GADMAdapterInMobiSetTargetingFromExtras(adConfig.extras);
  GADMAdapterInMobiSetIsAgeRestricted(
      GADMobileAds.sharedInstance.requestConfiguration.tagForChildDirectedTreatment);
}

void GADMAdapterInMobiSetIsAgeRestricted(NSNumber *_Nullable isRestricted) {
  if ([isRestricted isEqual:@1]) {
    [IMSdk setIsAgeRestricted:true];
  }
}

NSDictionary<NSString *, id> *_Nonnull GADMAdapterInMobiRequestParameters(
    GADInMobiExtras *_Nullable extras,
    GADMAdapterInMobiRequestParametersMediationType _Nonnull mediationType,
    NSNumber *_Nullable childDirectedTreatment) {
  NSMutableDictionary<NSString *, id> *requestParameters = [[NSMutableDictionary alloc] init];

  if (extras && extras.additionalParameters) {
    [requestParameters addEntriesFromDictionary:extras.additionalParameters];
  }

  GADMAdapterInMobiMutableDictionarySetObjectForKey(
      requestParameters, GADMAdapterInMobiRequestParametersMediationTypeKey, mediationType);

  GADMAdapterInMobiMutableDictionarySetObjectForKey(requestParameters,
                                                    GADMAdapterInMobiRequestParametersSDKVersionKey,
                                                    GADMobileAds.sharedInstance.sdkVersion);

  if (childDirectedTreatment) {
    NSString *coppaString = [childDirectedTreatment integerValue] ? @"1" : @"0";
    GADMAdapterInMobiMutableDictionarySetObjectForKey(
        requestParameters, GADMAdapterInMobiRequestParametersCOPPAKey, coppaString);
  }

  return requestParameters;
}

void GADMAdapterInMobiSetUSPrivacyCompliance(void) {
    NSString* usPrivacyString = [[NSUserDefaults standardUserDefaults] stringForKey:GADMAdapterInMobiIABUSPrivacyString];
    [IMPrivacyCompliance setUSPrivacyString:usPrivacyString];
}

NSData *_Nullable GADMAdapterInMobiBidResponseDataFromAdConfigration(
    GADMediationAdConfiguration *_Nonnull adConfig) {
    NSString *bidResponseString = adConfig.bidResponse;
    if (!bidResponseString) {
    return nil;
    }
    return [bidResponseString dataUsingEncoding:NSUTF8StringEncoding];
}
