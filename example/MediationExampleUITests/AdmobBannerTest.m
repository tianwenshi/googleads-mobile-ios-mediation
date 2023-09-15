//
//  AdmobBannerTest.m
//  MediationExampleUITests
//
//  Created by Mirinda on 2023/9/13.
//  Copyright © 2023 Google, Inc. All rights reserved.
//

#import <XCTest/XCTest.h>

@interface AdmobBannerTest : XCTestCase
@property (nonatomic, strong) XCUIApplication *app;
@end

@implementation AdmobBannerTest

- (void)setUp {
    // Put setup code here. This method is called before the invocation of each test method in the class.
    [super setUp];
    self.continueAfterFailure = NO;
    self.app = [[XCUIApplication alloc] init];
    [self.app launch];
    // In UI tests it is usually best to stop immediately when a failure occurs.
    
    // In UI tests it’s important to set the initial state - such as interface orientation - required for your tests before they run. The setUp method is a good place to do this.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
    [self.app terminate];
    self.app = nil;
}


- (void)testLoadBanner {
    XCUIElement *Label = self.app.staticTexts[@"Objective-C Custom Event"];
    XCTAssertTrue(Label.exists, @"Objective-C Custom Event not found!");
    [Label tap];
    sleep(6);
    XCUIElement *adWebview = self.app.webViews[@"ad_webview"];
    XCTAssertTrue(adWebview.exists, @"WKWebView does not exist");
    XCTAssertTrue(adWebview.isHittable, @"WKWebView is not hittable");
}

- (void)testLoadBannerClosed {
    XCUIElement *Label = self.app.staticTexts[@"Objective-C Custom Event"];
    XCTAssertTrue(Label.exists, @"Objective-C Custom Event not found!");
    [Label tap];
    sleep(6);
    XCUIElement *adWebview = self.app.webViews[@"ad_webview"];
    XCTAssertTrue(adWebview.exists, @"WKWebView does not exist");
    XCTAssertTrue(adWebview.isHittable, @"WKWebView is not hittable");
    
    XCUIElement *closebtn = self.app.buttons[@"close_button"];
    XCTAssertTrue(closebtn.exists, @"close btn not found!");
    !closebtn.exists ?: [closebtn tap];
    sleep(2);
    
    XCUIElement *closeRbtn = self.app.buttons[@"Not interested"];
    XCTAssertTrue(closeRbtn.exists, @"Not interested btn not found!");
    !closeRbtn.exists ?: [closeRbtn tap];
    sleep(3);
    
    
}

- (void)testLoadBannerClick {
    XCUIElement *Label = self.app.staticTexts[@"Objective-C Custom Event"];
    XCTAssertTrue(Label.exists, @"Objective-C Custom Event not found!");
    [Label tap];
    for(int i = 0; i<15; i++) {
        XCUIElement *adWebview = self.app.webViews[@"ad_webview"];
        if(adWebview.exists)
            break;

        sleep(1);
    }
    XCUIElement *adWebview = self.app.webViews[@"ad_webview"];
    XCTAssertTrue(adWebview.exists, @"WKWebView does not exist");
    XCTAssertTrue(adWebview.isHittable, @"WKWebView is not hittable");
    [adWebview tap];
    sleep(5);
    XCUIApplication *safariApp = [[XCUIApplication alloc] initWithBundleIdentifier:@"com.apple.mobilesafari"];
    NSPredicate *existsPredicate = [NSPredicate predicateWithFormat:@"self.state == %d", XCUIApplicationStateRunningForeground];
    XCTestExpectation *appSwitched = [self expectationForPredicate:existsPredicate evaluatedWithObject:safariApp handler:nil];
    [self waitForExpectations:@[appSwitched] timeout:5];
    XCTAssertTrue(safariApp.state == XCUIApplicationStateRunningForeground, @"切换到 Safari 应用程序");
    sleep(2);
}

//- (void)testExample {
//    // UI tests must launch the application that they test.
//    XCUIApplication *app = [[XCUIApplication alloc] init];
//    [app launch];
//
//    // Use XCTAssert and related functions to verify your tests produce the correct results.
//}
//
//- (void)testLaunchPerformance {
//    if (@available(macOS 10.15, iOS 13.0, tvOS 13.0, watchOS 7.0, *)) {
//        // This measures how long it takes to launch your application.
//        [self measureWithMetrics:@[[[XCTApplicationLaunchMetric alloc] init]] block:^{
//            [[[XCUIApplication alloc] init] launch];
//        }];
//    }
//}

@end
