package com.x.craft2android

import android.app.Activity
import android.content.Context
import android.content.res.AssetManager
import android.opengl.GLSurfaceView
import android.os.Bundle
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : Activity() {
    lateinit var glsv:GLSurfaceView
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        glsv=CraftGLSurfaceView(this)
        setContentView(glsv)
//        this.setNativeAssetManager(resources.assets)
//        stringFromJNI()
    }

    override fun onPause() {
        super.onPause()
        glsv.onPause()
    }

    override fun onResume() {
        super.onResume()
        glsv.onResume()
    }

            /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
//    external fun stringFromJNI(): String
//    external fun setNativeAssetManager(mng:AssetManager)
    companion object {

        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("native-lib")
        }

    }
}
