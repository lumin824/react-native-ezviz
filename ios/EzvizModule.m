
#import "RCTBridgeModule.h"
#import "RCTUIManager.h"

#import "EZOpenSDK/EZOpenSDK.h"
#import "EZOpenSDK/EZCameraInfo.h"
#import "EZOpenSDK/EZDeviceInfo.h"

@interface EzvizModule: NSObject<RCTBridgeModule>

@end

@implementation EzvizModule

- (instancetype) init{
    self = [super init];
    if(self){
        NSDictionary *infoDictionary = [[NSBundle mainBundle] infoDictionary];
        NSString *ezvizAppKey = [infoDictionary objectForKey:@"EzvizAppKey"];
        [EZOpenSDK initLibWithAppKey:ezvizAppKey];
    }
    return self;
}

RCT_EXPORT_MODULE();

RCT_EXPORT_METHOD(setAccessToken:(NSString*)accessToken)
{
    [EZOpenSDK setAccessToken:accessToken];
}

RCT_EXPORT_METHOD(getCameraList:(RCTPromiseResolveBlock)resolve
                  reject:(RCTPromiseRejectBlock)reject)
{
    [EZOpenSDK getCameraList:0 pageSize:100 completion:^(NSArray *cameraList, NSError *error) {
        if(error){
            reject([NSString stringWithFormat:@"%d", error.code], error.domain, error);
        }else{
            
            NSMutableArray* array = [[NSMutableArray alloc] initWithCapacity:cameraList.count];
            for(EZCameraInfo* cameraInfo in cameraList){
                NSMutableDictionary* camera = [[NSMutableDictionary alloc]init];
                camera[@"cameraId"] = cameraInfo.cameraId;
                camera[@"cameraName"] = cameraInfo.cameraName;
                camera[@"deviceId"] = cameraInfo.deviceId;
                camera[@"deviceName"] = cameraInfo.deviceName;
                camera[@"isOnline"] = [NSNumber numberWithBool:cameraInfo.isOnline];
                [array addObject:camera];
            }
            resolve(array);
        }
    }];
}

RCT_EXPORT_METHOD(getDeviceInfo:(NSString*)cameraId
                  resolve:(RCTPromiseResolveBlock)resolve
                  reject:(RCTPromiseRejectBlock)reject)
{
    [EZOpenSDK getDeviceInfo:cameraId completion:^(EZDeviceInfo *deviceInfo, NSError *error) {
        if(error){
            reject([NSString stringWithFormat:@"%d", error.code], error.domain, error);
        }
        else{
            NSMutableDictionary* device = [[NSMutableDictionary alloc]init];
            device[@"deviceId"] = deviceInfo.deviceId;
            device[@"deviceName"] = deviceInfo.deviceName;
            device[@"isSupportPTZ"] = [NSNumber numberWithBool:deviceInfo.isSupportPTZ];
            resolve(device);
        }
    }];
}

RCT_EXPORT_METHOD(controlPTZ:(NSString*)cameraId
                  command:(EZPTZCommand)command
                  action:(EZPTZAction)action
                  speed:(NSInteger)speed)
{
    [EZOpenSDK controlPTZ:cameraId command:command action:action speed:speed
                   result:^(BOOL result, NSError *error) {
        
    }];
}

RCT_EXPORT_METHOD(test:(RCTPromiseResolveBlock)resolve
                  reject:(RCTPromiseRejectBlock)reject) {
    resolve(@"ok");
}

-(NSDictionary*) constantsToExport
{
    return @{
        @"EZPTZAction_EZPTZActionSTART":@(EZPTZActionStart),
        @"EZPTZAction_EZPTZActionSTOP":@(EZPTZActionStop),
        @"EZPTZCommand_EZPTZCommandLeft":@(EZPTZCommandLeft),
        @"EZPTZCommand_EZPTZCommandRight":@(EZPtzCommandRight),
        @"EZPTZCommand_EZPTZCommandUp":@(EZPTZCommandUp),
        @"EZPTZCommand_EZPTZCommandDown":@(EZPTZCommandDown),
    };
}

@end

@implementation RCTConvert(EZPTZAction)
RCT_ENUM_CONVERTER(EZPTZAction, (@{
    @"EZPTZAction_EZPTZActionSTART":@(EZPTZActionStart),
    @"EZPTZAction_EZPTZActionSTOP":@(EZPTZActionStop),
}), EZPTZActionStop, integerValue)
@end

@implementation RCTConvert(EZPTZCommand)
RCT_ENUM_CONVERTER(EZPTZCommand, (@{
    @"EZPTZCommand_EZPTZCommandLeft":@(EZPTZCommandLeft),
    @"EZPTZCommand_EZPTZCommandRight":@(EZPtzCommandRight),
    @"EZPTZCommand_EZPTZCommandUp":@(EZPTZCommandUp),
    @"EZPTZCommand_EZPTZCommandDown":@(EZPTZCommandDown),
}), EZPTZCommandLeft, integerValue)
@end
