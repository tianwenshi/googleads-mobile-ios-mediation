//
//  MATRewardedVideo.h
//  MaticooSDK
//
//  Created by root on 2023/5/8.
//

#import "MATFullScrrenAd.h"

NS_ASSUME_NONNULL_BEGIN
@protocol MATRewardedVideoAdDelegate;

@interface MATRewardedVideoAd : MATFullScrrenAd
@property (nonatomic, weak) id<MATRewardedVideoAdDelegate> delegate;
- (MATRewardedVideoAd*)initWithPlacementID:(NSString*)placementID;
- (void)loadAd;
- (void)loadAd:(NSString*)biddingRequestId;
- (void)showAdFromViewController:(UIViewController*) vc;
- (void)showAdFromRootViewController;
@end

@protocol MATRewardedVideoAdDelegate <NSObject>
- (void)rewardedVideoAdDidLoad:(MATRewardedVideoAd *)rewardedVideoAd;
- (void)rewardedVideoAd:(MATRewardedVideoAd *)rewardedVideoAd didFailWithError:(NSError *)error;
- (void)rewardedVideoAd:(MATRewardedVideoAd *)rewardedVideoAd displayFailWithError:(NSError *)error;
- (void)rewardedVideoAdStarted:(MATRewardedVideoAd *)rewardedVideoAd;
- (void)rewardedVideoAdCompleted:(MATRewardedVideoAd *)rewardedVideoAd;
- (void)rewardedVideoAdWillLogImpression:(MATRewardedVideoAd *)rewardedVideoAd;
- (void)rewardedVideoAdDidClick:(MATRewardedVideoAd *)rewardedVideoAd;
- (void)rewardedVideoAdWillClose:(MATRewardedVideoAd *)rewardedVideoAd;
- (void)rewardedVideoAdDidClose:(MATRewardedVideoAd *)rewardedVideoAd;
- (void)rewardedVideoAdReward:(MATRewardedVideoAd *)rewardedVideoAd;
@end
NS_ASSUME_NONNULL_END
