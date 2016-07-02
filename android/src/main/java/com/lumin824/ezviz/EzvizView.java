package com.lumin824.ezviz;

import android.content.Context;
import android.view.SurfaceView;

import com.videogo.openapi.EZOpenSDK;
import com.videogo.openapi.EZPlayer;

/**
 * Created by lumin on 16/7/2.
 */
public class EzvizView extends SurfaceView {

    protected EZPlayer ezPlayer;

    public EzvizView(Context context) {
        super(context);
    }

    public void setCameraId(String cameraId){
        if(ezPlayer != null){
            ezPlayer.stopRealPlay();
            ezPlayer = null;
        }

        if(cameraId != null) {
            EZOpenSDK ezOpenSDK = EZOpenSDK.getInstance();
            ezPlayer = ezOpenSDK.createPlayer(getContext(), cameraId);

            ezPlayer.setSurfaceHold(getHolder());
            ezPlayer.startRealPlay();
        }
    }

    public void stopRealPlay(){
        if(ezPlayer != null) {
            ezPlayer.stopRealPlay();
        }
    }


}
