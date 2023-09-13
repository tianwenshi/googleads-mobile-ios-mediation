//
//  URLSessionNet.m
//  
//
//  Created by Mirinda on 16/5/30.
//  Copyright © 2016年 Mirinda. All rights reserved.
//

#import "MaticooMediationURLSession.h"
#import <UIKit/UIKit.h>


@interface MaticooMediationURLSession ()
@property (nonatomic, strong) NSURLSession *session;
@end

@implementation MaticooMediationURLSession

+ (instancetype)session
{
    return [[[self class]alloc]init];
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

/**
     302跳转
     completionHandler 返回request代表允许302，返回nil代表终止
 */
- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task willPerformHTTPRedirection:(NSHTTPURLResponse *)response newRequest:(NSURLRequest *)request completionHandler:(void (^)(NSURLRequest * __nullable))completionHandler
{
    if (response.statusCode == 301 || response.statusCode == 302)
    {
        //NSLog(@"requeset [ %ld ] url [ %@ ]",urlResponse.statusCode,dic[@"Location"]);
        completionHandler(request);
    }else{
        completionHandler(nil);
    }
}


#pragma mark - NSURLSessionDataTask POST
- (NSURLSessionDataTask*)POST:(NSMutableURLRequest *)request completeHandler:(void(^)(id responseObj, NSError *error))complete
{
    //[[UIApplication sharedApplication] setNetworkActivityIndicatorVisible:YES];
    NSURLSessionDataTask* task = [[NSURLSession sharedSession] dataTaskWithRequest:request completionHandler:^(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error) {
        //[[UIApplication sharedApplication] setNetworkActivityIndicatorVisible:NO];
        if (error)
        {
            complete(nil, error);
        }else
        {
            NSError *error1 = nil;
            NSHTTPURLResponse* httpResponse = (NSHTTPURLResponse*)response;
            if (200 == httpResponse.statusCode)
            {
                NSString *httpTypeStr = [httpResponse.allHeaderFields valueForKey:@"Content-Type"];
                NSRange range = [httpTypeStr rangeOfString:@"application/xml"];
                id responseObj;
                if (range.location!=NSNotFound)
                {
                    responseObj = data;
                }else
                {
                    responseObj=[NSJSONSerialization JSONObjectWithData:data options:NSJSONReadingMutableContainers|NSJSONReadingMutableLeaves|NSJSONReadingAllowFragments error:&error1];
                }
                
                if (error1)
                {
                    complete(nil, error1);
                }else
                {
                    complete(responseObj, nil);
                }
            }
            else
            {
                id responseObj = nil;
                responseObj=[NSJSONSerialization JSONObjectWithData:data options:NSJSONReadingMutableContainers|NSJSONReadingMutableLeaves|NSJSONReadingAllowFragments error:&error1];
                if (responseObj != nil){
                    NSError *err = [NSError errorWithDomain:@"Maticoo SDK Error: " code:httpResponse.statusCode userInfo:[NSDictionary dictionaryWithObject:responseObj forKey:@"reason"]];
                    complete(nil,err);
                }else{
                    NSError *err = [NSError errorWithDomain:@"Maticoo SDK Error: " code:httpResponse.statusCode userInfo:[NSDictionary dictionaryWithObject:@"unknow server error" forKey:@"reason"]];
                    complete(nil,err);
                }
            }
        }
    }];
    [task resume];
    return task;
}

@end
