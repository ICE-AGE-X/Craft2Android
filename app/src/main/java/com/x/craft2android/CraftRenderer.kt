package com.x.craft2android

import android.content.Context
import android.content.res.AssetManager
import android.opengl.GLES20
import android.opengl.GLSurfaceView
import android.util.Log
import javax.microedition.khronos.egl.EGLConfig
import javax.microedition.khronos.opengles.GL10

class CraftRenderer :GLSurfaceView.Renderer {
    var mScreenWidth=0
    var mScreenHeight=0
    var resPath:String=""
    override fun onSurfaceCreated(gl: GL10?, config: EGLConfig?) {
        _startTime  = 0
        setNativeAssetManager(context.resources.assets)
        CraftRenderer.nativeInit(this.mScreenWidth,this.mScreenHeight,resPath)
    }

    override fun onSurfaceChanged(gl: GL10?, width: Int, height: Int) {
        CraftRenderer.nativeOnSurfaceChanged(width,height)
    }

    override fun onDrawFrame(gl: GL10?) {
        CraftRenderer.nativeRender((System.currentTimeMillis()- _startTime).toDouble())
        _startTime=System.currentTimeMillis()
    }
    external fun setNativeAssetManager(mng: AssetManager)
    companion object{
        var _startTime:Long=0
        open lateinit var context: Context
        external fun nativeInit(width: Int,height: Int,resPath:String)
        external fun nativeOnSurfaceChanged(width: Int,height: Int)
        external fun nativeRender(dt:Double)
//        @JvmStatic
//        fun getTime():Double
//        {
//            return _time
//        }
//        @JvmStatic
//        fun setTime(t:Double)
//        {
//            _time=t
//            _startTime=System.currentTimeMillis()
//            Log.i("Craft2Android", "setTime:"+t);
//        }
    }

}