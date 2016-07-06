#import "EzvizView.h"

#import "EZOpenSDK/EZOpenSDK.h"
#import "EZOpenSDK/EZPlayer.h"

@implementation EzvizView

-(void)setCameraId:(NSString*)cameraId
{
    EZPlayer* player = [EZOpenSDK createPlayerWithCameraId:cameraId];
    [player setPlayerView:self];
    [player startRealPlay];
}
@end