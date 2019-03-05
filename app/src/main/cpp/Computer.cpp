//
// Created by Administrator on 2019/3/3.
//

#include <android/log.h>
#include "Computer.h"

void Computer::setCpu(char *cpu) {
    Computer::cpu = cpu;
}

// C++ 中定义class 实现
void Computer::setCPU(char *cpu) {
    this->cpu = cpu;
}

char *Computer::getCpu() {
    return this->cpu;
}

void Computer::setDisplay(char *display) {
    this->display = display;
}

char *Computer::getDisplay() {
    return this->display;
}

void Computer::setAge(int age) {
    this->age = age;
}

int Computer::getAge() {
    return this->age;
}

char *Computer::getName() const {
    return name;
}

void Computer::setName(char *name) {
    Computer::name = name;
}
//char * Computer::getName() {
//    return this->name;
//}
//
//void Computer::setName(char *name) {
//    this->name = name;
//}

/**
    * 重写 （） 运算符 实现 括号内的数据相乘
    * @param a
    * @param b
    * @return
    */
//int operator()(int a, int b) {
//    return a * b;
//}

Computer::Computer() {
    __android_log_print(ANDROID_LOG_INFO, "main", "Computer的构造函数执行！");
}


Computer::~Computer() {
    __android_log_print(ANDROID_LOG_INFO, "main", "Computer的析构函数执行,释放对象和内存！");
}

Computer::Computer(char *name, int age) : name(name), age(age) {
    this->name = name;
    this->age = age;
}
// 重载的 运算符方法直接在.h文件中实现，
// Cpp文件中报错：Error:(76, 5) error: overloaded 'operator()' must have at least one parameter of class or enumeration type
//int operator()(int a, int b) {
//    return a * b;
//}



