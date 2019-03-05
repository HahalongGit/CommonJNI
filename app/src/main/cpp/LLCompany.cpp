//
// Created by Administrator on 2019/3/5.
//
#include <android/log.h>
#include "LLCompany.h"

char *LLCompany::getDescription() const {
    return description;
}

void LLCompany::setDescription(char *description) {
    LLCompany::description = description;

}

LLCompany::LLCompany(char *name, char *description) : Company(name){//, description(description)
    this->name = name;
    this->description = description;
}

//LLCompany::LLCompany(char *name, char *description) : Company(name){//Company(name) 表示调用父类的构造方法初始化
//    this->description = description;
//}



//LLCompany::~LLCompany() {
//    __android_log_print(ANDROID_LOG_INFO, "main", "LLCompany析构函数");
//}

//void LLCompany::toString() {
//    __android_log_print(ANDROID_LOG_INFO, "main", "公司的名称是：%s", getDescription());
//}