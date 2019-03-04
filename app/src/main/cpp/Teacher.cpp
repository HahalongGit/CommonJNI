//
// Created by Administrator on 2019/3/4.
//
#include <android/log.h>
#include "Teacher.h"

Teacher::Teacher(char *name) {
    {
        this->name = name;
        __android_log_print(ANDROID_LOG_INFO, "Main", "Teacher一个参数构造函数");
        __android_log_print(ANDROID_LOG_INFO, "Main", "Teacher无参构造函数name1:%p", name);
        __android_log_print(ANDROID_LOG_INFO, "Main", "Teacher无参构造函数name2:%s", name);
    }
}

~Teacher() {
    __android_log_print(ANDROID_LOG_INFO, "Main", "Teacher析构函数");
}


