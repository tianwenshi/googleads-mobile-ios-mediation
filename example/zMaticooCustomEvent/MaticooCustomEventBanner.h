//
//  GADMBannerMaticoo.h
//  BannerExample
//
//  Created by root on 2023/9/12.
//  Copyright © 2023 Google. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GoogleMobileAds/GoogleMobileAds.h>
@import GoogleMobileAds;

NS_ASSUME_NONNULL_BEGIN

@interface MaticooCustomEventBanner : NSObject
- (void)loadBannerForAdConfiguration:(GADMediationBannerAdConfiguration *)adConfiguration
                   completionHandler:(GADMediationBannerLoadCompletionHandler)completionHandler;
@end

NS_ASSUME_NONNULL_END
