//
//  GADMBannerMaticoo.m
//  BannerExample
//
//  Created by root on 2023/9/12.
//  Copyright © 2023 Google. All rights reserved.
//

#import "MaticooCustomEventBanner.h"
@import MaticooSDK;
#include <stdatomic.h>
#include "MaticooMediationTrackManager.h"

#define dispatch_main_MATAdapter_ASYNC_safe(block)\
        if ([NSThread isMainThread]) {\
        block();\
        } else {\
        dispatch_async(dispatch_get_main_queue(), block);\
        }

@interface MaticooCustomEventBanner () <GADMediationAdapter, GADMediationBannerAd, MATBannerAdDelegate> {
  /// The sample banner ad.
  MATBannerAd *_bannerAd;

  /// The completion handler to call when the ad loading succeeds or fails.
  GADMediationBannerLoadCompletionHandler _loadCompletionHandler;

  /// The ad event delegate to forward ad rendering events to the Google Mobile Ads SDK.
  id<GADMediationBannerAdEventDelegate> _adEventDelegate;
}
@end


@implementation MaticooCustomEventBanner

+ (void)setUpWithConfiguration:(GADMediationServerConfiguration *)configuration
             completionHandler:(GADMediationAdapterSetUpCompletionBlock)completionHandler {
  // This is where you you will initialize the SDK that this custom event is built for.
  // Upon finishing the SDK initialization, call the completion handler with success.
    NSString *appkey = [[NSBundle mainBundle].infoDictionary objectForKey:@"zMaticooAppKey"];
      if(appkey == nil && ![appkey isEqualToString:@""]){
          NSError *error= [NSError errorWithDomain:@"com.google.zmaticoo" code:100 userInfo:[NSDictionary dictionaryWithObject:@"zmaticoo appkey is null" forKey:@"reason"]];
          completionHandler(error);
      }else{
          [[MaticooAds shareSDK] initSDK:appkey onSuccess:^{
              completionHandler(nil);
              [MaticooMediationTrackManager trackMediationInitSuccess];
          } onError:^(NSError * _Nonnull error) {
              completionHandler(error);
              [MaticooMediationTrackManager trackMediationInitFailed:error];
          }];
      }
}

+ (GADVersionNumber)adSDKVersion {
  GADVersionNumber version = {1,3,4};
  return version;
}

+ (GADVersionNumber)adapterVersion {
  GADVersionNumber version = {1.0};
  return version;
}

+ (nullable Class<GADAdNetworkExtras>)networkExtrasClass {
  return Nil;
}

- (void)loadBannerForAdConfiguration:(GADMediationBannerAdConfiguration *)adConfiguration
                   completionHandler:(GADMediationBannerLoadCompletionHandler)completionHandler{
    __block atomic_flag completionHandlerCalled = ATOMIC_FLAG_INIT;
    __block GADMediationBannerLoadCompletionHandler originalCompletionHandler =
        [completionHandler copy];

    _loadCompletionHandler = ^id<GADMediationBannerAdEventDelegate>(
        _Nullable id<GADMediationBannerAd> ad, NSError *_Nullable error) {
      // Only allow completion handler to be called once.
      if (atomic_flag_test_and_set(&completionHandlerCalled)) {
        return nil;
      }

      id<GADMediationBannerAdEventDelegate> delegate = nil;
      if (originalCompletionHandler) {
        // Call original handler and hold on to its return value.
        delegate = originalCompletionHandler(ad, error);
      }

      // Release reference to handler. Objects retained by the handler will also be released.
      originalCompletionHandler = nil;

      return delegate;
    };
    NSString *appkey = [[NSBundle mainBundle].infoDictionary objectForKey:@"zMaticooAppKey"];
      if(appkey == nil && ![appkey isEqualToString:@""]){
          NSError *error= [NSError errorWithDomain:@"com.google.zmaticoo" code:100 userInfo:[NSDictionary dictionaryWithObject:@"zmaticoo appkey is null" forKey:@"reason"]];
          _adEventDelegate = _loadCompletionHandler(nil, error);
      }else{
          [[MaticooAds shareSDK] initSDK:appkey onSuccess:^{
              dispatch_main_MATAdapter_ASYNC_safe(^{
                  NSString *adUnit = adConfiguration.credentials.settings[@"parameter"];
                  _bannerAd = [[MATBannerAd alloc] initWithPlacementID:adUnit];
                  _bannerAd.delegate = self;
                  [_bannerAd loadAd];
                  _bannerAd.frame = CGRectMake(0, 0, adConfiguration.adSize.size.width, adConfiguration.adSize.size.height);
                  [MaticooMediationTrackManager trackMediationInitSuccess];
                  [MaticooMediationTrackManager trackMediationAdRequest:adUnit adType:BANNER isAutoRefresh:NO];
              });
          } onError:^(NSError * _Nonnull error) {
              _adEventDelegate = _loadCompletionHandler(nil, error);
              [MaticooMediationTrackManager trackMediationInitFailed:error];
          }];
      }
}

#pragma mark GADMediationBannerAd implementation

- (nonnull UIView *)view {
  return _bannerAd;
}

- (void)bannerAdDidLoad:(MATBannerAd *)nativeBannerAd{
    _bannerAd = nativeBannerAd;
    _adEventDelegate = _loadCompletionHandler(self, nil);
    [MaticooMediationTrackManager trackMediationAdRequestFilled:nativeBannerAd.placementID adType:BANNER];
}

- (void)bannerAd:(nonnull MATBannerAd *)nativeBannerAd didFailWithError:(nonnull NSError *)error {
    _adEventDelegate = _loadCompletionHandler(nil, error);
    [MaticooMediationTrackManager trackMediationAdRequestFailed:nativeBannerAd.placementID adType:BANNER];
}

- (void)bannerAdDidClick:(nonnull MATBannerAd *)banner {
    [_adEventDelegate reportClick];
    [MaticooMediationTrackManager trackMediationAdClick:banner.placementID adType:BANNER];
}

- (void)bannerAdDidImpression:(nonnull MATBannerAd *)banner {
    [_adEventDelegate reportImpression];
    [MaticooMediationTrackManager trackMediationAdImp:banner.placementID adType:BANNER];
}

- (void)bannerAdDismissed:(nonnull MATBannerAd *)bannerAd{
    [_adEventDelegate didDismissFullScreenView];
}
@end
