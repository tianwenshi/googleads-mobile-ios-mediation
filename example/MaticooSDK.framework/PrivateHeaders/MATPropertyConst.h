//
//  MATPropertyConst.h
//  MaticooSDK
//
//  Created by root on 2023/4/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MATPropertyConst : NSObject
extern NSString *const MATPropertyTypeInt;
extern NSString *const MATPropertyTypeShort;
extern NSString *const MATPropertyTypeFloat;
extern NSString *const MATPropertyTypeDouble;
extern NSString *const MATPropertyTypeLong;
extern NSString *const MATPropertyTypeLongLong;
extern NSString *const MATPropertyTypeChar;
extern NSString *const MATPropertyTypeBOOL1;
extern NSString *const MATPropertyTypeBOOL2;
extern NSString *const MATPropertyTypePointer;

extern NSString *const MATPropertyTypeIvar;
extern NSString *const MATPropertyTypeMethod;
extern NSString *const MATPropertyTypeBlock;
extern NSString *const MATPropertyTypeClass;
extern NSString *const MATPropertyTypeSEL;
extern NSString *const MATPropertyTypeId;
@end

NS_ASSUME_NONNULL_END
