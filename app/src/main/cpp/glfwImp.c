//
// Created by ICEAGE on 2020/10/25.
//
#include "glfwImp.h"
#include "native-lib.h"
//GetTime gTime=NULL;
//SetTime sTime=NULL;
double ___time=0;
double glfwGetTime()
{
    return ___time/1000;
}

void  glfwSetTime(double t)
{
    ___time=t*1000;
}

void addTime(double dt)
{
    ___time+=dt;
}