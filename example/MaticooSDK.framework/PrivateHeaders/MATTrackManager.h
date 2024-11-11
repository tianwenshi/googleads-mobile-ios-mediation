//
//  MATTrackManager.h
//  MaticooSDK
//
//  Created by root on 2023/5/4.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MATTrackManager : NSObject
+ (void)setTrackGrade:(NSUInteger)grade;
+ (void)trackSDKInitStart;
+ (void)trackSDKInitSuccess;
+ (void)trackSDKInitFailed:(NSInteger) eventCode msg:(NSString*)msg appKey:(NSString*)appKey; //"1、初始化前置检查异常（AppKey、权限）2、初始化期间发生的crash3、配置文件请求成功之后，响应码错误。4、配置文件请求结果为空。5、配置文件请求的配置项为空。6、配置信息，网络请求失败"
+ (void)trackAdRequest:(NSString*)pid adType:(NSInteger)adtype rid:(NSString*)rid isAutoRefresh:(NSInteger) isAuto otherInfo:(NSDictionary *)info;
+ (void)trackAdRequestInTraffic:(NSString*)pid adType:(NSInteger)adtype otherInfo:(NSDictionary *)info; //广告走网络请求
+ (void)trackAdHitCache:(NSString*)pid adType:(NSInteger)adtype isAutoRefresh:(NSInteger)isAuto rid:(NSString*)rid; //广告走网络请求
+ (void)trackAdLoadSuccess:(NSString*)pid adType:(NSInteger)adtype duration:(NSTimeInterval) duration rid:(NSString*)rid otherInfo:(NSDictionary *)info;
+ (void)trackAdRequestSuccess:(NSString*)pid adType:(NSInteger)adtype duration:(NSTimeInterval) duration rid:(NSString*)rid otherInfo:(NSDictionary *)info;
+ (void)trackAdRequestNetworkFailed:(NSString*)pid adType:(NSInteger)adtype msg:(NSString*) msg otherInfo:(NSDictionary *)info;
+ (void)trackAdRequestFailed:(NSString*)pid adType:(NSInteger)adtype msg:(NSString*) msg otherInfo:(NSDictionary *)info;
+ (void)trackAdShowFailed:(NSString*)pid adType:(NSInteger)adtype msg:(NSString*) msg rid:(NSString*)rid otherInfo:(NSDictionary *)info;
+ (void)trackVideoPlayed:(NSString*)pid adType:(NSInteger)adtype rid:(NSString*)rid otherInfo:(NSDictionary *)info;
+ (void)trackVideoCompleted:(NSString*)pid adType:(NSInteger)adtype rid:(NSString*)rid otherInfo:(NSDictionary *)info;
+ (void)trackClick:(NSString*)pid adType:(NSInteger)adtype position:(NSString*)position rid:(NSString*)rid otherInfo:(NSDictionary *)info;
+ (void)trackShow:(NSString*)pid adType:(NSInteger)adtype rid:(NSString*)rid otherInfo:(NSDictionary *)info;
+ (void)trackClose:(NSString*)pid adType:(NSInteger)adtype button:(NSString*)btnName rid:(NSString*)rid otherInfo:(NSDictionary *)info;
+ (void)trackVideoMuted:(NSString*)pid adType:(NSInteger)adtype isMute:(BOOL)isMute rid:(NSString*)rid;
+ (void)trackLoadWhileShowing:(NSString*)pid adType:(NSInteger)adtype;
+ (void)trackInteractiveIconShow:(NSString *)pid dict:(NSDictionary*)baseDictionary rid:(NSString*)rid otherInfo:(NSDictionary *)info;
+ (void)trackInteractiveIconClick:(NSString *)pid dict:(NSDictionary*)baseDictionary rid:(NSString*)rid otherInfo:(NSDictionary *)info;
+ (void)trackInteractiveIconShowBi:(NSString *)pid rid:(NSString*)rid otherInfo:(NSDictionary *)info;
+ (void)trackInteractiveIconClickBi:(NSString *)pid rid:(NSString*)rid otherInfo:(NSDictionary *)info;
+ (void)trackAdImp:(NSString *)pid adType:(NSInteger)adtype rid:(NSString*)rid otherInfo:(NSDictionary *)info;
+ (void)trackAdImpInterval:(NSString *)pid adType:(NSInteger)adtype rid:(NSString*)rid visible:(NSInteger)visible otherInfo:(NSDictionary *)info;
+ (void)trackAdLayout:(NSString *)pid adType:(NSInteger)adtype rid:(NSString*)rid otherInfo:(NSDictionary *)info;
+ (void)trackPrivacyClick:(NSString *)pid adType:(NSInteger)adtype msgType:(NSInteger)msgType rid:(NSString*)rid;
+ (void)trackInteractiveWebEvent:(NSString*)pid biDict:(NSDictionary*)biDictionary baseDict:(NSDictionary*)baseDictionary h5Dict:(NSDictionary*) h5Dict rid:(NSString*)rid otherInfo:(NSDictionary *)info;
+ (void)trackCacheTime:(NSString *)pid adType:(NSInteger)adtype duration:(NSInteger)duration success:(BOOL)success rid:(NSString*)rid;
+ (void)trackNetwork:(NSString*)systemError msg:(NSString*)msg;
+ (void)trackMediationInitSuccess;
+ (void)trackMediationInitFailed:(NSString*)msg;
+ (void)trackMediationAdRequest:(NSString*)pid adType:(NSInteger)adtype rid:(NSString*)rid isAutoRefresh:(NSInteger)isAuto;
+ (void)trackMediationAdRequestFilled:(NSString*)pid adType:(NSInteger)adtype;
+ (void)trackMediationAdRequestFailed:(NSString*)pid adType:(NSInteger)adtype msg:(NSString*)msg;
+ (void)trackMediationAdShow:(NSString*)pid adType:(NSInteger)adtype;
+ (void)trackMediationAdImp:(NSString*)pid adType:(NSInteger)adtype;
+ (void)trackMediationAdImpFailed:(NSString*)pid adType:(NSInteger)adtype msg:(NSString*)msg;
+ (void)trackMediationAdClick:(NSString*)pid adType:(NSInteger)adtype;
+ (void)trackImportentExceptionInfo:(NSString*)exceptionInfo pid:(NSString *)pid adType:(NSInteger)adtype;
+ (void)trackExceptionInfo:(NSString*)exceptionInfo pid:(NSString *)pid adType:(NSInteger)adtype;
+ (void)setServerInfo:(NSDictionary * _Nullable)serverDic pid:(NSString *)pid;
+ (void)trackInitUserSet:(NSDictionary *)extraInfo;
+ (void)trackMediationJSLog:(NSString*)customEventName pid:(NSString*)pid adType:(NSInteger)adtype dict:(NSDictionary*)params;
@end

NS_ASSUME_NONNULL_END
