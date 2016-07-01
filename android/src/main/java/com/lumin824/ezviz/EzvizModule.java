package com.lumin824.ezviz;

import com.facebook.react.bridge.Promise;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;


public class EzvizModule extends ReactContextBaseJavaModule {

  public EzvizModule(ReactApplicationContext reactContext) {
    super(reactContext);
  }

  @Override
  public String getName(){
    return "EzvizModule";
  }

  @ReactMethod
  public void test(Promise promise){
    promise.resolve("ok");
  }
}
