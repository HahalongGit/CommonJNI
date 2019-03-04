//
// Created by Administrator on 2019/3/4.
//
#include <android/log.h>
#include "Student.h"


//Student::Student(char *name, char * headTeacher, char * objectTeacher) : name(name),headTeacher(headTeacher),objectTeacher(objectTeacher) {
//    this->name = name;
//    __android_log_print(ANDROID_LOG_INFO, "Main", "Student一个参数的构造函数");
//}

~Student() {
    __android_log_print(ANDROID_LOG_INFO, "Main", "Student析构函数");
}

char *Student::getName() const {
    return name;
}

void Student::setName(char *name) {
    Student::name = name;
}

const Teacher &Student::getHeadTeacher() const {
    return headTeacher;
}

void Student::setHeadTeacher(const Teacher &headTeacher) {
    Student::headTeacher = headTeacher;
}

const Teacher &Student::getObjectTeacher() const {
    return objectTeacher;
}

void Student::setObjectTeacher(const Teacher &objectTeacher) {
    Student::objectTeacher = objectTeacher;
}

Student::Student(char *name, const Teacher &headTeacher, const Teacher &objectTeacher) : name(name), headTeacher(
        headTeacher), objectTeacher(objectTeacher) {
    this->name = name;
    this->headTeacher = headTeacher;
    this->objectTeacher = objectTeacher;
}



