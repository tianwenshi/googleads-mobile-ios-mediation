//
//  MATBanner.h
//  MaticooSDK
//
//  Created by root on 2023/4/14.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol MATBannerAdDelegate;
@interface MATBannerAd : UIView
@property (nonatomic, weak) id<MATBannerAdDelegate> delegate;
@property (nonatomic, strong) NSString* placementID;
@property (nonatomic, strong) NSDictionary* localExtra;
- (MATBannerAd*)initWithPlacementID:(NSString*)placementID;
- (void)loadAd;
- (void)loadAd:(NSString*)biddingRequestId;
@end

@protocol MATBannerAdDelegate <NSObject>
- (void)bannerAdDidLoad:(MATBannerAd *)bannerAd;
- (void)bannerAd:(MATBannerAd *)bannerAd didFailWithError:(NSError *)error;
- (void)bannerAdDidImpression:(MATBannerAd*) bannerAd;
- (void)bannerAd:(MATBannerAd *)bannerAd showFailWithError:(NSError *)error;
- (void)bannerAdDidClick:(MATBannerAd*) bannerAd;
- (void)bannerAdDismissed:(MATBannerAd*) bannerAd;
@end
NS_ASSUME_NONNULL_END
