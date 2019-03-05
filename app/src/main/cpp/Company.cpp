//
// Created by Administrator on 2019/3/5.
//
#include <android/log.h>
#include "Company.h"

char *Company::getName() const {
    return name;
}

void Company::setName(char *name) {
    Company::name = name;
}

int Company::getAge() const {
    return age;
}

void Company::setAge(int age) {
    Company::age;
}

Company::~Company() {
    __android_log_print(ANDROID_LOG_INFO,"main","Company的析构函数");
}
