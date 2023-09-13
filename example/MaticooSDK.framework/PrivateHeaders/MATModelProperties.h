//
//  MATModelProperties.h
//  MaticooSDK
//
//  Created by root on 2023/4/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (MATModelProperty)

+(NSArray*)MATModelPropertys;
+(BOOL)MATIsClassFormFoundation:(Class)c;

@end

NS_ASSUME_NONNULL_END
