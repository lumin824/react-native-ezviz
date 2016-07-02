package com.lumin824.ezviz;

import android.app.Application;

import com.facebook.react.bridge.Arguments;
import com.facebook.react.bridge.Promise;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.WritableArray;
import com.facebook.react.bridge.WritableMap;
import com.videogo.exception.BaseException;
import com.videogo.openapi.EZOpenSDK;
import com.videogo.openapi.bean.EZCameraInfo;
import com.videogo.openapi.bean.EZDeviceInfo;
import com.videogo.openapi.EZConstants.EZPTZCommand;
import com.videogo.openapi.EZConstants.EZPTZAction;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.annotation.Nullable;


public class EzvizModule extends ReactContextBaseJavaModule {

  public EzvizModule(ReactApplicationContext reactContext) {
    super(reactContext);
  }

  @Override
  public String getName(){
    return "EzvizModule";
  }

  @Override
  public void initialize() {
    super.initialize();

    Application application = (Application) getReactApplicationContext().getBaseContext();

    EZOpenSDK.initLib(application, "95ed8b332fdb402cb8085926144ecb61","");
    EZOpenSDK.getInstance().setAccessToken("at.6m3onvsn7mmyhud4ai601ywqdn7tc9vg-3gl26woblc-19qyfes-nv6q7uam9");

  }

  @ReactMethod
  public void getCameraList(Promise promise){

    try {
      List<EZCameraInfo> cameraInfoList = EZOpenSDK.getInstance().getCameraList(0, 100);
      WritableArray array = Arguments.createArray();
      for(EZCameraInfo cameraInfo: cameraInfoList){
        WritableMap camera = Arguments.createMap();
        camera.putString("cameraId", cameraInfo.getCameraId());
        camera.putString("cameraName", cameraInfo.getCameraName());
        camera.putString("deviceId", cameraInfo.getDeviceId());
        camera.putString("deviceName", cameraInfo.getDeviceName());
        camera.putInt("onlineStatus", cameraInfo.getOnlineStatus());
        array.pushMap(camera);
      }
      promise.resolve(array);
    } catch (BaseException e) {
      promise.reject(e);
    }
  }

  @ReactMethod
  public void getDeviceInfo(String cameraId, Promise promise){
    try {
      EZDeviceInfo deviceInfo = EZOpenSDK.getInstance().getDeviceInfo(cameraId);
      WritableMap device = Arguments.createMap();
      device.putString("deviceId", deviceInfo.getDeviceId());
      device.putString("deviceName", deviceInfo.getDeviceName());
      device.putBoolean("isSupportPTZ", deviceInfo.isSupportPTZ());
      promise.resolve(device);
    } catch (BaseException e) {
      promise.reject(e);
    }
  }

  @ReactMethod
  public void getDeviceList(Promise promise){
    try {
      List<EZDeviceInfo> deviceInfoList = EZOpenSDK.getInstance().getDeviceList(0, 100);
      WritableArray array = Arguments.createArray();
      for(EZDeviceInfo deviceInfo: deviceInfoList){
        WritableMap device = Arguments.createMap();
        device.putString("deviceId", deviceInfo.getDeviceId());
        device.putString("deviceName", deviceInfo.getDeviceName());
        device.putBoolean("isSupportPTZ", deviceInfo.isSupportPTZ());
        array.pushMap(device);
      }
      promise.resolve(array);
    } catch (BaseException e) {
      promise.reject(e);
    }
  }

  @ReactMethod
  public void controlPTZ(String cameraId, String command, String action, int speed, Promise promise){
    int ret = EZOpenSDK.getInstance().controlPTZ(cameraId,
            EZPTZCommand.valueOf(command),
            EZPTZAction.valueOf(action), speed);

    promise.resolve(String.valueOf(ret));
  }

  @Nullable
  @Override
  public Map<String, Object> getConstants() {
    final Map<String, Object> constants = new HashMap<>();
    constants.put("EZPTZAction_EZPTZActionSTART", EZPTZAction.EZPTZActionSTART.name());
    constants.put("EZPTZAction_EZPTZActionSTOP", EZPTZAction.EZPTZActionSTOP.name());
    constants.put("EZPTZCommand_EZPTZCommandLeft", EZPTZCommand.EZPTZCommandLeft.name());
    constants.put("EZPTZCommand_EZPTZCommandRight", EZPTZCommand.EZPTZCommandRight.name());
    constants.put("EZPTZCommand_EZPTZCommandUp", EZPTZCommand.EZPTZCommandUp.name());
    constants.put("EZPTZCommand_EZPTZCommandDown", EZPTZCommand.EZPTZCommandDown.name());
    return constants;
  }
}
