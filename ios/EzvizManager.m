#import "RCTViewManager.h"
#import <MapKit/MapKit.h>



#import "EzvizView.h"

@interface EzvizManager : RCTViewManager

@end

@implementation EzvizManager

RCT_EXPORT_MODULE()

- (UIView *)view
{
  return [[EzvizView alloc] init];
}

RCT_CUSTOM_VIEW_PROPERTY(cameraId, NSString, EzvizView)
{
    
    
    
    view.cameraId = json;
}



@end
