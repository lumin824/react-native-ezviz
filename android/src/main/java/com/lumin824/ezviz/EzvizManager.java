package com.lumin824.ezviz;

import com.facebook.react.uimanager.SimpleViewManager;
import com.facebook.react.uimanager.ThemedReactContext;
import com.facebook.react.uimanager.annotations.ReactProp;

/**
 * Created by lumin on 16/7/1.
 */
public class EzvizManager extends SimpleViewManager<EzvizView> {

    @Override
    public String getName() {
        return "Ezviz";
    }

    @Override
    protected EzvizView createViewInstance(ThemedReactContext reactContext) {
        EzvizView view = new EzvizView(reactContext);
        return view;
    }

    @Override
    public void onDropViewInstance(EzvizView view) {
        super.onDropViewInstance(view);
        view.stopRealPlay();
    }

    @ReactProp(name="cameraId")
    public void setCameraId(EzvizView view, String cameraId){
        view.setCameraId(cameraId);
    }
}
