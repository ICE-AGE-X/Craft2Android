//
// Created by ICEAGE on 2020/10/25.
//

#ifndef CRAFT2ANDROID_NATIVE_LIB_H
#define CRAFT2ANDROID_NATIVE_LIB_H
#include <jni.h>
#include <android/log.h>
#define  LOG_TAG    "Craft2Android"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
//double getTime();
//void setTime(double t);
void readFile(const char * filename,unsigned char * buffer);
void getFileSize(const char * filename,size_t * size);
#endif //CRAFT2ANDROID_NATIVE_LIB_H
