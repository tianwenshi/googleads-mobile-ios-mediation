//
//  MATModalViewController.h
//  ApplinsSDK
//
//  Created by Applins on 2018/5/14.
//  Copyright © 2018年 Mirinda. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void (^vcWillLayout)(CGRect rt);
typedef void (^VCDidAppear)(void);
@class MATModalViewController;

@protocol MATModalViewControllerDelegate <NSObject>
- (void)MATModalViewControllerDidRotate:(MATModalViewController*)modalViewController;
- (void)MATModalViewWillClose:(MATModalViewController*)modalViewController;
- (void)MATModalViewDidClose:(MATModalViewController*)modalViewController;
@end

@interface MATModalViewController : UIViewController

@property (nonatomic, weak) id<MATModalViewControllerDelegate> delegate;
@property (nonatomic, assign) BOOL allowRotation;
@property (nonatomic, assign) BOOL isPresented;
@property (nonatomic, copy) VCDidAppear vcDidAppearBolck;
@property (nonatomic, copy) VCDidAppear vcWillAppearBolck;
@property (nonatomic, copy) vcWillLayout vcWillLayout;
@property (nonatomic, assign) UIInterfaceOrientation forcedOrientation;

- (void)forceRotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation;

@end
