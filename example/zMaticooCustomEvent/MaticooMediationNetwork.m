//
//  NetworkManager.m
//
//  Created by Mirinda on 16/5/30.
//  Copyright © 2016年 Mirinda. All rights reserved.
//

#import "MaticooMediationNetwork.h"
#import "MaticooMediationURLSession.h"
//#import "MATReachability.h"
//#import "NSData+ALSAES.h"

@interface MaticooMediationNetwork ()
@end

@implementation MaticooMediationNetwork
//初始化
+ (instancetype)manager
{
    return [[[self class]alloc]init];
}

+ (id)POST:(NSString *)path parameters:(NSDictionary *)params completeHandle:(void (^)(id responseObj, NSError* error))complete
{
    //NSLog(params.description);
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:path]];
    
    [request setValue:@"application/json" forHTTPHeaderField:@"Content-Type"];
    
    NSError* parseError = nil;
    request.HTTPMethod = @"POST";
    
    NSData* postData = nil;
    if (!([(params) isKindOfClass:[NSDictionary class]] && (params).count > 0)) {
        complete(nil,nil);
        return nil;
    }
    
    @try
    {
        postData = [NSJSONSerialization dataWithJSONObject:params options:kNilOptions error:&parseError];
    }
    @catch (NSException *exception){
        NSLog(@"Error(try-catch):MATNetWorkManager->POST,exception name is %@,reason is %@",exception.name,exception.reason);
        return nil;
    }
    
    if ([postData isKindOfClass:[NSData class]] && postData.length > 0)
    {
        request.HTTPBody = postData;
    }else{
        request.HTTPBody = nil;
    }
        
    MaticooMediationURLSession* session = [MaticooMediationURLSession session];
    
    return [session POST:request completeHandler:^(id responseObj, NSError *error) {
        if (error)
        {
            NSLog(@"%@", error.description);
            complete(responseObj,error);
        }
        else
        {
            complete(responseObj,nil);
        }
    }];
}


#pragma mark -session delegate
-(void)URLSession:(NSURLSession *)session didReceiveChallenge:(NSURLAuthenticationChallenge *)challenge completionHandler:(void (^)(NSURLSessionAuthChallengeDisposition, NSURLCredential * _Nullable))completionHandler {
    
    NSURLSessionAuthChallengeDisposition disposition = NSURLSessionAuthChallengePerformDefaultHandling;
    __block NSURLCredential *credential = nil;
    
    if ([challenge.protectionSpace.authenticationMethod isEqualToString:NSURLAuthenticationMethodServerTrust]) {
        credential = [NSURLCredential credentialForTrust:challenge.protectionSpace.serverTrust];
        if (credential) {
            disposition = NSURLSessionAuthChallengeUseCredential;
        } else {
            disposition = NSURLSessionAuthChallengePerformDefaultHandling;
        }
    } else {
        disposition = NSURLSessionAuthChallengePerformDefaultHandling;
    }
    
    if (completionHandler) {
        completionHandler(disposition, credential);
    }
}

- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task willPerformHTTPRedirection:(NSHTTPURLResponse *)response newRequest:(NSURLRequest *)request completionHandler:(void (^)(NSURLRequest * __nullable))completionHandler
{
    if (response.statusCode == 301 || response.statusCode == 302) {
        //NSLog(@"requeset [ %ld ] url [ %@ ]",urlResponse.statusCode,dic[@"Location"]);
        completionHandler(request);
    }else{
        completionHandler(nil);
    }
}

@end
