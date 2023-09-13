//
//  MaticooError.h
//  MaticooSDK
//
//  Created by root on 2023/4/10.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger
{
    MATError_10000 = 0,//从服务器获取配置失败
    MATError_10002,    //配置信息数据有误
    MATError_10003,    //广告位为空
    MATError_10004,    //广告位关闭
    MATError_10005,    //请求的广告与拉配置信息的slot不是同一app的
    MATError_20000,    //网络请求错误
    MATError_20001,    //无网络
    MATError_20002,    //获取网络类型失败
    MATError_20003,    //webView加载网页超时
    MATError_30001,    //广告数据错误
    MATError_40001,    //广告素材下载失败
    MATError_40004,    //广告素材未下载完成
    MATError_40005,    //广告素材本地检索失败
    MATError_40007,    //所有类型(FB,CT,Admob)广告数据都获取失败
    MATError_50000,    //未调用SDK初始化接口
    MATError_50001,    //未调用广告预加载接口
    MATError_50005,    //插屏广告同一时间仅允许存在一个
    MATError_50006,    //banner容器尺寸不合法（小于banner尺寸）
    MATError_50007,    //等待广告加载完成
    MATError_60002,    //本地变量错误
    MATError_70000,    //FB广告错误
    MATError_70001,    //ADMob广告错误
    MATError_80000     //激励视频缓存错误
    
} MaticooError;


NS_ASSUME_NONNULL_END
