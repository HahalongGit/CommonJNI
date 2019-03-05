//
// Created by Administrator on 2019/3/5.
//

#ifndef COMMONJNI_LLCOMPANY_H
#define COMMONJNI_LLCOMPANY_H

#include "Company.h"

/**
 * LLCompany 子类继承父类
 */
class LLCompany : public Company {

public:
    char * description;

public:

//    LLCompany(char *description);



    LLCompany(char *name, char *description);

    char *getDescription() const;

    void setDescription(char *description);

    void toString() {
        __android_log_print(ANDROID_LOG_INFO, "main", "公司的名称是：%s", getDescription());
    }

    ~LLCompany(){
        __android_log_print(ANDROID_LOG_INFO,"main","Company的析构函数");
    }

};

#endif //COMMONJNI_LLCOMPANY_H
