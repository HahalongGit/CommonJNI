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

Computer::Computer() {}

Computer::Computer(char *name, int age) : name(name), age(age) {
    this->name = name;
    this->age = age;
}



