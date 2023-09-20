//
//  MATTrackManager.m
//  MaticooSDK
//
//  Created by root on 2023/5/4.
//

#import "MaticooMediationTrackManager.h"
#import <objc/runtime.h>
#import <objc/message.h>
#import "MaticooMediationNetwork.h"
#import <AppTrackingTransparency/AppTrackingTransparency.h>
#import <AdSupport/ASIdentifierManager.h>

#define TIMESTAMP_MS [[NSDate date] timeIntervalSince1970] * 1000
static NSString *logURL = @"";
static NSString *idfa = @"";

@implementation MaticooMediationTrackManager

+(NSString *) buildLogUrl{
    Class requestClass = NSClassFromString(@"MATRequestParameters");
    if(requestClass && [logURL isEqualToString:@""]){
        logURL = ((NSString* (*)(id, SEL))objc_msgSend)((id)requestClass, @selector(buildLogUrl));
    }
    return logURL;
}

+(NSString*) getIDFA{
    if (@available(iOS 14, *)) {
        // iOS14及以上版本需要先请求权限
        [ATTrackingManager requestTrackingAuthorizationWithCompletionHandler:^(ATTrackingManagerAuthorizationStatus status) {
            // 获取到权限后，依然使用老方法获取idfa
            if (status == ATTrackingManagerAuthorizationStatusAuthorized) {
                idfa = [[ASIdentifierManager sharedManager].advertisingIdentifier UUIDString];
            }
        }];
    } else {
        // iOS14以下版本依然使用老方法
        // 判断在设置-隐私里用户是否打开了广告跟踪
        if ([[ASIdentifierManager sharedManager] isAdvertisingTrackingEnabled]) {
            idfa = [[ASIdentifierManager sharedManager].advertisingIdentifier UUIDString];
        }
    }
    return idfa;
}

+(NSString*) getBundle{
    NSString *bundle = NSBundle.mainBundle.bundleIdentifier;
    if (bundle != nil)
        return bundle;
    return @"";
}

+(NSString*) getShortBundleVersion{
    NSDictionary *infoDict = [[NSBundle mainBundle] infoDictionary];
    NSString *shortVersion = [infoDict objectForKey:@"CFBundleShortVersionString"];
    return shortVersion;
}

+ (void)trackMediationInitSuccess{
    NSMutableDictionary *dict = [NSMutableDictionary dictionary];
    NSMutableArray *jsonArray = [NSMutableArray array];
    [jsonArray addObject:@{ @"eid": [NSNumber numberWithInt:203],@"ts": [NSNumber numberWithLongLong:TIMESTAMP_MS],@"mediation":@"max",@"did":[self getIDFA],@"bundle":[self getBundle],@"appv":[self getShortBundleVersion]}];
    [dict setValue:jsonArray forKey:@"data"];
    NSString *url = [self buildLogUrl];
    [MaticooMediationNetwork POST:url parameters:dict completeHandle:^(id responseObj, NSError *error) {}];
}

+ (void)trackMediationInitFailed:(NSError*)error{
    NSMutableDictionary *dict = [NSMutableDictionary dictionary];
    NSMutableArray *jsonArray = [NSMutableArray array];
    [jsonArray addObject:@{ @"eid": [NSNumber numberWithInt:204],@"ts": [NSNumber numberWithLongLong:TIMESTAMP_MS], @"mediation":@"max", @"msg": error.description,@"did":[self getIDFA],@"bundle":[self getBundle],@"appv":[self getShortBundleVersion]}];
    [dict setValue:jsonArray forKey:@"data"];
    NSString *url = [self buildLogUrl];
    [MaticooMediationNetwork POST:url parameters:dict completeHandle:^(id responseObj, NSError *error) {}];
}

+ (void)trackMediationAdRequest:(NSString*)pid adType:(NSInteger)adtype isAutoRefresh:(BOOL)isAuto{
    NSMutableDictionary *dict = [NSMutableDictionary dictionary];
    NSMutableArray *jsonArray = [NSMutableArray array];
    [jsonArray addObject:@{ @"eid": [NSNumber numberWithInt:201],@"ts": [NSNumber numberWithLongLong:TIMESTAMP_MS],@"ad_type": [NSNumber numberWithInteger:adtype], @"mediation":@"max", @"pid":pid?pid:@"",@"did":[self getIDFA],@"bundle":[self getBundle],@"appv":[self getShortBundleVersion]}];
    [dict setValue:jsonArray forKey:@"data"];
    NSString *url = [self buildLogUrl];
    [MaticooMediationNetwork POST:url parameters:dict completeHandle:^(id responseObj, NSError *error) {}];
}

+ (void)trackMediationAdRequestFilled:(NSString*)pid adType:(NSInteger)adtype{
    NSMutableDictionary *dict = [NSMutableDictionary dictionary];
    NSMutableArray *jsonArray = [NSMutableArray array];
    [jsonArray addObject:@{ @"eid": [NSNumber numberWithInt:205],@"ts": [NSNumber numberWithLongLong:TIMESTAMP_MS],@"ad_type": [NSNumber numberWithInteger:adtype], @"mediation":@"max", @"pid":pid?pid:@"",@"did":[self getIDFA],@"bundle":[self getBundle],@"appv":[self getShortBundleVersion]}];
    [dict setValue:jsonArray forKey:@"data"];
    NSString *url = [self buildLogUrl];
    [MaticooMediationNetwork POST:url parameters:dict completeHandle:^(id responseObj, NSError *error) {}];
}

+ (void)trackMediationAdRequestFailed:(NSString*)pid adType:(NSInteger)adtype{
    NSMutableDictionary *dict = [NSMutableDictionary dictionary];
    NSMutableArray *jsonArray = [NSMutableArray array];
    [jsonArray addObject:@{ @"eid": [NSNumber numberWithInt:206],@"ts": [NSNumber numberWithLongLong:TIMESTAMP_MS],@"ad_type": [NSNumber numberWithInteger:adtype], @"mediation":@"max", @"pid":pid?pid:@"",@"did":[self getIDFA],@"bundle":[self getBundle],@"appv":[self getShortBundleVersion]}];
    [dict setValue:jsonArray forKey:@"data"];
    NSString *url = [self buildLogUrl];
    [MaticooMediationNetwork POST:url parameters:dict completeHandle:^(id responseObj, NSError *error) {}];
}

+ (void)trackMediationAdShow:(NSString*)pid adType:(NSInteger)adtype{
    NSMutableDictionary *dict = [NSMutableDictionary dictionary];
    NSMutableArray *jsonArray = [NSMutableArray array];
    [jsonArray addObject:@{ @"eid": [NSNumber numberWithInt:202],@"ts": [NSNumber numberWithLongLong:TIMESTAMP_MS],@"ad_type": [NSNumber numberWithInteger:adtype], @"mediation":@"max", @"pid":pid?pid:@"",@"did":[self getIDFA],@"bundle":[self getBundle],@"appv":[self getShortBundleVersion]}];
    [dict setValue:jsonArray forKey:@"data"];
    NSString *url = [self buildLogUrl];
    [MaticooMediationNetwork POST:url parameters:dict completeHandle:^(id responseObj, NSError *error) {}];
}

+ (void)trackMediationAdImp:(NSString*)pid adType:(NSInteger)adtype{
    NSMutableDictionary *dict = [NSMutableDictionary dictionary];
    NSMutableArray *jsonArray = [NSMutableArray array];
    [jsonArray addObject:@{ @"eid": [NSNumber numberWithInt:207],@"ts": [NSNumber numberWithLongLong:TIMESTAMP_MS],@"ad_type": [NSNumber numberWithInteger:adtype], @"mediation":@"max", @"pid":pid?pid:@"",@"did":[self getIDFA],@"bundle":[self getBundle],@"appv":[self getShortBundleVersion]}];
    [dict setValue:jsonArray forKey:@"data"];
    NSString *url = [self buildLogUrl];
    [MaticooMediationNetwork POST:url parameters:dict completeHandle:^(id responseObj, NSError *error) {}];
}

+ (void)trackMediationAdImpFailed:(NSString*)pid adType:(NSInteger)adtype{
    NSMutableDictionary *dict = [NSMutableDictionary dictionary];
    NSMutableArray *jsonArray = [NSMutableArray array];
    [jsonArray addObject:@{ @"eid": [NSNumber numberWithInt:208],@"ts": [NSNumber numberWithLongLong:TIMESTAMP_MS],@"ad_type": [NSNumber numberWithInteger:adtype], @"mediation":@"max", @"pid":pid?pid:@"",@"did":[self getIDFA],@"bundle":[self getBundle],@"appv":[self getShortBundleVersion]}];
    [dict setValue:jsonArray forKey:@"data"];
    NSString *url = [self buildLogUrl];
    [MaticooMediationNetwork POST:url parameters:dict completeHandle:^(id responseObj, NSError *error) {}];
}

+ (void)trackMediationAdClick:(NSString*)pid adType:(NSInteger)adtype{
    NSMutableDictionary *dict = [NSMutableDictionary dictionary];
    NSMutableArray *jsonArray = [NSMutableArray array];
    [jsonArray addObject:@{ @"eid": [NSNumber numberWithInt:209],@"ts": [NSNumber numberWithLongLong:TIMESTAMP_MS],@"ad_type": [NSNumber numberWithInteger:adtype], @"mediation":@"max", @"pid":pid?pid:@"",@"did":[self getIDFA],@"bundle":[self getBundle],@"appv":[self getShortBundleVersion]}];
    [dict setValue:jsonArray forKey:@"data"];
    NSString *url = [self buildLogUrl];
    [MaticooMediationNetwork POST:url parameters:dict completeHandle:^(id responseObj, NSError *error) {}];
}

@end
