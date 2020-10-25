package com.x.craft2android

import android.content.Context
import android.opengl.GLSurfaceView
import android.util.AttributeSet
import android.util.Log

open class CraftGLSurfaceView(context: Context?) : GLSurfaceView(context) {
    init{
        this.initView();
    }

    fun initView(){
        this.setEGLConfigChooser(5,6,5,0,16,8)
        this.setEGLContextClientVersion(2)
        this.isFocusableInTouchMode=true
        CraftRenderer.context=this.context
        this.setCraftRenderer(CraftRenderer())
//        this.queueEvent()
    }

    open fun setCraftRenderer(renderer: CraftRenderer)
    {
        this.setRenderer(renderer);
    }

}