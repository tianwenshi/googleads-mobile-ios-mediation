//
//  MATNativeAd.h
//  MaticooSDK
//
//  Created by Mirinda on 2023/4/25.
//

#import <Foundation/Foundation.h>
#import "MATWebview.h"
#import <CoreGraphics/CoreGraphics.h>

NS_ASSUME_NONNULL_BEGIN
@class MATNativeAd;

typedef NS_ENUM(NSUInteger, BrandLogoPosition) {
    ADCHOICES_TOP_RIGHT  = 1,
    ADCHOICES_BOTTOM_RIGHT,
    ADCHOICES_BOTTOM_LEFT
};

typedef NS_ENUM(NSUInteger, AdElement) {
    AD_TITLE        = 1,   //title
    AD_ICON         = 2,   //icon
    AD_SPONSORED    = 3,   //sponsored
    AD_DESCRIBE     = 4,   //describe
    AD_CTATEXT      = 5    //ctatext
};


@interface MATNativeAdElements : NSObject
@property (nonatomic, strong) NSString* _Nullable title;
@property (nonatomic, strong) NSString* _Nullable iconUrl;
@property (nonatomic, strong) NSString* _Nullable sponsored;
@property (nonatomic, strong) NSString* _Nullable describe;
@property (nonatomic, strong) NSString* _Nullable ctatext;
@property (nonatomic, strong) NSString* _Nullable  brandLogo; //图片的base64字符串
@property (nonatomic, strong) MATWebview* _Nonnull mediaView;
@end

@protocol MATNativeAdDelegate <NSObject>
- (void)nativeAdLoadSuccess:(MATNativeAd *)nativeAd;
- (void)nativeAdFailed:(MATNativeAd *)nativeAd withError:(NSError*)error;
- (void)nativeAdDisplayed:(MATNativeAd *)nativeAd;
- (void)nativeAdDisplayFailed:(MATNativeAd *)nativeAd;
- (void)nativeAdClicked:(MATNativeAd *)nativeAd;
- (void)nativeAdClosed:(MATNativeAd *)nativeAd;
@end

@interface MATNativeAd : UIView
@property (nonatomic, weak) id<MATNativeAdDelegate> delegate;
@property (nonatomic, strong) MATNativeAdElements* nativeElements;
@property (nonatomic, assign, readonly) BOOL isTemplateAd;
@property (nonatomic, strong) NSString* placementID;
@property (nonatomic, strong) NSDictionary* localExtra;

- (instancetype)initWithPlacementID:(NSString *)placementID;
- (void)loadAd;
- (void)loadAd:(NSString*)biddingRequestId;
- (void)nativeAdClosedReportWithReason:(NSString * _Nullable)reason; // for user Self-Rendering style ad
//Personalized settings
- (void)setAdTemplateStyle;
- (void)setAdSize:(CGSize)adSize;
- (void)setBrandLogoPositionOnAd:(BrandLogoPosition)logoPosition;
- (void)setRequiredAdElements:(AdElement)element,...;
- (void)setVideoIsMute:(BOOL)isMute;//mute video by default
- (void)registerViewForInteraction:( UIView * _Nonnull )AdView
                          iConView:(UIView * _Nullable)iConView
                       CTAView:(UIView * _Nullable)ctaView;
 

@end

NS_ASSUME_NONNULL_END
