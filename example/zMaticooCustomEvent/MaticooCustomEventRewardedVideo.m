//
//  MaticooCustomEventRewardedVideo.m
//  RewardedVideoExample
//
//  Created by root on 2023/9/12.
//  Copyright © 2023 Google. All rights reserved.
//

#import "MaticooCustomEventRewardedVideo.h"
#include <stdatomic.h>
#include "MaticooMediationTrackManager.h"
@import MaticooSDK;
#import "MaticooCustomExtras.h"

@interface MaticooCustomEventRewardedVideo () <MATRewardedVideoAdDelegate, GADMediationRewardedAd, GADMediationAdapter> {
  /// Handle rewarded ads from Sample SDK.
  MATRewardedVideoAd *_rewardedAd;

  /// Completion handler to call when sample rewarded ad finishes loading.
  GADMediationRewardedLoadCompletionHandler _loadCompletionHandler;

  ///  Delegate for receiving rewarded ad notifications.
  id<GADMediationRewardedAdEventDelegate> _adEventDelegate;
}

@end

@implementation MaticooCustomEventRewardedVideo

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
    GADVersionNumber version = {1.1};
    return version;
}

+ (nullable Class<GADAdNetworkExtras>)networkExtrasClass {
    return [MaticooCustomExtras class];
}

- (void)loadRewardedAdForAdConfiguration:(GADMediationRewardedAdConfiguration *)adConfiguration
                       completionHandler:
(GADMediationRewardedLoadCompletionHandler)completionHandler {
    __block atomic_flag completionHandlerCalled = ATOMIC_FLAG_INIT;
    __block GADMediationRewardedLoadCompletionHandler originalCompletionHandler =
    [completionHandler copy];
    
    _loadCompletionHandler = ^id<GADMediationRewardedAdEventDelegate>(
                                                                      _Nullable id<GADMediationRewardedAd> ad, NSError *_Nullable error) {
                                                                          // Only allow completion handler to be called once.
                                                                          if (atomic_flag_test_and_set(&completionHandlerCalled)) {
                                                                              return nil;
                                                                          }
                                                                          
                                                                          id<GADMediationRewardedAdEventDelegate> delegate = nil;
                                                                          if (originalCompletionHandler) {
                                                                              // Call original handler and hold on to its return value.
                                                                              delegate = originalCompletionHandler(ad, error);
                                                                          }
                                                                          
                                                                          // Release reference to handler. Objects retained by the handler will also be released.
                                                                          originalCompletionHandler = nil;
                                                                          
                                                                          return delegate;
                                                                      };
    
    NSString *adUnit = adConfiguration.credentials.settings[@"parameter"];
    if (adUnit == nil){
        NSError *error= [NSError errorWithDomain:@"com.google.zmaticoo" code:100 userInfo:[NSDictionary dictionaryWithObject:@"zmaticoo placement id is null" forKey:@"reason"]];
        _loadCompletionHandler(nil, error);
        return;
    }
    _rewardedAd = [[MATRewardedVideoAd alloc] initWithPlacementID:adUnit];
    _rewardedAd.delegate = self;
    
    id extras = adConfiguration.extras;
    if (extras != nil && [extras isKindOfClass:[MaticooCustomExtras class]]){
        _rewardedAd.localExtra = ((MaticooCustomExtras *)extras).localExtra;
    }
    
    [_rewardedAd loadAd];
    [MaticooMediationTrackManager trackMediationAdRequest:adUnit adType:REWARDEDVIDEO isAutoRefresh:NO];
}

#pragma mark GADMediationRewardedAd implementation

- (void)presentFromViewController:(nonnull UIViewController *)viewController {
    if (_rewardedAd && _rewardedAd.isReady){
        [_rewardedAd showAdFromViewController:viewController];
        [MaticooMediationTrackManager trackMediationAdShow:_rewardedAd.placementID adType:REWARDEDVIDEO];
    }
}

#pragma mark SampleRewardedAdDelegate implementation

- (void)rewardedVideoAdDidLoad:(MATRewardedVideoAd *)rewardedVideoAd{
    _adEventDelegate = _loadCompletionHandler(self, nil);
    [MaticooMediationTrackManager trackMediationAdRequestFilled:rewardedVideoAd.placementID adType:REWARDEDVIDEO];
}

- (void)rewardedVideoAdWillClose:(MATRewardedVideoAd *)rewardedVideoAd{
    [_adEventDelegate willDismissFullScreenView];
}

- (void)rewardedVideoAdDidClose:(MATRewardedVideoAd *)rewardedVideoAd {
    [_adEventDelegate didDismissFullScreenView];
}

- (void)rewardedVideoAd:(MATRewardedVideoAd *)rewardedVideoAd didFailWithError:(NSError *)error{
    _adEventDelegate = _loadCompletionHandler(nil, error);
    [MaticooMediationTrackManager trackMediationAdRequestFailed:rewardedVideoAd.placementID adType:REWARDEDVIDEO msg:error.description];
}

- (void)rewardedVideoAdWillLogImpression:(MATRewardedVideoAd *)rewardedVideoAd {
    [_adEventDelegate willPresentFullScreenView];
    [MaticooMediationTrackManager trackMediationAdImp:rewardedVideoAd.placementID adType:REWARDEDVIDEO];
}

- (void)rewardedVideoAdStarted:(MATRewardedVideoAd *)rewardedVideoAd{
    [_adEventDelegate didStartVideo];
}

- (void)rewardedVideoAdDidClick:(MATRewardedVideoAd *)rewardedVideoAd{
    [_adEventDelegate reportClick];
    [MaticooMediationTrackManager trackMediationAdClick:rewardedVideoAd.placementID adType:REWARDEDVIDEO];
}

- (void)rewardedVideoAdCompleted:(MATRewardedVideoAd *)rewardedVideoAd{
    [_adEventDelegate didEndVideo];
}

- (void)rewardedVideoAdReward:(MATRewardedVideoAd *)rewardedVideoAd {
  [_adEventDelegate didRewardUser];
}

- (void)rewardedVideoAd:(MATRewardedVideoAd *)rewardedVideoAd displayFailWithError:(NSError *)error{
    [_adEventDelegate didFailToPresentWithError:error];
    [MaticooMediationTrackManager trackMediationAdImpFailed:rewardedVideoAd.placementID adType:INTERSTITIAL msg:error.description];
}

@end
