//
//  MATPropertyType.h
//  MaticooSDK
//
//  Created by root on 2023/4/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MATPropertyType : NSObject
//Type identifier
@property(nonatomic, copy) NSString* code;

//Id type or not id type
@property(nonatomic, readonly, getter=isIdType) BOOL idType;

//Number type or not number type: int,float,double, and so on
@property(nonatomic, readonly, getter=isNumberType)BOOL numberType;

//Boolean type or not boolean type
@property(nonatomic, readonly, getter=isBoolType)BOOL  boolType;

//Object type  (if not a object type , value is nil)
@property(nonatomic, readonly) Class classType;

//Foundation class or not, for example：NSString, NSArray and so on
@property(nonatomic, readonly, getter=isFromFoundation) BOOL formFoundation;


//通过属性字符串解析出属性类型
+(instancetype)propertyTypeWithPropertyAttributeString:(NSString*)attributeString;
@end

NS_ASSUME_NONNULL_END
