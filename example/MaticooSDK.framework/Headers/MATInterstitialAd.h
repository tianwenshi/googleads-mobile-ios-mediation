//
//  MATInterstitialAd.h
//  MaticooSDK
//
//  Created by root on 2023/4/23.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MATFullScrrenAd.h"

NS_ASSUME_NONNULL_BEGIN
@protocol MATInterstitialAdDelegate;

@interface MATInterstitialAd : MATFullScrrenAd
@property (nonatomic, weak) id<MATInterstitialAdDelegate> delegate;
- (MATInterstitialAd*)initWithPlacementID:(NSString*)placementID;
- (void)loadAd;
- (void)loadAd:(NSString*)biddingRequestId;
- (void)showAdFromViewController:(UIViewController*) vc;
- (void)showAdFromRootViewController;
@end

@protocol MATInterstitialAdDelegate <NSObject>
- (void)interstitialAdDidLoad:(MATInterstitialAd *)interstitialAd;
- (void)interstitialAd:(MATInterstitialAd *)interstitialAd didFailWithError:(NSError *)error;
- (void)interstitialAd:(MATInterstitialAd *)interstitialAd displayFailWithError:(NSError *)error;
- (void)interstitialAdWillLogImpression:(MATInterstitialAd *)interstitialAd;
- (void)interstitialAdDidClick:(MATInterstitialAd *)interstitialAd;
- (void)interstitialAdWillClose:(MATInterstitialAd *)interstitialAd;
- (void)interstitialAdDidClose:(MATInterstitialAd *)interstitialAd;
@end

NS_ASSUME_NONNULL_END
