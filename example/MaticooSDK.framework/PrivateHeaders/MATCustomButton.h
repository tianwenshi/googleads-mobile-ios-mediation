//
//  ADCustomButton.h
//  ApplinsSDK
//
//  Created by Mirinda on 2018/4/10.
//  Copyright © 2018年 Mirinda. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface MATCustomButton : UIButton

@property (nonatomic, strong) UIColor * _Nullable progressTrackColor;           //进度条轨道颜色，默认灰色
@property (nonatomic, strong) UIColor * _Nullable progressColor;                //进度条颜色,默认黑色
@property (nonatomic, assign) CGFloat progressWidth;                            //进度条宽度,默认2.0f
@property (nonatomic, assign) BOOL removeProgressTrackAfterDraw;                //绘制完成后删除进度条轨道,默认不删除
@property (nonatomic, assign) CGFloat p;

//Spalsh Skip Button
+ (instancetype _Nullable )initSkipButton;
- (void)showSkipButtonFromTop:(NSInteger)top FromRight:(NSInteger)right skip:(BOOL)skip adShow:(NSInteger)showTime countDown:(NSInteger)count  superView:(UIView *_Nonnull)view buttonClicked:(void (^_Nonnull)(BOOL))clicked;
/**
 开始进度条动画
 
 @param duration 进度条时间
 @param timeBlock 以0.1s的粒度回调返回当前已经走过的时间
 @param completion 是否结束 (YES,时间到自动结束； NO,stop方法触发结束)
 */
- (void)progressStartWithDuration:(NSInteger)duration currentTime:(void (^_Nullable)(CGFloat time))timeBlock completion:(void (^ __nullable)(BOOL finished))completion;

//暂停绘制progress
- (void)pause;

//继续绘制progress
- (void)resume;

//停止绘制progress
- (void)stop;

@end
