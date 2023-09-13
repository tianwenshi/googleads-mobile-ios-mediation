//
//  MATJsonObject.h
//  MaticooSDK
//
//  Created by root on 2023/4/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol MATModelKeyValue <NSObject>

@optional

//数组指定特殊的类进行解析
+ (NSDictionary *) objectClassInArray;

//将特殊的key作替换
+ (NSDictionary *) replacedKeyWithPropertyName;

@end


@interface NSObject (MATModelKeyValue2Object)<MATModelKeyValue>
//把josn数据转成对象
+(instancetype)MATObjectWithKeyValues:(id)keyValues;
@end

NS_ASSUME_NONNULL_END
