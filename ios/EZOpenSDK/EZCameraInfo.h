//
//  EZCameraInfo.h
//  EzvizOpenSDK
//
//  Created by DeJohn Dong on 15/9/15.
//  Copyright (c) 2015年 Hikvision. All rights reserved.
//

#import <Foundation/Foundation.h>

/// 此类为摄像头信息对象
@interface EZCameraInfo : NSObject

/// 摄像头Id，设备每次删除添加以后此属性会变化，不建议缓存
@property (nonatomic, copy) NSString *cameraId;
/// 摄像头名称
@property (nonatomic, copy) NSString *cameraName;
/// 通道号
@property (nonatomic) NSInteger channelNo;
/// 设备Id，暂时无特别用处，注意与cameraId区分，很多用户会把它们搞混而造成错误
@property (nonatomic, copy) NSString *deviceId;
/// 设备名称
@property (nonatomic, copy) NSString *deviceName;
/// 设备序列号
@property (nonatomic, copy) NSString *deviceSerial;
/// 设备是否加密
@property (nonatomic) BOOL isEncrypt;
/// 分享状态：0、未分享，1、分享所有者，2、分享接受者（表示此摄像头是别人分享给我的）
@property (nonatomic) NSInteger isShared;
/// 设备在PC端设置的封面地址
@property (nonatomic, copy) NSString *picUrl;
/// 设备在线状态
@property (nonatomic) BOOL isOnline;
/// 设备是否开启活动检测
@property (nonatomic) BOOL isDefence;
/// 视频清晰度：0、流畅，1、均衡，2、高清
@property (nonatomic) NSInteger videoLevel;

@end
