//
//  MATWebview.h
//  MaticooSDK
//
//  Created by root on 2023/4/17.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>
#import "MATAdModel.h"

NS_ASSUME_NONNULL_BEGIN
@protocol MATWebviewDelegate <NSObject>
//js
//- (void)webviewCacheSuccess;
- (void)webviewLoadSuccess;
- (void)webviewJsLoadSuccess;
- (void)webviewLoadFailed:(NSString*)msg;
- (void)webviewImageImp; //image banner imp
- (void)webviewVideoImp; //video imp
- (void)webviewVideoCompleted;
- (void)webviewVideoClick:(NSString*)position;
- (void)webviewSKANClick:(NSDictionary*)productParameters position:(NSString*)position;
- (void)webviewAdRewareded;
- (void)webviewCloseAd;
- (void)webviewVideoMuted:(BOOL)isMuted;
- (void)webviewCloseVisible;
- (void)webviewInteract:(NSDictionary*)dict;
- (void)webviewInteractClose;
//native
- (void)webviewClick;
- (void)webviewLayout;     //layout
- (void)webviewPauseAd;
- (void)webviewResumeAd;
- (void)webviewJSLog:(NSString*)eventName params:(NSDictionary*)params;
- (void)webviewVastVideoInfo:(NSDictionary*)info;
- (void)webviewVastVideoBridgeCompanionImp;

//escalation delegate
-(void)escalationEventError:(NSError *)error withEventType:(NSString *)type andUrl:(NSString *)url;
@end


@interface MATWebview : UIView
@property (nonatomic, weak) id<MATWebviewDelegate> delegate;
@property (nonatomic, assign) BOOL isVideoAd;
@property (nonatomic, strong) UIViewController *inVC;
@property (nonatomic, assign) BOOL isH5CloseBtnClick;
@property (nonatomic, strong) NSString *videoInitJson;
@property (nonatomic, strong) NSString *crid;
@property (nonatomic, strong) NSString *finalUrl;
@property (nonatomic, assign) BOOL isMutltipleAd;
- (void)loadUrl:(NSString*)url;
- (void)dissMiss;
- (void)playVideo;
//- (void)setVideoCacheFinish;
//- (void)setVideoCacheFailed;
- (void)evaluate:(NSString*)script;
- (void)setSKANResponse:(MATSKANResponse*) skad;
- (void)setWebviewClearColor;

//for new video multi-hierarchical rendering
- (void)evaluateForVastVideo:(NSString*)script;
    //for new video multi-hierarchical rendering
- (void)setClickArea:(NSInteger)areaFlag ratio:(CGFloat)ratio isMutltipleAd:(BOOL)isMutltiple;
- (void)setAutoClick:(NSInteger)autoClick;
@end

NS_ASSUME_NONNULL_END
