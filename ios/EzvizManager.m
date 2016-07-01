#import "RCTViewManager.h"
#import <MapKit/MapKit.h>

@interface EzvizManager : RCTViewManager

@end

@implementation EzvizManager

RCT_EXPORT_MODULE()

- (UIView *)view
{
  return [[MKMapView alloc] init];
}



@end
