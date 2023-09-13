//
//  NSTimer+MATExtraMethod.h
//  ApplinsSDK
//
//  Created by Mirinda on 2018/4/10.
//  Copyright © 2018年 Mirinda. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSTimer (MATExtraMethod)
/**
 创建NSTimer
 
 @param seconds 回调间隔
 @param repeats 是否重复调用
 @param block  timer的回调
 */
+ (NSTimer *)MATScheduledTimerWithTimeInterval:(NSTimeInterval)seconds repeats:(BOOL)repeats block:(void (^)(NSTimer *timer))block;

//暂停Timer
- (void)MATPauseTimer;

//重启Timer
- (void)MATResumeTimer;

//关闭Timer
- (void)MATStopTimer;

//指定时间重启Timer
- (void)MATResumeTimerAfterTimeInterval:(NSTimeInterval)interval;
@end
