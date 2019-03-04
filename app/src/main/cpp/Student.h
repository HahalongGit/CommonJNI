//
// Created by Administrator on 2019/3/4.
//

#include "Teacher.h"


#ifndef COMMONJNI_STUDENT_H
#define COMMONJNI_STUDENT_H

class Student {
private:
    char *name;
    Teacher headTeacher;// 班主任
    Teacher objectTeacher;// 任课老师
public:
    Student(char *name);

    Student(char *name, const Teacher &headTeacher, const Teacher &objectTeacher);

//    Student(char *name) :headTeacher(""),objectTeacher("");

    Student();

    char *getName() const;

    void setName(char *name);

    const Teacher &getHeadTeacher() const;

    void setHeadTeacher(const Teacher &headTeacher);

    const Teacher &getObjectTeacher() const;

    void setObjectTeacher(const Teacher &objectTeacher);

};

#endif //COMMONJNI_STUDENT_H