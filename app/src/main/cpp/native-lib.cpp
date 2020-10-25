
#include <string>

#include "native-lib.h"
#include "test.h"
#include "glfwImp.h"
#include "lodepng.h"
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>
#include <pthread.h>
//extern GetTime gTime;
//extern SetTime sTime;
extern AndroidGetFileLength androidGetFileLength;
extern AndroidReadFile androidReadFile;
JNIEnv *jniEnv= nullptr;
JavaVM *javaVm= nullptr;
static pthread_key_t g_key;
void _detachCurrentThread(void* a) {
    javaVm->DetachCurrentThread();
}
JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved){
    LOGI("jni onload");
    javaVm=vm;
    if(vm->GetEnv((void **)&jniEnv, JNI_VERSION_1_6) != JNI_OK)
    {
        return -1;
    }
    pthread_key_create(&g_key, _detachCurrentThread);
    return JNI_VERSION_1_6;
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_x_craft2android_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT void JNICALL
Java_com_x_craft2android_CraftRenderer_00024Companion_nativeInit(JNIEnv *env, jobject thiz,
                                                                 jint width, jint height,
                                                                 jstring res_path) {
//    LOGI("reg time func");
//    gTime=getTime;
//    sTime=setTime;
    LOGI("reg read file func");
    androidGetFileLength=getFileSize;
    androidReadFile=readFile;
    LOGI("call main");
    init_main(width, height);

}extern "C"
JNIEXPORT void JNICALL
Java_com_x_craft2android_CraftRenderer_00024Companion_nativeOnSurfaceChanged(JNIEnv *env,
                                                                             jobject thiz,
                                                                             jint width,
                                                                             jint height) {
    onViewChange(width,height);
}extern "C"
JNIEXPORT void JNICALL
Java_com_x_craft2android_CraftRenderer_00024Companion_nativeRender(JNIEnv *env, jobject thiz,jdouble dt) {
    draw(dt);
}


//double getTime()
//{
//    jclass craftRenderer=jniEnv->FindClass("com/x/craft2android/CraftRenderer");
//    jmethodID getTime=jniEnv->GetStaticMethodID(craftRenderer, "getTime", "()D");
//    jdouble d=jniEnv->CallStaticDoubleMethod(craftRenderer, getTime);
//    jniEnv->DeleteLocalRef(craftRenderer);
//    return  d;
//}
//
//void setTime(double t)
//{
//    jclass craftRenderer=jniEnv->FindClass("com/x/craft2android/CraftRenderer");
//    jmethodID setTime=jniEnv->GetStaticMethodID(craftRenderer, "setTime", "(D)V");
//    jniEnv->CallStaticVoidMethod(craftRenderer, setTime, t);
//    jniEnv->DeleteLocalRef(craftRenderer);
//}

AAssetManager *nativeAssetManager;
void readFile(const char * filename,unsigned char * buffer)
{
    AAsset *asset=AAssetManager_open(nativeAssetManager,filename,AASSET_MODE_BUFFER);
    size_t len=AAsset_getLength(asset);
    AAsset_read(asset,buffer,len);
    AAsset_close(asset);
}

void getFileSize(const char * filename,size_t * size)
{
    AAsset *asset=AAssetManager_open(nativeAssetManager,filename,AASSET_MODE_BUFFER);
    size_t len=AAsset_getLength(asset);
    *size=len;
    AAsset_close(asset);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_x_craft2android_CraftRenderer_setNativeAssetManager(JNIEnv *env, jobject thiz,
                                                            jobject mng) {
    // TODO: implement setNativeAssetManager()
    nativeAssetManager= AAssetManager_fromJava(env,mng);
}