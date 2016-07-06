//
//  EZCheckFavoriteSquareVideo.h
//  EzvizOpenSDK
//
//  Created by DeJohn Dong on 15/12/2.
//  Copyright © 2015年 Hikvision. All rights reserved.
//

#import <Foundation/Foundation.h>

/// 此类为视频广场视频收藏比较对象
@interface EZCheckFavoriteSquareVideo : NSObject

/// 视频编号
@property (nonatomic, copy) NSString *videoId;
/// 收藏编号
@property (nonatomic, copy) NSString *favoriteId;

@end
