//
//  MATInteractAd.h
//  MaticooSDK
//
//  Created by Mirinda on 2023/5/23.
//

#import <UIKit/UIKit.h>
#import "MATFullScrrenAd.h"
NS_ASSUME_NONNULL_BEGIN
@class MATInteractAd;
@protocol MATInteractAdDelegate <NSObject>
- (void)interactAdLoadSuccess:(MATInteractAd *)interactAd andAdEntranceView:(UIView *)adView;
- (void)interactAdFailed:(MATInteractAd *)interactAd withError:(NSError*)error;
- (void)InteractAdEntranceShowed:(MATInteractAd *)interactAd;
- (void)interactAdDisplayed:(MATInteractAd *)interactAd;
- (void)interactAdDisplayFailed:(MATInteractAd *)interactAd withError:(NSError*)error;
- (void)interactAdClicked:(MATInteractAd *)interactAd;
- (void)interactAdClosed:(MATInteractAd *)interactAd;
@end

@interface MATInteractAd : MATFullScrrenAd
@property (nonatomic, weak) id<MATInteractAdDelegate> delegate;

- (instancetype)initWithPlacementID:(NSString *)placementID;
- (void)loadAd;
- (void)loadAd:(NSString*)biddingRequestId;
- (void)loadAdOnController:(UIViewController *)VC;
@end

NS_ASSUME_NONNULL_END
