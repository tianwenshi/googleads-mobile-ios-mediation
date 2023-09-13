//
//  MATInteractEntranceView.h
//  MaticooSDK
//
//  Created by Mirinda on 2023/5/24.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class MATInteractEntranceView;

@protocol MATInteractEntranceViewDelegate <NSObject>
- (void)MATInteractEntranceViewIsImp:(MATInteractEntranceView *)entranceView;
@end

@interface MATInteractEntranceView : UIView
@property (nonatomic, weak) id<MATInteractEntranceViewDelegate> delegate;
@end

NS_ASSUME_NONNULL_END
