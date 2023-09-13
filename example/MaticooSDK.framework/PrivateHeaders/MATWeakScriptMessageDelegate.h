//
//  MATWeakScriptMessageDelegate.h
//  MaticooSDK
//
//  Created by root on 2023/4/17.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface MATWeakScriptMessageDelegate : NSObject <WKScriptMessageHandler>

@property (nonatomic, assign) id<WKScriptMessageHandler> scriptDelegate;

- (instancetype)initWithDelegate:(id<WKScriptMessageHandler>)scriptDelegate;

@end

NS_ASSUME_NONNULL_END
