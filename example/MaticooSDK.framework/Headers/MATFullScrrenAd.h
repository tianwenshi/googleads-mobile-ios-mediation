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
@property (nonatomic, assign) BOOL alreadyPlayVideo;
@property (nonatomic, assign) BOOL alreadyCloseVisible;
@property (nonatomic, strong) NSString *biddingRequestId;
@property (nonatomic, assign) NSInteger adShow;
@property (nonatomic, assign) NSInteger countDown;
@property (nonatomic, assign) BOOL canSkip;
@property (nonatomic, assign) BOOL isPreloading;

- (void)closeControlEvent;
- (void)prepareCloseButton:(CGFloat)p;
- (void)addClostButtonControl:(NSInteger) top right:(NSInteger) right;
- (void)removeCloseButton;
- (void)setButtonImage;
- (void)presentModalView:(UIView*)view UIController:(UIViewController*) viewController;
- (void)cacheMediaFiles:(NSArray*)mediaFiles resources:(NSArray*)resources;
- (NSInteger)getAdType;
- (void)checkVideoPlay;
- (void)webviewImp;
- (void)webviewClick;
- (void)webviewVideoImp;
- (void)webviewLoadSuccess;
- (void)webviewLoadFailed:(NSString*) msg;
- (void)webviewCloseVisible;
- (void)loadAd;
- (void)pauseAd;
- (void)resumeAd;
- (void)dismissModalView:(MATWebview*)view animated:(BOOL)animated;
//- (void)webviewCacheSuccess;
@end

NS_ASSUME_NONNULL_END
