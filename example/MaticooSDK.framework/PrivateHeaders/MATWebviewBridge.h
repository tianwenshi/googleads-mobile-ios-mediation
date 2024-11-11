//
//  MATWebviewBridge.h
//  MaticooSDK
//
//  Created by root on 2023/4/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@protocol MATWebviewBridgeDelegate;

@interface MATWebviewBridge : NSObject
@property (nonatomic, weak) id<MATWebviewBridgeDelegate> delegate;
@property (nonatomic,assign) BOOL isH5BtnClick;
- (BOOL)parseRequestStr:(NSString*)requestStr;
@end


@protocol MATWebviewBridgeDelegate <NSObject>
@required
- (void)mraidBridge:(MATWebviewBridge*)bridge windowOnload:(BOOL)finish;
- (void)mraidBridgeCloseAd:(MATWebviewBridge*)bridge;
- (void)mraidBridgeJSLoadSuccess:(MATWebviewBridge*)bridge;
- (void)mraidBridgeJSLoadFailed:(MATWebviewBridge*)bridge;
- (void)mraidBridgeImageImp:(MATWebviewBridge*)bridge;
- (void)mraidBridgeVideoImp:(MATWebviewBridge*)bridge;
- (void)mraidBridgeVideoClick:(MATWebviewBridge *)bridge position:(NSString *)position url:(NSString*)url;
- (void)mraidBridgeVideoCompleted:(MATWebviewBridge*)bridge;
- (void)mraidBridgeAdReward:(MATWebviewBridge*)bridge;
- (void)mraidBridgeVideo:(MATWebviewBridge*)bridge isMuted:(BOOL)isMuted;
- (void)mraidCloseVisible:(MATWebviewBridge*)bridge;
- (void)mraidBridgeInteract:(MATWebviewBridge*)bridge info:(NSDictionary*)dict;
- (void)mraidBridgeInteractClose:(MATWebviewBridge*)bridge;
- (void)mraidBridgeJsLog:(MATWebviewBridge*)bridge eventName:(NSString*)eventName info:(NSDictionary*)dict;
- (void)vastVideoBridge:(MATWebviewBridge*)bridge videoInfo:(NSDictionary*)info;
- (void)vastVideoBridgeCompanionImp:(MATWebviewBridge*)bridge;
@end

static NSString* MATWebviewBridgeCommandWindowOnload = @"onload";
static NSString* MATWebviewBridgeCommandConsole = @"console://localhost?";
NS_ASSUME_NONNULL_END
