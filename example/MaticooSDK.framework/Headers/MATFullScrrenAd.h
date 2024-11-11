//
//  MATFullScrrenAd.h
//  MaticooSDK
//
//  Created by root on 2023/5/8.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MATModalViewController.h"
#import "MATWebview.h"
#import "MATAdModel.h"


NS_ASSUME_NONNULL_BEGIN
@class MATVideo;
@interface MATFullScrrenAd : NSObject
@property (nonatomic, strong) MATAdModel* ad;
@property (nonatomic, strong) MATModalViewController* modalViewController;
@property (nonatomic, assign) BOOL isReady;
@property (nonatomic, strong) MATWebview *__nullable matWebview;
@property (nonatomic, assign) BOOL isVideo;
@property (atomic, strong) NSMutableDictionary* baseDictionary;
@property (atomic, strong) NSMutableDictionary *biDictionary;
@property (nonatomic, strong) NSString* placementID;
@property (nonatomic, assign) BOOL isLoading;
@property (nonatomic, assign) BOOL isShowing;
@property (nonatomic, assign) BOOL alreadyImp;
@property (atomic, assign) BOOL alreadyPlayVideo;
@property (nonatomic, assign) BOOL alreadyCloseVisible;
@property (nonatomic, strong) NSString *biddingRequestId;
@property (nonatomic, assign) NSInteger adShow;
@property (nonatomic, assign) NSInteger countDown;
@property (nonatomic, assign) BOOL canSkip;
@property (nonatomic, assign) BOOL isPreloading;
@property (nonatomic, assign) BOOL isH5CloseBtnClick;
@property (nonatomic, strong) MATVideo *matVideo;
@property (nonatomic, strong) NSMutableDictionary *BIInfo;
@property (nonatomic, strong) NSTimer *videoTimeOutTimer;
@property (nonatomic, assign) NSInteger video_cache_ratio;
@property (nonatomic, assign) NSInteger local;
@property (nonatomic, assign) BOOL isSendDidLoad;
@property (nonatomic, assign) BOOL isVideoCanPlay;
@property (nonatomic, assign) BOOL isWebSuccess;
@property (nonatomic, assign) NSInteger expire;
@property (nonatomic, assign) long long adReturnTime;
@property (nonatomic, assign) BOOL isMutltipleAd;
@property (nonatomic, strong) NSString *adRequestFromServer;
@property (nonatomic, assign) float currentSeconds;
@property (nonatomic, assign) float totalSeconds;
@property (nonatomic, strong) NSString *crid;
@property (nonatomic, strong) NSDictionary *localExtra;
//@property (nonatomic, assign) BOOL isVideoPlayed;

- (void)closeControlEvent;
- (void)prepareCloseButton:(CGFloat)p;
- (void)addClostButtonControl:(NSInteger) top right:(NSInteger) right;
- (void)removeCloseButton;
- (void)setButtonImage;
- (void)presentModalView:(UIView*)view UIController:(UIViewController*) viewController;
- (void)cacheMediaFiles:(NSArray*)mediaFiles resources:(NSArray*)resources;
- (NSInteger)getAdType;
- (void)checkVideoPlay;
- (void)webviewLayout;
- (void)webviewClick;
- (void)webviewVideoImp;
- (void)webviewLoadSuccess;
- (void)webviewLoadFailed:(NSString*) msg;
- (void)trackAdImpUrl;
- (void)webviewCloseVisible;
- (void)impBannerBITrack;
- (void)loadAd;
- (void)pauseAd;
- (void)resumeAd;
- (void)dismissModalView:(MATWebview*)view animated:(BOOL)animated;
- (void)showAd:(UIViewController*) vc;
- (void)setVideoUrl:(NSArray *)urlArr andTrackData:(MATVideoResponse *)trackModel videoDelegate:(id)delegate;
- (void)sendClickTrack;
- (void)videoLoadingTimeOut:(NSTimer *)timer;
- (void)buttonChangeBig;
- (void)videoPlayerStatusReadyToPlay: (CGFloat)totalSeconds;
- (void)videoCacheSeconds:(CGFloat)cacheSeconds totalSeconds:(CGFloat)totalSeconds;
- (void)videoPlaybackProgressTrackCurrentSeconds:(CGFloat)currentSeconds totalSeconds:(CGFloat)totalSeconds;
- (void)videoDidEnterBackground;
- (void)videoEnterForeground;
- (void)videoPlayEnd;
- (void)videoLoadError:(NSError *)error;
- (void)videoPlayFailedWithError:(NSError *)error;
- (void)videoPlayState:(float)state;
- (void)webviewCacheSuccess;
-(void)sendErrorToServer:(NSError *)error withEventType:(NSString *)type andUrl:(NSString *)url;
@end

NS_ASSUME_NONNULL_END
