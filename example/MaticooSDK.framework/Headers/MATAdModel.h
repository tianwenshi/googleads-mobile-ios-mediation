//
//  MATAdModel.h
//  MaticooSDK
//
//  Created by root on 2023/4/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class MATBidResponse, MATNativeResponse, MATInteractiveResponse;

@interface MATAdModel : NSObject
@property (nonatomic,assign) NSInteger code;
@property (nonatomic,strong) NSString *msg;
@property (nonatomic,strong) MATBidResponse *bidresp;
@property (nonatomic,strong) MATInteractiveResponse *interactiveresp;
@end

@interface MATBidResponse : NSObject
@property (nonatomic,assign) NSInteger pid;
@property (nonatomic,assign) NSInteger nbr;                     //NoBidReason Code
@property (nonatomic,strong) NSString *err;                     //NoBidReason Msg
@property (nonatomic,strong) NSString *nurl;                    //WinNotice URL
@property (nonatomic,strong) NSString *lurl;                    //LossNotice URL
@property (nonatomic,strong) NSString *adurl;
@property (nonatomic,strong) NSString *clkurl;
@property (nonatomic,strong) NSString *adType;                  //"for interstitial Ad:interstitial-banner/interstitial-video"
@property (nonatomic,assign) NSInteger expire;                  //Expire time, in minutes
@property (nonatomic,strong) NSArray *mediaFiles;               //media file for reward ad
@property (nonatomic,strong) NSArray *resources;                //image/js file for reward ad
@property (nonatomic,strong) NSString *adRequestId;
@property (nonatomic,assign) CGFloat cat;
@property (nonatomic,strong) MATNativeResponse *nativeResponse; //native ad respnose data
@end

@interface MATNativeResponse : NSObject
@property (nonatomic,assign) NSString *icon_url;
@property (nonatomic,strong) NSString *title;
@property (nonatomic,strong) NSString *img_ad_url;              //✔︎ for image native ad
@property (nonatomic,strong) NSString *video_ad_url;            //✔︎ for video native ad
@property (nonatomic,strong) NSString *impurl;
@property (nonatomic,strong) NSArray *imp_trackers;
@property (nonatomic,strong) NSArray *click_trackers;
@property (nonatomic,strong) NSString *click_through_url;
@property (nonatomic,strong) NSString *sponsored_data;
@property (nonatomic,strong) NSString *describe_data;
@property (nonatomic,strong) NSString *cta_text;
@end

@interface MATInteractiveResponse : NSObject
@property (nonatomic,assign) NSInteger pid;
@property (nonatomic,strong) NSString *country;
@property (nonatomic,strong) NSString *request_id;
@property (nonatomic,strong) NSString *icon_url;
@property (nonatomic,strong) NSString *h5_url;
@property (nonatomic,strong) NSString *interactive_adv_id;
@property (nonatomic,assign) NSInteger recall_interval;         //recall_interval
@property (nonatomic,assign) NSInteger bi_app_id;
@end
NS_ASSUME_NONNULL_END
