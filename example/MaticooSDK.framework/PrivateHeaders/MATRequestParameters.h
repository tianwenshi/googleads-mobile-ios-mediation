//
//  MATRequestParam.h
//  MaticooSDK
//
//  Created by root on 2023/4/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MATRequestParameters : NSObject
+(NSMutableDictionary *) buildBaseParameters;
+(NSMutableDictionary *) buildBIParameters;
+(NSMutableDictionary *) buildBiddingParameters;
+(NSString *) buildLogUrl;
+(NSString *) buildLogUrl:(NSString*) key;
+(NSString *) buildInitUrl:(NSString*) key;
+(NSString *) buildPrivacyUrl:(NSString*) key;
+(NSMutableDictionary *) buildBannerParameters:(NSMutableDictionary*) dict pid:(NSInteger)pid cwidth:(NSInteger)cwidth cheight:(NSInteger)cheight;
+(NSMutableDictionary *) buildFullScreenParameters:(NSMutableDictionary*) dict pid:(NSInteger)pid;
+(NSString *) buildRequestAdUrl;
+ (NSMutableDictionary *)buildNativeParameters:(NSMutableDictionary*)dic pid:(NSInteger)pid;
+ (NSMutableDictionary *)buildInteractParameters:(NSMutableDictionary*)dic pid:(NSInteger)pid;
+(void) setAppkey:(NSString*)key;
+(NSString*) getAppkey;
+(NSString *) buildBiddingUrl;
+(NSString *) buildBiddingAdUrl:(NSString*)requestId;
@end

NS_ASSUME_NONNULL_END
