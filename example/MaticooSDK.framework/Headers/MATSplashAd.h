//
//  MATSpalshAd.h
//  MaticooSDK
//
//  Created by root on 2023/6/1.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MATFullScrrenAd.h"

NS_ASSUME_NONNULL_BEGIN

@protocol MATSplashAdDelegate;

@interface MATSplashAd : MATFullScrrenAd
@property (nonatomic, weak) id<MATSplashAdDelegate> delegate;
- (MATSplashAd*)initWithPlacementID:(NSString*)placementID;
- (void)loadAd;
- (void)loadAd:(NSString*)biddingRequestId;
- (void)showAdFromViewController:(UIViewController*) vc;
- (void)showAdFromRootViewController;
@end

@protocol MATSplashAdDelegate <NSObject>
- (void)splashAdDidLoad:(MATSplashAd *)splashAd;
- (void)splashAd:(MATSplashAd *)splashAd didFailWithError:(NSError *)error;
- (void)splashAd:(MATSplashAd *)splashAd displayFailWithError:(NSError *)error;
- (void)splashAdWillLogImpression:(MATSplashAd *)splashAd;
- (void)splashAdDidClick:(MATSplashAd *)splashAd;
- (void)splashAdWillClose:(MATSplashAd *)splashAd;
- (void)splashAdDidClose:(MATSplashAd *)splashAd;
@end

NS_ASSUME_NONNULL_END
