//
//  MATAdModel.h
//  MaticooSDK
//
//  Created by root on 2023/4/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class MATBidResponse, MATNativeResponse, MATInteractiveResponse, MATSKANResponse, MATVideoResponse, MATVideoEventTrack, MATVideoIconsInfo,MATVideoCompanInfo,MATVideoCompanEventTrack;

@interface MATAdModel : NSObject
@property (nonatomic,assign) NSInteger code;
@property (nonatomic,strong) NSString *msg;
@property (nonatomic,strong) MATBidResponse *bidresp;
@property (nonatomic,strong) MATInteractiveResponse *interactiveresp;
@property (nonatomic,assign) NSInteger ort;
@end

@interface MATBidResponse : NSObject
@property (nonatomic,assign) NSInteger pid;
@property (nonatomic,assign) NSInteger nbr;                     //NoBidReason Code
@property (nonatomic,strong) NSString *err;                     //NoBidReason Msg
@property (nonatomic,strong) NSString *nurl;                    //WinNotice URL
@property (nonatomic,strong) NSString *lurl;                    //LossNotice URL
@property (nonatomic,strong) NSString *adurl;
@property (nonatomic,strong) NSString *clkurl;
@property (nonatomic,strong) NSString *crid;
@property (nonatomic,strong) NSString *finalUrl;
@property (nonatomic,strong) NSString *impurl;
@property (nonatomic,strong) NSString *adType;                  //"for interstitial Ad:interstitial-banner/interstitial-video"
@property (nonatomic,assign) NSInteger expire;                  //Expire time, in minutes
@property (nonatomic,strong) NSArray *mediaFiles;               //media file for reward ad
@property (nonatomic,strong) NSArray *resources;                //image/js file for reward ad
@property (nonatomic,strong) NSString *adRequestId;
@property (nonatomic,strong) NSString *gid;
@property (nonatomic,strong) NSString *dsp;
@property (nonatomic,assign) CGFloat cat;
@property (nonatomic,assign) NSInteger range;
@property (nonatomic,assign) NSInteger autoClick;
@property (nonatomic,assign) NSInteger multi;
@property (nonatomic,assign) CGFloat range_ratio;
@property (nonatomic,strong) MATNativeResponse *nativeResponse; //native ad respnose data
@property (nonatomic,assign) NSInteger mraid;
@property (nonatomic,strong) NSString *adm;
@property (nonatomic,strong) MATSKANResponse *skadn;
@property (nonatomic,strong) MATVideoResponse *video_response;
@property (nonatomic,assign) NSTimeInterval vc_interval;
@end

@interface MATNativeResponse : NSObject
@property (nonatomic,assign) NSString *icon_url;
@property (nonatomic,strong) NSString *title;
@property (nonatomic,strong) NSString *img_ad_url;              //✔︎ for image native ad
@property (nonatomic,strong) NSString *video_ad_url;            //✔︎ for video native ad
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

@interface MATSKANResponse : NSObject
@property (nonatomic,strong) NSString *ad_network_id;
@property (nonatomic,strong) NSString *version;
@property (nonatomic,strong) NSString *source_app_id;
@property (nonatomic,strong) NSString *target_app_id;
@property (nonatomic,strong) NSString *signature;
@property (nonatomic,strong) NSString *campaign_id;
@property (nonatomic,strong) NSString *nonce;
@property (nonatomic,strong) NSString *timestamp;
@property (nonatomic,strong) NSString *source_identifier;
@end

@interface MATVideoResponse : NSObject
@property (nonatomic,strong) NSArray *imp_trackers;
@property (nonatomic,strong) NSArray *click_tracking;
@property (nonatomic,strong) NSString *click_through_url;
@property (nonatomic,strong) MATVideoEventTrack *track_event;
@property (nonatomic,strong) MATVideoCompanInfo *companion;;
@property (nonatomic,strong) NSArray *error;
@property (nonatomic,strong) NSArray <MATVideoIconsInfo*> *icons;
@property (nonatomic,strong) NSString *type;
@property (nonatomic,assign) NSInteger width;
@property (nonatomic,assign) NSInteger height;
@property (nonatomic,strong) NSString *title;
@property (nonatomic,strong) NSString *desc;
@property (nonatomic,strong) NSString *cta;
@end

@interface MATVideoEventTrack : NSObject
@property (nonatomic,strong) NSArray *start;
@property (nonatomic,strong) NSArray *firstQuartile;
@property (nonatomic,strong) NSArray *midpoint;
@property (nonatomic,strong) NSArray *thirdQuartile;
@property (nonatomic,strong) NSArray *complete;
@property (nonatomic,strong) NSArray *mute;
@property (nonatomic,strong) NSArray *unmute;
@property (nonatomic,strong) NSArray *rewind;
@property (nonatomic,strong) NSArray *pause;
@property (nonatomic,strong) NSArray *resume;
@property (nonatomic,strong) NSArray *creativeView;
@property (nonatomic,strong) NSArray *fullscreen;
@property (nonatomic,strong) NSArray *acceptInvitationLinear;
@property (nonatomic,strong) NSArray *close;
@property (nonatomic,strong) NSArray *closeLinear;
@property (nonatomic,strong) NSArray *exitFullscreen;
@end


@interface MATVideoIconsInfo : NSObject
@property (nonatomic,strong) NSString *view_tracking;
@property (nonatomic,strong) NSArray *click_tracking;
@property (nonatomic,strong) NSString *click_through_url;
@property (nonatomic,strong) NSString *static_resource;
@property (nonatomic,strong) NSString *program;
@property (nonatomic,assign) NSInteger width;
@property (nonatomic,assign) NSInteger height;
@property (nonatomic,strong) NSString *x_position;
@property (nonatomic,strong) NSString *y_position;
@end

@interface MATVideoCompanInfo : NSObject
@property (nonatomic,strong) NSString *static_resource;
@property (nonatomic,strong) NSString *click_through_url;
@property (nonatomic,strong) MATVideoCompanEventTrack *track_event;
@property (nonatomic,assign) NSInteger width;
@property (nonatomic,assign) NSInteger height;
@end

@interface MATVideoCompanEventTrack : NSObject
@property (nonatomic,strong) NSArray *creativeView;
@end

NS_ASSUME_NONNULL_END
