//
//  MATBiddingRequest.h
//  MaticooSDK
//
//  Created by root on 2023/7/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@protocol MATBiddingRequestDelegate;
@interface MATBiddingResult : NSObject
@property (nonatomic,strong) NSString* request_id;
@property (nonatomic,strong) NSNumber* ecpm;
@property (nonatomic,strong) NSString* nurl;
@end

@interface MATBiddingResponse : NSObject
@property (nonatomic,assign) NSInteger code;
@property (nonatomic,strong) NSString *msg;
@property (nonatomic,strong) MATBiddingResult *bid_result;
@end

@interface MATBiddingRequest : NSObject
@property (nonatomic,weak) id<MATBiddingRequestDelegate> delegate;
@property (nonatomic,strong) MATBiddingResponse *bidResponse;
@property (nonatomic,strong) NSString *placementId;
-(void)requestBidding:(NSString*) biddingToken placementId:(NSString*) placementId timestamp:(NSInteger) timestamp;
@end

@protocol MATBiddingRequestDelegate <NSObject>
- (void)biddingResponse:(NSString*)requestId placementId:(NSString*) placementId;
@end
NS_ASSUME_NONNULL_END
