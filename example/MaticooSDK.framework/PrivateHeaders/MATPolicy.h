//
//  MATPolicy.h
//  MaticooSDK
//
//  Created by root on 2023/4/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define about_child_description  @"aboutChildDescription"

@interface MATPolicy : NSObject

+ (instancetype)shareInstance;

-(BOOL)getIsRestrictUser;

-(void)setDoNotTrackStatus:(BOOL) status;

-(BOOL)getDoNotTrackStatus;

-(void)setIsAgeRestrictedUser:(BOOL) status;

-(BOOL)getIsAgeRestrictedUser;

-(void)setConsentStatus:(BOOL) status;

-(BOOL)getConsentStatus;
@end

NS_ASSUME_NONNULL_END
