//
// Created by Administrator on 2019/3/5.
//

#ifndef COMMONJNI_COMPANY_H
#define COMMONJNI_COMPANY_H

class Company {

public:
    int age;// 公有属性
    char *name; // 私有属性
public:
    Company(char *name) {
        this->name = name;
    }

    ~Company();

    Company() {}


    char *getName() const;

    void setName(char *name);

    int getAge() const;

    void setAge(int age);
};

/**
 * ：冒号表示继承
 */
class DiguaCompany : Company {

};

/**
 * C++ 可以多继承
 */
class DgSoftWareCompany : DiguaCompany, private Company {


};

// 修饰符
// private  当前类访问
// protected 当前类和子类访问
//public 所有的类访问
// 属性修饰符和继承修饰符，继承修饰符表示类的关系，属性修饰符表示属性的关系，属性是private的子类也不能访问
// java 中父类的引用可以指向子类的对象，C++中
#endif //COMMONJNI_COMPANY_H
