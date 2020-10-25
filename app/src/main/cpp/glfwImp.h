//
// Created by ICEAGE on 2020/10/25.
//

#ifndef CRAFT2ANDROID_GLFWIMP_H
#define CRAFT2ANDROID_GLFWIMP_H
//#include "native-lib.h"
//typedef double (*GetTime)();
//
//typedef void (*SetTime)(double);
//extern GetTime gTime;
//extern SetTime sTime;

double glfwGetTime();
void  glfwSetTime(double t);
void addTime(double dt);
#endif //CRAFT2ANDROID_GLFWIMP_H
