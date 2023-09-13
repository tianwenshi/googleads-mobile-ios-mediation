//
//  WKWebview+MATWebview.h
//  MaticooSDK
//
//  Created by root on 2023/4/17.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface WKWebView (MATWebView)
- (void)MATWebViewDisableScrolling;

- (void)MATWebViewDisableSelection;

- (void)MATWebViewScrollToTop;
@end

NS_ASSUME_NONNULL_END
