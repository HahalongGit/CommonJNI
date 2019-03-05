//
// Created by Administrator on 2019/3/3.
//
// 不能重复的include 头文件
#ifndef COMMONJNI_COMPUTER_H
#define COMMONJNI_COMPUTER_H

#include <iostream>
// C++ 的正规类的定义
using namespace std;// 使用标准命名空间
class Computer {

public:
    Computer(char *name, int age);

    Computer();

    ~Computer();// 析构函数声明

private:
    char *cpu;
    char *display;
    char *name;
    int age;;

public:

    /**
     * 提供一个友元函数重写 << 符号
     * @param out
     * @param computer
     */
    friend ostream &operator<<(ostream &out, Computer &computer);

    /**
     * 重写 （） 运算符 实现 括号内的数据相乘
     * @param a
     * @param b
     * @return
     */
    int operator()(int a, int b) {
        return a * b;
    }

    /**
     * 重写 != (不等于)运算符
     * @param computer
     * @return
     */
    int operator!=(Computer &computer) {
        int result = strcmp(this->name, computer.name);
        if (result != 0) {
            return 1;
        }
        if (this->age != computer.age) {
            return 1;
        }
        // 名称和age 都相等返回1 表示相等，0否则不相等 ，这里是不等于的重写，返回
        return 0;
    }

    char *getCpu();

    void setCPU(char *cpu);

    char *getDisplay();

    void setDisplay(char *display);

    int getAge();

    void setAge(int age);

    void setCpu(char *cpu);

    char *getName() const;

    void setName(char *name);

    //    char *getName();
//
//    void setName(char *name);

//

};

#endif //COMMONJNI_COMPUTER_H