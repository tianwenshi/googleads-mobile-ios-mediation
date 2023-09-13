//
//  MATTrackManager.h
//  MaticooSDK
//
//  Created by root on 2023/5/4.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MATTrackManager : NSObject
+ (void)trackSDKInitStart:(NSDictionary*)biDictionary;
+ (void)trackSDKInitSuccess:(NSDictionary*)biDictionary;
+ (void)trackSDKInitFailed:(NSInteger) eventCode msg:(NSString*)msg dict:(NSDictionary*)biDictionary appKey:(NSString*)appKey; //"1、初始化前置检查异常（AppKey、权限）2、初始化期间发生的crash3、配置文件请求成功之后，响应码错误。4、配置文件请求结果为空。5、配置文件请求的配置项为空。6、配置信息，网络请求失败"
+ (void)trackAdRequest:(NSString*)pid adType:(NSInteger)adtype rid:(NSString*)rid isAutoRefresh:(NSInteger) isAuto dict:(NSDictionary*)biDictionary;
//+ (void)trackAdRequestInProcess:(NSString*)pid adType:(NSInteger)adtype dict:(NSDictionary*)baseDicionary;

+ (void)trackAdRequestInTraffic:(NSString*)pid adType:(NSInteger)adtype dict:(NSDictionary*)biDictionary; //广告走网络请求
+ (void)trackAdHitCache:(NSString*)pid adType:(NSInteger)adtype isAutoRefresh:(NSInteger)isAuto dict:(NSDictionary*)biDictionary rid:(NSString*)rid; //广告走网络请求
+ (void)trackAdLoadSuccess:(NSString*)pid adType:(NSInteger)adtype duration:(NSTimeInterval) duration dict:(NSDictionary*)biDictionary rid:(NSString*)rid;
+ (void)trackAdRequestSuccess:(NSString*)pid adType:(NSInteger)adtype duration:(NSTimeInterval) duration dict:(NSDictionary*)biDictionary rid:(NSString*)rid;
+ (void)trackAdRequestNetworkFailed:(NSString*)pid adType:(NSInteger)adtype msg:(NSString*) msg dict:(NSDictionary*)biDictionary;
+ (void)trackAdRequestFailed:(NSString*)pid adType:(NSInteger)adtype msg:(NSString*) msg dict:(NSDictionary*)biDictionary;
+ (void)trackAdShowFailed:(NSString*)pid adType:(NSInteger)adtype msg:(NSString*) msg dict:(NSDictionary*)biDictionary rid:(NSString*)rid;
+ (void)trackVideoPlayed:(NSString*)pid adType:(NSInteger)adtype dict:(NSDictionary*)biDictionary rid:(NSString*)rid;
+ (void)trackVideoCompleted:(NSString*)pid adType:(NSInteger)adtype dict:(NSDictionary*)biDictionary rid:(NSString*)rid;
+ (void)trackClick:(NSString*)pid adType:(NSInteger)adtype position:(NSString*)position dict:(NSDictionary*)biDictionary rid:(NSString*)rid;
+ (void)trackShow:(NSString*)pid adType:(NSInteger)adtype dict:(NSDictionary*)biDictionary rid:(NSString*)rid;
+ (void)trackClose:(NSString*)pid adType:(NSInteger)adtype button:(NSString*)btnName dict:(NSDictionary*)biDictionary rid:(NSString*)rid;
+ (void)trackVideoMuted:(NSString*)pid adType:(NSInteger)adtype isMute:(BOOL)isMute dict:(NSDictionary*)biDictionary rid:(NSString*)rid;
+ (void)trackLoadWhileShowing:(NSString*)pid adType:(NSInteger)adtype dict:(NSDictionary*)biDictionary;
+ (void)trackInteractiveIconShow:(NSString *)pid dict:(NSDictionary*)biDictionary rid:(NSString*)rid;
+ (void)trackInteractiveIconClick:(NSString *)pid dict:(NSDictionary*)biDictionary rid:(NSString*)rid;
+ (void)trackInteractiveIconShowBi:(NSString *)pid dict:(NSDictionary*)biDictionary rid:(NSString*)rid;
+ (void)trackInteractiveIconClickBi:(NSString *)pid dict:(NSDictionary*)biDictionary rid:(NSString*)rid;
+ (void)trackAdImp:(NSString *)pid adType:(NSInteger)adtype dict:(NSDictionary*)biDictionary rid:(NSString*)rid;
+ (void)trackPrivacyClick:(NSString *)pid adType:(NSInteger)adtype msgType:(NSInteger)msgType dict:(NSDictionary*)biDictionary rid:(NSString*)rid;
+ (void)trackInteractiveWebEvent:(NSString*)pid biDict:(NSDictionary*)biDictionary baseDict:(NSDictionary*)baseDictionary h5Dict:(NSDictionary*) h5Dict rid:(NSString*)rid;
+ (void)trackCacheTime:(NSString *)pid adType:(NSInteger)adtype duration:(NSInteger)duration success:(BOOL)success dict:(NSDictionary*)biDictionary rid:(NSString*)rid;
+ (void)trackNetwork:(NSString*)systemError msg:(NSString*)msg dict:(NSDictionary*)biDictionary;
@end

NS_ASSUME_NONNULL_END
