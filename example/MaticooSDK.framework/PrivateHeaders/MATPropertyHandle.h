//
//  MATPropertyHandle.h
//  MaticooSDK
//
//  Created by root on 2023/4/13.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>

NS_ASSUME_NONNULL_BEGIN
@class MATPropertyType;
@interface MATPropertyHandle : NSObject
@property(nonatomic,copy)NSString* name;
@property(nonatomic,strong)MATPropertyType* type;
//属性对象初始化，通过传入一个属性返回一个属性对象
+(instancetype)propertyWithOriginalProperty:(objc_property_t)property;
@end

NS_ASSUME_NONNULL_END
