//
// Created by Administrator on 2019/3/4.
//

#ifndef COMMONJNI_STATICCLASS_H
#define COMMONJNI_STATICCLASS_H

class StaticClass {

private:
    char *name;

public:
    static int age;

    StaticClass(char *name);

    ~StaticClass();
};

#endif //COMMONJNI_STATICCLASS_H
