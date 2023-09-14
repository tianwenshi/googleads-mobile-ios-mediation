//
//  AdmobMixTest.m
//  MediationExampleUITests
//
//  Created by Mirinda on 2023/9/14.
//  Copyright © 2023 Google, Inc. All rights reserved.
//

#import <XCTest/XCTest.h>

@interface AdmobMixTest : XCTestCase
@property (nonatomic, strong) XCUIApplication *app;
@end

@implementation AdmobMixTest

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

- (void)testMixTest {
    XCUIElement *Label = self.app.staticTexts[@"Objective-C Custom Event"];
    XCTAssertTrue(Label.exists, @"Objective-C Custom Event not found!");
    [Label tap];
    sleep(6);
    XCUIElement *adWebview = self.app.webViews[@"ad_webview"];
    XCTAssertTrue(adWebview.exists, @"WKWebView does not exist");
    XCTAssertTrue(adWebview.isHittable, @"WKWebView is not hittable");
    
    sleep(5);
    XCUIElement *show = self.app.buttons[@"Show Interstitial Ad"];
    !show.exists?:[show tap];
    sleep(10);
    XCUIElement *inWebview = self.app.webViews[@"ad_webview"];
    XCTAssertTrue(inWebview.exists, @"WKWebView does not exist");
    XCTAssertTrue(inWebview.isHittable, @"WKWebView is not hittable");
    
    XCUIElement *close = self.app.buttons[@"close_x"];
    if(close.exists) {
       [close tap];
    }
    sleep(5);
    
    XCUIElement *reShow = self.app.buttons[@"Show Rewarded Ad"];
    !reShow.exists?:[reShow tap];
    sleep(10);
    XCUIElement *reWebview = self.app.webViews[@"ad_webview"];
    XCTAssertTrue(reWebview.exists, @"WKWebView does not exist");
    XCTAssertTrue(reWebview.isHittable, @"WKWebView is not hittable");
    sleep(35);
    XCUIElement *reClose = self.app.buttons[@"ad_closeBtn"];
    if(reClose.exists) {
       [reClose tap];
    }
    
    sleep(5);
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
