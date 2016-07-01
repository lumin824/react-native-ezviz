
#import "RCTBridgeModule.h"
#import "RCTUIManager.h"

@interface EzvizModule: NSObject<RCTBridgeModule>

@end

@implementation EzvizModule

- (instancetype) init{
    self = [super init];

    return self;
}

RCT_EXPORT_MODULE();

RCT_EXPORT_METHOD(test:(RCTPromiseResolveBlock)resolve
                  reject:(RCTPromiseRejectBlock)reject) {
    resolve(@"ok");
}

@end
