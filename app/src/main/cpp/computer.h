//
// Created by Administrator on 2019/3/3.
//

// 不能重复的include 头文件
#ifndef COMMONJNI_COMPUTER_H
#define COMMONJNI_COMPUTER_H


// C++ 的正规类的定义
class Computer {

public:
    Computer(char *name, int age);

    Computer();

    ~Computer();// 析构函数声明

private:
    char *cpu;
    char *display;
    char *name;
    int age;


public:
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

};

#endif //COMMONJNI_COMPUTER_H