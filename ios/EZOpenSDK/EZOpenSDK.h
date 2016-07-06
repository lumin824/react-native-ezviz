//
//  EZOpenSDK.h
//  EzvizOpenSDK
//
//  Created by DeJohn Dong on 15/9/10.
//  Copyright (c) 2015年 Hikvision. All rights reserved.
//

#import <UIKit/UIKit.h>

/* EZOpenSDK的错误定义 */
typedef NS_ENUM(NSInteger, EZErrorCode) {
    EZ_DEVICE_CONNECT_COUNT_LARGEST = 340410, //设备取流连接数量超过最大值
    EZ_DEVICE_TTS_TALKING_TIMEOUT = 360002,   //对讲发起超时
    EZ_DEVICE_QUERY_RECORD_FAILED = 380005,   //远程SD卡搜索录像失败
    EZ_DEVICE_TTS_TALKING = 360010,           //设备正在对讲中
    EZ_DEVICE_IS_PRIVACY_PROTECTING = 380011, //设备隐私保护中
    EZ_DEVICE_CONNECT_COUNT_LIMIT = 380045,   //设备直连取流连接数量过大
    EZ_DEVICE_COMMAND_NOT_SUPPORT = 380047,   //设备不支持该命令
    EZ_DEVICE_CAS_TALKING = 380077,           //设备正在对讲中
    EZ_DEVICE_OFFLINE = 380121,               //设备不在线
    EZ_PLAY_TIMEOUT = 380209,                 //网络连接超时
    EZ_DEVICE_TIMEOUT = 380212,               //设备端网络连接超时
    EZ_DEVICE_BUNDEL_STATUS_ON = 380128,      //设备开启了终端绑定，请到萤石云客户端关闭终端绑定
    EZ_DEVICE_STREAM_LIMIT = 395546,          //设备取流受到限制
    EZ_CLINET_TIMEOUT = 390025,               //同时`390026`手机网络引起的取流超时
    /**
     *  HTTP 错误码
     */
    EZ_HTTPS_SMS_FREQUENTLY = 101041,            //短信发送太频繁，60s一次
    EZ_HTTPS_PARAM_ERROR = 110001,               //请求参数错误
    EZ_HTTPS_ACCESS_TOKEN_INVALID = 110002,      //AccessToken无效
    EZ_HTTPS_REGIST_USER_NOT_EXSIT = 110004,     //注册用户不存在
    EZ_HTTPS_USER_BINDED = 110012,               //第三方账户与萤石账号已经绑定
    EZ_HTTPS_CAMERA_NOT_EXISTS = 120001,         //通道不存在，请检查摄像头设备是否重新添加过
    EZ_HTTPS_DEVICE_NOT_EXISTS = 120002,         //设备不存在
    EZ_HTTPS_DEVICE_NETWORK_ANOMALY = 120006,    //网络异常
    EZ_HTTPS_DEVICE_OFFLINE = 120007,            //设备不在线
    EZ_HTTPS_DEIVCE_RESPONSE_TIMEOUT = 120008,   //设备请求响应超时异常
    EZ_HTTPS_ILLEGAL_DEVICE_SERIAL = 120014,     //不合法的序列号
    EZ_HTTPS_USER_NOT_OWN_THIS_DEVICE = 120018,  //该用户不拥有该设备
    EZ_HTTPS_DEVICE_ADDED_MYSELF = 120017,       //同时`120020`设备已经被自己添加
    EZ_HTTPS_DEVICE_ONLINE_NOT_ADDED = 120021,   //设备在线，未被用户添加
    EZ_HTTPS_DEVICE_ONLINE_IS_ADDED = 120022,    //设备在线，已经被别的用户添加
    EZ_HTTPS_DEVICE_OFFLINE_NOT_ADDED = 120023,  //设备不在线，未被用户添加
    EZ_HTTPS_DEVICE_OFFLINE_IS_ADDED = 120024,   //设备不在线，已经被别的用户添加
    EZ_HTTPS_DEVICE_OFFLINE_IS_ADDED_MYSELF = 120029, //设备不在线，但是已经被自己添加
    EZ_HTTPS_OPERATE_LEAVE_MSG_FAIL = 120202,    //操作留言消息失败
    EZ_HTTPS_DEVICE_BUNDEL_STATUS_ON = 120031,   //同时`106002`错误码也是，设备开启了终端绑定，请到萤石云客户端关闭终端绑定
    EZ_HTTPS_SERVER_DATA_ERROR = 149999,         //数据异常
    EZ_HTTPS_SERVER_ERROR = 150000,              //服务器异常
    /**
     *  接口 错误码(SDK本地校验)
     */
    EZ_SDK_TALK_DOING = 400077,        //对讲进行中，请稍候再试
    EZ_SDK_CAMERAID_NOTEXIST = 400404, //cameraId不存在，请重新获取设备信息
    EZ_SDK_TIMEOUT = 400409,           //取流超时，请检查手机的网络状态
    EZ_SDK_PARAM_ERROR = 400500,       //接口参数错误
    EZ_SDK_STREAM_TIMEOUT = 401011,    //取流连接超时，请检查摄像头的网络状态
};

/* 播放器EZPlayer的状态消息定义 */
typedef NS_ENUM(NSInteger, EZMessageCode) {
    PLAYER_VALIDATE_CODE_CANCEL = -2, //视频加密验证码输入被取消
    PLAYER_NEED_VALIDATE_CODE = -1,   //播放需要安全验证
    PLAYER_REALPLAY_START = 1,        //直播开始
    PLAYER_VIDEOLEVEL_CHANGE = 2,     //直播流清晰度切换中
    PLAYER_STREAM_RECONNECT = 3,      //直播流取流正在重连
    PLAYER_VOICE_TALK_START = 4,      //对讲开始
    PLAYER_VOICE_TALK_END = 5,        //对讲结束
    PLAYER_PLAYBACK_START = 11,       //录像回放开始播放
    PLAYER_PLAYBACK_STOP = 12         //录像回放结束播放
};

/* WiFi配置设备状态 */
typedef NS_ENUM(NSInteger, EZWifiConfigStatus) {
    DEVICE_WIFI_CONNECTING = 1,   //设备正在连接WiFi
    DEVICE_WIFI_CONNECTED = 2,    //设备连接WiFi成功
    DEVICE_PLATFORM_REGISTED = 3, //设备注册平台成功
    DEVICE_ACCOUNT_BINDED = 4     //设备已经绑定账户
};

/* 设备ptz命令 */
typedef NS_OPTIONS(NSUInteger, EZPTZCommand) {
    EZPTZCommandLeft            = 1 << 0, //向左旋转
    EZPtzCommandRight           = 1 << 1, //向右旋转
    EZPTZCommandUp              = 1 << 2, //向上旋转
    EZPTZCommandDown            = 1 << 3, //向下旋转
};

/*
 * 设备显示命令
 */
typedef NS_OPTIONS(NSUInteger, EZDisplayCommand) {
    EZDisplayCommandCenter          = 1 << 0, //显示中间
    EZDisplayCommandLeftRight       = 1 << 1, //左右翻转
    EZDisplayCommandUpDown          = 1 << 2  //上下翻转
};

/**
 *  设备ptz动作命令
 */
typedef NS_ENUM(NSInteger, EZPTZAction) {
    EZPTZActionStart = 1, //ptz开始
    EZPTZActionStop = 2   //ptz停止
};

/* 消息状态 */
typedef NS_ENUM(NSInteger, EZMessageStatus) {
    EZMessageStatusRead = 1,    //已读
};

/* 消息类型 */
typedef NS_ENUM(NSInteger, EZMessageType)
{
    EZMessageTypeAlarm = 1,   //报警类型
    EZMessageTypeLeave,       //留言类型
};

/* 留言消息类型 */
typedef NS_ENUM(NSInteger, EZLeaveMessageType)
{
    EZLeaveMessageTypeAll,    //全部
    EZLeaveMessageTypeVoice,  //语音类
    EZLeaveMessageTypeVideo,  //视频类
};

/* 短信类型 */
typedef NS_ENUM(NSInteger, EZSMSType) {
    EZSMSTypeSecure = 1,     //安全验证
    EZSMSTypeOperate = 2,    //设备操作验证码，比如关闭视频加密操作。
};

@class EZPlayer;
@class EZDeviceInfo;
@class EZAccessToken;
@class EZCameraInfo;
@class EZDeviceVersion;
@class EZUserInfo;
@class EZProbeDeviceInfo;
@class EZDeviceUpgradeStatus;
@class EZLeaveMessage;

/// 此类为EZOpenSDK接口类 特别说明：110001（参数错误）、110002（AccessToken过期）、149999、150000（服务端异常）是所有http接口（返回值是NSOperation对象的大部分是http接口）都会返回的通用错误码，400500为接口参数错误的通用错误码
@interface EZOpenSDK : NSObject

/**
 *  @since 3.0.0
 *  实例EZOpenSDK方法
 *
 *  @param appKey 传入申请的appKey
 *
 *  @return YES/NO
 */
+ (BOOL)initLibWithAppKey:(NSString *)appKey;

/**
 *  @since 3.0.0
 *  销毁EZOpenSDK方法
 *
 *  @return YES/NO
 */
+ (BOOL)destoryLib;

/**
 *  @since 3.0.0
 *  获取SDK版本号
 *
 *  @return 版本号
 */
+ (NSString *)getVersion;

/**
 *  @since 3.0.0
 *  打开授权登录中间页面
 *
 *  @param block 回调block
 */
+ (void)openLoginPage:(void (^)(EZAccessToken *accessToken))block;

/**
 *  @since 3.0.0
 *  授权登录以后给EZOpenSDK设置AccessToken
 *
 *  @param accessToken 授权登录获取的accessToken
 */
+ (void)setAccessToken:(NSString *)accessToken;

/**
 *  @since 3.0.0
 *  登出账号
 *
 *  @param completion 回调block，error为空表示登出成功
 */
+ (void)logout:(void (^)(NSError *error))completion;

/**
 *  @since 3.0.0
 *  打开设备设置中间页
 *
 *  @param deviceSerial 设备序列号
 */
+ (void)openSettingDevicePage:(NSString *)deviceSerial __deprecated_msg("该方法已过期");

/**
 *  @since 3.0.0
 *  获取用户所有的摄像头列表
 *
 *  @param pageIndex  分页当前页码（从0开始）
 *  @param pageSize   分页每页数量（建议20以内)
 *  @param completion 回调block，正常时返回EZCameraInfo的数组，错误时返回错误码
 *  @exception 错误码类型：待补充
 *
 *  @return operation
 */
+ (NSOperation *)getCameraList:(NSInteger)pageIndex
                      pageSize:(NSInteger)pageSize
                    completion:(void (^)(NSArray *cameraList, NSError *error))completion;
/**
 *  @since 3.0.0
 *  根据cameraId获取设备详细信息
 *
 *  @param cameraId    设备摄像头id
 *  @param completion  回调block, 正常时返回EZDeviceInfo的对象信息，错误时返回错误码
 *  @exception 错误码类型：待补充
 *  @see 使用该接口时要注意cameraId必须来自SDK获取cameraInfo以后得到的cameraId。如果是服务端获取的cameraId很有可能收到400500的错误
 */
+ (void)getDeviceInfo:(NSString *)cameraId
           completion:(void (^)(EZDeviceInfo *deviceInfo, NSError *error))completion;

/**
 *  @since 3.0.0
 *  根据查询条件获取指定设备的报警信息列表
 *
 *  @param cameraId   设备摄像头id
 *  @param pageIndex  分页当前页码（从0开始）
 *  @param pageSize   分页每页数量（建议20以内）
 *  @param beginTime  搜索时间范围开始时间
 *  @param endTime    搜索时间范围结束时间
 *  @param completion 回调block，正常时返回EZAlarmInfo的对象数组和查询范围内的报警数量总数，错误时返回错误码
 *  @exception 错误码类型：待补充
 *
 *  @return operation
 */
+ (NSOperation *)getAlarmList:(NSString *)cameraId
                    pageIndex:(NSInteger)pageIndex
                     pageSize:(NSInteger)pageSize
                    beginTime:(NSDate *)beginTime
                      endTime:(NSDate *)endTime
                   completion:(void (^)(NSArray *alarmList, NSInteger alarmCount, NSError *error))completion;

/**
 *  @since 3.0.0
 *  根据alarmId删除报警信息
 *
 *  @param alarmIds   报警信息Id数组(可以只有一个Id)，最多为10个Id，否则会报错
 *  @param completion 回调block，error为空时表示删除成功
 *  @exception 错误码类型：110004、120202，具体参考EZOpenSDK头文件中的EZErrorCode错误码注释
 *
 *  @return operation
 */
+ (NSOperation *)deleteAlarm:(NSArray *)alarmIds
                  completion:(void (^)(NSError *error))completion;

/**
 *  @since 3.0.0
 *  设置报警信息为已读
 *
 *  @param alarmIds   报警信息Id数组(可以只有一个Id)，最多为10个id,否则会报错
 *  @param status     报警消息状态
 *  @param completion 回调block，error为空时表示设置成功
 *  @exception 错误码类型：110004、120202，具体参考EZOpenSDK头文件中的EZErrorCode错误码注释
 *
 *  @return opeartion
 */
+ (NSOperation *)setAlarmStatus:(NSArray *)alarmIds
                    alarmStatus:(EZMessageStatus)status
                     completion:(void (^)(NSError *error))completion;


/**
 *  @since 3.0.0
 *  根据设备序列号删除当前账号的设备
 *
 *  @param deviceSerial 设备序列号
 *  @param completion   回调block，error为空时表示删除成功
 *  @exception 错误码类型：106002，具体参考EZOpenSDK头文件中的EZErrorCode错误码注释
 *  @see 该接口与终端绑定功能相关，会遇到删除时报106002的错误，请关闭终端绑定以后再试
 *
 *  @return operation
 */
+ (NSOperation *)deleteDevice:(NSString *)deviceSerial
                   completion:(void (^)(NSError *error))completion;

/**
 *  @since 3.0.0
 *  根据设备序列号查询摄像头信息。
 *
 *  @param deviceSerial 设备序列号
 *  @param completion   回调block，正常时返回EZCameraInfo的对象信息，错误时返回错误码
 *  @exception 错误码类型：待补充
 *  @see 使用场景通常是B模式下获取单个摄像头信息使用。特别说明：原来的添加前查询设备功能请使用`probeDeviceInfo:completion:`接口来完成
 *
 *  @return operation
 */
+ (NSOperation *)getCameraInfo:(NSString *)deviceSerial
                    completion:(void (^)(EZCameraInfo *cameraInfo, NSError *error))completion;

/**
 *  @since 3.0.0
 *  透传接口，该接口已经不推荐使用
 *
 *  @param transferInfo 透传接口信息(JSON字符串)
 *  @param completion   回调block
 *  @see 兼容旧版本的接口，新用户忽略
 *
 *  @return operation
 */
+ (NSOperation *)transferAPI:(NSString *)transferInfo
                  completion:(void (^)(id responseObject, NSError *error))completion __deprecated_msg("该接口即将废弃");

/**
 *  @since 3.0.0
 *  查询云存储录像信息列表
 *
 *  @param cameraId   设备摄像头id
 *  @param beginTime  查询时间范围开始时间
 *  @param endTime    查询时间范围结束时间
 *  @param completion 回调block，正常时返回EZCloudRecordFile的对象数组，错误时返回错误码
 *  @exception 错误码类型：待补充
 *
 *  @return operation
 */
+ (NSOperation *)searchRecordFileFromCloud:(NSString *)cameraId
                                 beginTime:(NSDate *)beginTime
                                   endTime:(NSDate *)endTime
                                completion:(void (^)(NSArray *couldRecords, NSError *error))completion;

/**
 *  @since 3.0.0
 *  查询远程SD卡存储录像信息列表
 *
 *  @param cameraId   设备摄像头id
 *  @param beginTime  查询时间范围开始时间
 *  @param endTime    查询时间范围结束时间
 *  @param completion 回调block，正常时返回EZDeviceRecrodFile的对象数组，错误时返回错误码
 *  @exception 错误码类型：400404，具体参考EZOpenSDK头文件中的EZErrorCode错误码注释
 *
 *  @return operation
 */
+ (NSOperation *)searchRecordFileFromDevice:(NSString *)cameraId
                                  beginTime:(NSDate *)beginTime
                                    endTime:(NSDate *)endTime
                                 completion:(void (^)(NSArray *deviceRecords, NSError *error))completion;

/**
 *  @since 3.0.0
 *  开始WiFi配置
 *
 *  @param ssid         连接WiFi SSID
 *  @param password     连接WiFi 密码
 *  @param deviceSerial 连接WiFi的设备的设备序列号
 *  @param statusBlock  返回连接设备的WiFi配置状态
 *
 *  @return YES/NO
 */
+ (BOOL)startConfigWifi:(NSString *)ssid
               password:(NSString *)password
           deviceSerial:(NSString *)deviceSerial
           deviceStatus:(void (^)(EZWifiConfigStatus status))statusBlock;

/**
 *  @since 3.0.0
 *  根据设备序列号和设备验证码添加设备
 *
 *  @param deviceSerial 设备序列号
 *  @param deviceCode   设备验证码
 *  @param completion   回调block，error为空时表示添加成功
 *  @exception 错误码类型：120002、120006、120007、120008、120014，具体参考EZOpenSDK头文件中的EZErrorCode错误码注释
 *
 *  @return operation
 */
+ (NSOperation *)addDevice:(NSString *)deviceSerial
                deviceCode:(NSString *)deviceCode
                completion:(void (^)(NSError *error))completion;

/**
 *  @since 3.0.0
 *  停止Wifi配置
 *
 *  @return YES/NO
 */
+ (BOOL)stopConfigWifi;

/**
 *  @since 3.0.0
 *  PTZ 控制接口
 *
 *  @param cameraId    设备摄像头id
 *  @param command     ptz控制命令
 *  @param action      控制启动/停止
 *  @param speed       速度 (取值范围：0-7整数值)
 *  @param resultBlock 回调block，正常时result为YES，错误时result为NO并且附带错误码
 *  @exception 错误码类型：待补充
 *
 *  @return YES/NO
 */
+ (BOOL)controlPTZ:(NSString *)cameraId
           command:(EZPTZCommand)command
            action:(EZPTZAction)action
             speed:(NSInteger)speed
            result:(void (^)(BOOL result, NSError *error))resultBlock;

/**
 *  @since 3.0.0
 *  摄像头显示控制接口
 *
 *  @param cameraId    设备摄像头id
 *  @param command     显示控制命令
 *  @param resultBlock 回调block，正常时result为YES，错误时result为NO并且附带错误码
 *  @exception 错误码类型：待补充
 *
 *  @return YES/NO
 */
+ (BOOL)controlDisplay:(NSString *)cameraId
               command:(EZDisplayCommand)command
                result:(void (^)(BOOL result, NSError *error))resultBlock;

/**
 *  @since 3.0.0
 *  根据cameraId构造EZPlayer对象
 *
 *  @param cameraId 设备摄像头Id
 *
 *  @return EZPlayer对象
 */
+ (EZPlayer *)createPlayerWithCameraId:(NSString *)cameraId;


/**
 *  @since 3.0.0
 *  根据url构造EZPlayer对象 （主要用来处理视频广场的播放）
 *
 *  @param url 播放url
 *
 *  @return EZPlayer对象
 */
+ (EZPlayer *)createPlayerWithUrl:(NSString *)url;


/**
 *  @since 3.0.0
 *  释放EZPlayer对象
 *
 *  @param player EZPlayer对象
 *
 *  @return YES/NO
 */
+ (BOOL)releasePlayer:(EZPlayer *)player;

#pragma mark - V3.1 新增加接口

/**
 *  @since 3.1.0
 *  数据解密
 *
 *  @param data     需要解密的数据
 *  @param password 解密密码
 *
 *  @return 解密的NSData对象
 */
+ (NSData *)decryptData:(NSData *)data password:(NSString *)password;

/**
 *  @since 3.1.0
 *  根据设备序列号从SDK获取设备验证码
 *
 *  @param deviceSerial 设备序列号
 *
 *  @return 设备验证码
 */
+ (NSString *)getValidteCode:(NSString *)deviceSerial;

/**
 *  @since 3.1.0
 *  向SDK设置设备序列号和设备验证码
 *
 *  @param validateCode 设备验证码
 *  @param deviceSerail 设备序列号
 */
+ (void)setValidateCode:(NSString *)validateCode forDeviceSerial:(NSString *)deviceSerail;

/**
 *  @since 3.1.0
 *  获取短信验证码接口
 *
 *  @param type       短信类型
 *  @param completion 回调block，error为空时与表示发送成功
 *  @exception 错误码类型：101041，具体参考EZOpenSDK头文件中的EZErrorCode错误码注释
 *
 *  @return operation
 */
+ (NSOperation *)getSMSCode:(EZSMSType)type completion:(void (^)(NSError *error))completion;

/**
 *  @since 3.1.0
 *  验证安全验证码接口
 *
 *  @param smsCode    获取到的手机短信安全验证码
 *  @param completion 回调block，error为空时表示验证成功
 *  @deprecated 该接口已经废弃，平台不会再返回要求安全验证的功能
 *
 *  @return operation
 */
+ (NSOperation *)validateSecureSMSCode:(NSString *)smsCode
                            completion:(void (^)(NSError *error))completion;
+ (NSOperation *)secureSmsValidate:(NSString *)smsCode
                        completion:(void (^)(NSError *error))completion __deprecated_msg("使用`validateSecureSMSCode:completion:`替代");

/**
 *  @since 3.1.0
 *  获取视频广场的频道列表
 *
 *  @param completion 回调block，正常时返回EZSquareChannel的对象数组，错误时返回错误码
 *  @exception 错误码类型：待补充
 *
 *  @return operation
 */
+ (NSOperation *)getSquareChannelList:(void (^)(NSArray *squareColumns, NSError *error))completion;

/**
 *  @since 3.1.0
 *  获取视频广场公共资源视频列表
 *
 *  @param channelId  频道编号
 *  @param pageIndex  分页当前页码（从0开始）
 *  @param pageSize   分页每页数量（建议20以内）
 *  @param completion 回调block，正常时返回EZSquareVideo的对象数组，错误时返回错误码
 *  @exception 错误码类型：待补充
 *
 *  @return operation
 */
+ (NSOperation *)getSquareVideoList:(NSInteger)channelId
                          pageIndex:(NSInteger)pageIndex
                           pageSize:(NSInteger)pageSize
                         completion:(void (^)(NSArray *videoList, NSInteger totalCount, NSError *error))completion;
/**
 *  @since 3.1.0
 *  收藏视频广场公共资源
 *
 *  @param videoId   视频Id
 *  @param completion 回调block，正常时返回收藏的id信息，错误时返回错误码
 *  @exception 错误码类型：待补充
 *
 *  @return operation
 */
+ (NSOperation *)saveFavorite:(NSString *)videoId
                   completion:(void (^)(NSString *favoriteId, NSError *error))completion;
/**
 *  @since 3.1.0
 *  取消收藏的视频广场公共资源
 *
 *  @param favoriteId 收藏Id
 *  @param completion 回调block，error为空时表示取消收藏成功
 *  @exception 错误码类型：待补充
 *
 *  @return operation
 */
+ (NSOperation *)cancelFavorite:(NSString *)favoriteId
                     completion:(void (^)(NSError *error))completion;

/**
 *  @since 3.1.0
 *  获取收藏的视频广场公共资源列表
 *
 *  @param pageIndex  分页当前页码（从0开始）
 *  @param pageSize   分页每页数量（建议20以内）
 *  @param completion 回调block，正常时返回EZFavoriteSquareVideo的对象数组和收藏总数，错误时返回错误码
 *  @exception 错误码类型：待补充
 *
 *  @return operation
 */
+ (NSOperation *)getFavoriteSquareVideoList:(NSInteger)pageIndex
                                   pageSize:(NSInteger)pageSize
                                 completion:(void (^)(NSArray *videoList, NSInteger totalCount, NSError *error))completion;

/**
 *  @since 3.1.0
 *  检查视频广场资源是否被收藏过
 *
 *  @param videoIds   videoIds，可以是多个值
 *  @param completion 回调block，正常时返回EZCheckFavoriteSquareVideo的对象数组，错误时返回错误码
 *  @exception 错误码类型：待补充
 *
 *  @return operation
 */
+ (NSOperation *)checkFavorite:(NSArray *)videoIds
                    completion:(void (^)(NSArray *checkFavorites, NSError *error))completion;

#pragma mark - V3.2 新增加接口

/**
 *  @since 3.2.0
 *  根据设备序列号控制设备的活动检测开关接口，该接口只支持IPC设备，非IPC设备请使用`setDeviceDefence:deviceSerial:completion`接口设置布撤防
 *
 *  @param isDefence    YES为开，NO为关
 *  @param deviceSerial 设备序列号
 *  @param completion   回调block，error为空表示设置成功
 *  @exception 错误码类型：110004、120002、120014、120018，具体参考EZOpenSDK头文件中的EZErrorCode错误码注释
 *
 *  @return operation
 */
+ (NSOperation *)setDefence:(BOOL)isDefence
               deviceSerial:(NSString *)deviceSerial
                 completion:(void (^)(NSError *error))completion;

/**
 *  @since 3.2.0
 *  获取开通萤石云服务的短信验证码接口
 *
 *  @param mobileNumber 手机号码
 *  @param completion   回调block，error为空表示发送短信成功
 *  @exception 错误码类型：101041，具体参考EZOpenSDK头文件中的EZErrorCode错误码注释
 *
 *  @return operation
 */
+ (NSOperation *)getOpenEzvizServiceSMSCode:(NSString *)mobileNumber
                                 completion:(void (^)(NSError *error))completion;

/**
 *  @since 3.2.0
 *  开通萤石云服务接口
 *
 *  @param mobileNumber 手机号码
 *  @param smsCode      收到的开通服务的短信验证码
 *  @param completion   回调block，error为空表示操作成功
 *  @exception 错误码类型：110004、110012，具体参考EZOpenSDK头文件中的EZErrorCode错误码注释
 *
 *  @return operation
 */
+ (NSOperation *)openEzvizService:(NSString *)mobileNumber
                          smsCode:(NSString *)smsCode
                       completion:(void (^)(NSError *error))completion;

/**
 *  @since 3.2.0
 *  获取抓取摄像头图片的url接口
 *
 *  @param deviceSerial 设备序列号
 *  @param channelNo    通道号
 *  @param completion   回调block，正常时返回url地址信息，错误时返回错误码
 *  @exception 错误码类型：120001、120002、120006、120008，具体参考EZOpenSDK头文件中的EZErrorCode错误码注释
 *  @see 该接口比较耗时，不建议进行批量设备抓图，SDK内部只支持6个http请求并发，该接口会持续占用http请求资源，如果遇到http请求延时巨大问题，优先考虑抓图接口并发造成的问题
 *
 *  @return operation
 */
+ (NSOperation *)capturePicture:(NSString *)deviceSerial
                      channelNo:(NSInteger)channelNo
                     completion:(void (^)(NSString *url, NSError *error))completion;

/**
 *  @since 3.2.0
 *  获取设备的版本信息接口
 *
 *  @param deviceSerial 设备序列号
 *  @param completion   回调block，正常时返回EZDeviceVersion的对象信息，错误时返回错误码
 *  @exception 错误码类型：110004、120002、120014、120018，具体参考EZOpenSDK头文件中的EZErrorCode错误码注释
 *
 *  @return operation
 */
+ (NSOperation *)getDeviceVersion:(NSString *)deviceSerial
                       completion:(void (^)(EZDeviceVersion *version, NSError *error))completion;

/**
 *  @since 3.2.0
 *  设备视频图片加密开关接口（短信方式）
 *
 *  @param isEncrypt    是否加密
 *  @param deviceSerial 设备序列号
 *  @param smsCode      绑定手机号收到的设备操作短信验证码，关闭视频加密的时候smsCode才是必填
 *  @param completion   回调block，error为空时表示操作成功
 *  @exception 错误码类型：110004、120002、120006、120007、120008、120014、120018，具体参考EZOpenSDK头文件中的EZErrorCode错误码注释
 *  @see 该接口不推荐使用，如果是B模式情况下，短信验证数每天有上限（10条）
 *
 *  @return operation
 */
+ (NSOperation *)setDeviceEnryptStatus:(BOOL)isEncrypt
                          deviceSerial:(NSString *)deviceSerial
                               smsCode:(NSString *)smsCode
                            completion:(void (^)(NSError *error))completion __deprecated_msg("该接口不推荐使用，请使用通过设备验证码开关视频图片加密接口");

/**
 *  @since 3.4.0
 *  通过设备验证码开关视频图片加密接口
 *
 *  @param isEncrypt    是否加密，只有NO(关闭)的时候需要设备验证码的相关参数(vaildateCode)
 *  @param deviceSerial 设备序列号
 *  @param validateCode 设备验证码
 *  @param completion   回调block，error为空时表示操作成功
 *  @exception 错误码类型：110004、120002、120006、120007、120008、120014、120018，具体参考EZOpenSDK头文件中的EZErrorCode错误码注释
 *
 *  @return operation
 */
+ (NSOperation *)setDeviceEnryptStatusEx:(BOOL)isEncrypt
                            deviceSerial:(NSString *)deviceSerial
                            validateCode:(NSString *)validateCode
                              completion:(void (^)(NSError *))completion;

/**
 *  @since 3.2.0
 *  根据设备序列号修改设备名称接口
 *
 *  @param deviceSerial 设备序列号
 *  @param deviceName   设备名称
 *  @param completion   回调block，error为空时表示修改成功
 *  @exception 错误码类型：110004、120002、120014、120018，具体参考EZOpenSDK头文件中的EZErrorCode错误码注释
 *
 *  @return operation
 */
+ (NSOperation *)setDeviceName:(NSString *)deviceName
                  deviceSerial:(NSString *)deviceSerial
                    completion:(void (^)(NSError *error))completion;

/**
 *  @since 3.2.0
 *  获取用户基本信息的接口
 *
 *  @param completion 回调block， 正常时返回EZUserInfo的对象，错误时返回错误码
 *  @exception 错误码类型：110004，具体参考EZOpenSDK头文件中的EZErrorCode错误码注释
 *
 *  @return operation
 */
+ (NSOperation *)getUserInfo:(void (^)(EZUserInfo *userInfo, NSError *error))completion;

/**
 *  @since 3.2.0
 *  根据设备序列号获取未读消息数，设备序列号为空时获取所有设备的未读消息数
 *
 *  @param deviceSerial 需要获取的设备序列号，为空时返回账户下所有设备的未读消息数
 *  @param type         消息类型：EZMessageTypeAlarm 报警消息（1），EZMessageTypeLeave 留言消息（2）
 *  @param completion   回调block，正常时返回未读数量，错误时返回错误码
 *  @exception 错误码类型：110004、120002、120014、120018、120202，具体参考EZOpenSDK头文件中的EZErrorCode错误码注释
 *
 *  @return operation
 */
+ (NSOperation *)getUnreadMessageCount:(NSString *)deviceSerial
                           messageType:(EZMessageType)type
                            completion:(void (^)(NSInteger count, NSError *error))completion;

/**
 *  @since 3.2.0
 *  根据设备序列号获取设备的留言消息列表
 *
 *  @param deviceSerial 需要获取的设备序列号
 *  @param beginTime    开始时间
 *  @param endTime      结束时间
 *  @param pageIndex    分页页码
 *  @param pageSize     分页单页数量
 *  @param completion   回调block，正常时返回EZLeaveMessage的对象数组，错误时返回错误码
 *  @exception 错误码类型：110004、120002、120014、120018、120202，具体参考EZOpenSDK头文件中的EZErrorCode错误码注释
 *
 *  @return operation
 */
+ (NSOperation *)getLeaveMessageList:(NSString *)deviceSerial
                           pageIndex:(NSInteger)pageIndex
                            pageSize:(NSInteger)pageSize
                           beginTime:(NSDate *)beginTime
                             endTime:(NSDate *)endTime
                          completion:(void (^)(NSArray *leaveMessageList, NSInteger totalCount, NSError *error))completion;

/**
 *  @since 3.2.0
 *  根据leaveId设置留言消息状态
 *
 *  @param leaveIds   留言消息Id数组(最大数量为10，允许只有1个)，多个ID以半角逗号隔开，如：1234565,124344
 *  @param status     需要设置的留言状态，目前只支持 EZMessageStatusRead(已读)；
 *  @param completion 回调block，error为空表示设置成功
 *  @exception 错误码类型：110004、120202，具体参考EZOpenSDK头文件中的EZErrorCode错误码注释
 *
 *  @return operation
 */
+ (NSOperation *)setLeaveMessageStatus:(NSArray *)leaveIds
                         messageStatus:(EZMessageStatus)status
                            completion:(void (^)(NSError *error))completion;

/**
 *  @since 3.2.0
 *  根据leaveId删除留言消息
 *
 *  @param leaveIds   留言消息Id数组(最大数量为10，允许只有1个)，多个ID以半角逗号隔开,如：1234565,124344
 *  @param completion 回调block，error为空表示删除成功
 *  @exception 错误码类型：110004、120202，具体参考EZOpenSDK头文件中的EZErrorCode错误码注释
 *
 *  @return operation
 */
+ (NSOperation *)deleteLeaveMessage:(NSArray *)leaveIds
                         completion:(void (^)(NSError *error))completion;

/**
 *  @since 3.2.0
 *  根据设备序列号获取存储介质状态(如是否初始化，格式化进度等)
 *
 *  @param deviceSerial 设备序列号
 *  @param completion   回调block，正常时返回EZStorageStauts的对象数组，错误时返回错误码
 *  @exception 错误码类型：110004、120002、120006、120007、120008、120014、120018，具体参考EZOpenSDK头文件中的EZErrorCode错误码注释
 *
 *  @return operation
 */
+ (NSOperation *)getStorageStatus:(NSString *)deviceSerial
                       completion:(void (^)(NSArray *storageStatus, NSError *error))completion;

/**
 *  @since 3.2.0
 *  根据设备序列号和分区编号格式化分区（SD卡）
 *
 *  @param deviceSerial 设备序列号
 *  @param storageIndex 查询返回的分区号，0表示全部格式化，可能会有几块硬盘的情况
 *  @param completion   回调block，error为空表示设置成功
 *  @exception 错误码类型：110004、120002、120006、120007、120008、120014、120016、120018，具体参考EZOpenSDK头文件中的EZErrorCode错误码注释
 *
 *  @return operation
 */
+ (NSOperation *)formatStorage:(NSString *)deviceSerial
                  storageIndex:(NSInteger)storageIndex
                    completion:(void (^)(NSError *error))completion;
/**
 *  @since 3.2.0
 *  尝试查询设备信息，设备Wifi配置前查询一次设备的信息
 *
 *  @param deviceSerial 设备序列号
 *  @param completion   回调block，正常时返回EZProbeDeviceInfo对象，错误码返回错误码
 *  @exception 错误码类型：110004、120002、120014、120020、120021、120022、120023、120024、120029，具体参考EZOpenSDK头文件中的EZErrorCode错误码注释
 *  @see 全新的设备是没有注册到平台的，所以会出现设备不存在的情况，设备wifi配置成功以后会上报数据到萤石云平台，以后每次查询就不会出现设备不存在的情况了。
 *
 *  @return operation
 */
+ (NSOperation *)probeDeviceInfo:(NSString *)deviceSerial
                      completion:(void (^)(EZProbeDeviceInfo *deviceInfo, NSError *error))completion;

/**
 *  @since 3.2.0
 *  根据设备序列号获取设备升级时的进度状态
 *
 *  @param deviceSerial 设备序列号
 *  @param completion   回调block，正常时返回EZDeviceUpgradeStatus对象，错误时返回错误码
 *  @exception 错误码类型：120002、120006、120007、120008、120014，具体参考EZOpenSDK头文件中的EZErrorCode错误码注释
 *
 *  @return operation
 */
+ (NSOperation *)getDeviceUpgradeStatus:(NSString *)deviceSerial
                             completion:(void (^)(EZDeviceUpgradeStatus *status, NSError *error))completion;

/**
 *  @since 3.2.0
 *  通过设备序列号对设备进行升级操作，前提是该设备有更新软件的提示
 *
 *  @param deviceSerial 设备序列号
 *  @param completion   回调block，error为空表示操作成功
 *  @exception 错误码类型：120002、120006、120007、120008、120014，具体参考EZOpenSDK头文件中的EZErrorCode错误码注释
 *
 *  @return operation
 */
+ (NSOperation *)upgradeDevice:(NSString *)deviceSerial
                    completion:(void (^)(NSError *error))completion;

/**
 *  @since 3.2.0
 *  通过设备序列号获取设备基本信息
 *
 *  @param deviceSerial 设备序列号
 *  @param completion   回调block，正常时返回EZDeviceInfo的基本信息，错误时返回错误码
 *  @exception 错误码类型：110004、120002、120014、120018，具体参考EZOpenSDK头文件中的EZErrorCode错误码注释
 *
 *  @return operation
 */
+ (NSOperation *)getDeviceInfoBySerial:(NSString *)deviceSerial
                            completion:(void (^)(EZDeviceInfo *deviceInfo, NSError *error))completion;

/**
 *  @since 3.2.0
 *  根据EZLeaveMessage对象信息获取语音留言消息数据接口
 *  @param message    留言消息对象
 *  @param completion 回调block （resultCode = 1 表示语音下载成功，-1表示下载失败）
 *
 *  @return operation
 */
+ (NSOperation *)getLeaveMessageData:(EZLeaveMessage *)message
                          completion:(void (^)(NSData *data, NSInteger resultCode))completion;

/**
 *  @since 3.2.0
 *  打开云存储中间页
 *
 *  @param deviceSerial 设备序列号
 */
+ (void)openCloudPage:(NSString *)deviceSerial;

#pragma mark - V3.3 新增加接口

/**
 *  @since 3.3.0
 *  获取用户所有的设备列表
 *
 *  @param pageIndex  分页当前页码（从0开始）
 *  @param pageSize   分页每页数量（建议20以内）
 *  @param completion 回调block，正常时返回EZDeviceInfo（非完整对象）的对象数组和设备总数，错误时返回错误码
 *  @exception 错误码类型：110004，具体参考EZOpenSDK头文件中的EZErrorCode错误码注释
 *
 *  @return operation
 */
+ (NSOperation *)getDeviceList:(NSInteger)pageIndex
                      pageSize:(NSInteger)pageSize
                    completion:(void (^)(NSArray *deviceList, NSInteger totalCount, NSError *error))completion;

/**
 *  @since 3.3.0
 *  根据设备序列号获取设备关联的探测器列表
 *
 *  @param deviceSerial 设备序列号
 *  @param completion   回调block，正常时返回EZDetectorInfo的对象数组，错误时返回错误码
 *  @exception 错误码类型：110004、120002、120014、120018，具体参考EZOpenSDK头文件中的EZErrorCode错误码注释
 *
 *  @return operation
 */
+ (NSOperation *)getDetectorList:(NSString *)deviceSerial
                      completion:(void (^)(NSArray *detectorList, NSError *error))completion;


/**
 *  @since 3.3.0
 *  根据设备序列号获取报警信息列表，设备序列号为nil时查询整个账户下的报警信息列表
 *
 *  @param deviceSerial 设备序列号
 *  @param pageIndex    分页当前页码（从0开始）
 *  @param pageSize     分页每页数量（建议20以内）
 *  @param beginTime    搜索时间范围开始时间（可以为空，nil代表为空）
 *  @param endTime      搜索时间范围结束时间（可以为空，nil代表为空）
 *  @param completion   回调block，正常时返回EZAlarmInfo的对象数据和查询时间范围内的报警个数的总数，错误时返回错误码
 *  @exception 错误码类型：110004、120002、120014、120018，具体参考EZOpenSDK头文件中的EZErrorCode错误码注释
 *
 *  @return operation
 */
+ (NSOperation *)getAlarmListBySerial:(NSString *)deviceSerial
                            pageIndex:(NSInteger)pageIndex
                             pageSize:(NSInteger)pageSize
                            beginTime:(NSDate *)beginTime
                              endTime:(NSDate *)endTime
                           completion:(void (^)(NSArray *alarmList, NSInteger totalCount, NSError *error))completion;

/**
 *  @since 3.3.0
 *  设备设置布防状态，兼容A1和IPC设备的布防
 *
 *  @param defence      布防状态, IPC布防状态只有0和1，A1有0:睡眠 8:在家 16:外出
 *  @param deviceSerial 设备序列号
 *  @param completion   回调block，error为空表示设置成功
 *  @exception 错误码类型：110004、120002、120014、120018，具体参考EZOpenSDK头文件中的EZErrorCode错误码注释
 *
 *  @return operation
 */
+ (NSOperation *)setDeviceDefence:(NSInteger)defence
                     deviceSerial:(NSString *)deviceSerial
                       completion:(void (^)(NSError *error))completion;

/**
 *  @since 3.3.0
 *  打开修改密码中间页
 *
 *  @param completion 回调block resultCode为0时表示修改密码成功
 */
+ (void)openChangePasswordPage:(void (^)(NSInteger resultCode))completion;

@end
