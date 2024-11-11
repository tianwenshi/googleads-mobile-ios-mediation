//
//  MATTools.h
//  MaticooSDK
//
//  Created by root on 2023/4/25.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class MATVideoResponse;
@interface MATTools : NSObject
+ (UIWindow*)keyWindow;
+ (UIViewController*)rootViewController:(UIViewController *)VC;
+ (BOOL)isDisplayedInScreenWith:(UIView *)flagView;
+ (NSString*)imageTypeForImageData:(NSData *)data;
+ (NSString *)getAPPIDFromLink:(NSString *)link;
+ (NSString*)timeNow;
+ (BOOL) isToday:(long) time;
+ (long long)getCurrentTime;
+ (CGFloat)distanceBetweenPoint:(CGPoint)point1 andPoint:(CGPoint)point2;

+ (BOOL)canPlay:(NSString*)url;
+ (void)deleteVideoFileWithCache:(NSString *)path andDayOut:(NSInteger)days;
+ (void)trackHandle:(NSArray *)trackArr;
+ (void)trackUrl:(NSString *)urlStr;
+ (void)trackVast:(NSArray *)trackArr errorCode:(NSString *)code;
+ (NSString *)getVideoPathFromURL:(NSString *)url isLocal:(BOOL *)isLocal videoType:(NSString*)videoType;
+ (NSString *)getVideoType:(NSString *)typeStr;
+ (NSString *)creatSendToJSVastVideoInitStr:(MATVideoResponse *)videoModel url:(NSArray *)urlArray;

+ (BOOL)isViewCovered:(UIView *)view;
+ (NSInteger)isViewCovered:(UIView *)view intersectionAreaRatio:(CGFloat)intersectionRatio;
+ (double)rateViewIntersectionWindow:(UIView *)view;
/**
 检测是否设置了代理

 @return bool
 */
+ (BOOL)fetchHttpProxy;

+ (BOOL) isCharging;

+ (BOOL) checkRequestFailTimes;
+ (void) increaseRequestFailTimes;
+ (void) resetRequestFailTimes;

@end

NS_ASSUME_NONNULL_END
