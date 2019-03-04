//
// Created by Administrator on 2019/3/4.
//
#include "StaticClass.h"
#include <iostream>
#include <android/log.h>


StaticClass::StaticClass(char *name) : name(name) {
    this->name = name;
}

StaticClass::~StaticClass() {
    __android_log_print(ANDROID_LOG_INFO, "Main", "StaticClass析构函数");
}