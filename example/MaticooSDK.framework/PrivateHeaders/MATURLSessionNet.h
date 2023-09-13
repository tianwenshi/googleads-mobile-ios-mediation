//
//  URLSessionNet.h
//  ApplinsSDK
//
//  Created by Mirinda on 16/5/30.
//  Copyright © 2016年 Mirinda. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MATURLSessionNet : NSObject <NSURLSessionDelegate>

+(instancetype)session;

/**
 封装NSURLSessionDataTask get方法

 @param url 请求链接
 @param isJson 是否需要Json解析
 @param complete 回调
 @return session
 */
- (NSURLSessionDataTask*)GET:(NSURL *)url isRetJson:(BOOL)isJson completeHandler:(void(^)(id responseObj, NSError *error))complete;

/**
 封装NSURLSessionDataTask post方法

 @param url 请求链接
 @param complete 回调
 @return session
 */
- (NSURLSessionDataTask*)POST:(NSMutableURLRequest *)url completeHandler:(void(^)(id responseObj, NSError *error))complete;

@end
                  
