//
// Created by Administrator on 2019/3/3.
//

#include <iostream>
#include "Computer.h"

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

