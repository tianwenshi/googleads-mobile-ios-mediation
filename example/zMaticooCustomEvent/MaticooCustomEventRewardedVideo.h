//
//  MaticooCustomEventRewardedVideo.h
//  RewardedVideoExample
//
//  Created by root on 2023/9/12.
//  Copyright © 2023 Google. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GoogleMobileAds/GoogleMobileAds.h>

@interface MaticooCustomEventRewardedVideo : NSObject
- (void)loadRewardedAdForAdConfiguration:(GADMediationRewardedAdConfiguration *)adConfiguration
                       completionHandler:
                           (GADMediationRewardedLoadCompletionHandler)completionHandler;
@end
