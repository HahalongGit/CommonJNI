/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
#include <android/log.h>
#include "com_lll_commonjni_NDKCppInteface.h"
#include "Student.h"
#include <iostream>
/* Header for class com_lll_commonjni_NDKCppInteface */


/*
 * Class:     com_lll_commonjni_NDKCppInteface
 * Method:    executeCppConst C++ 方式编写jni代码
 * Signature: ()V
 */
using namespace std;// 标准命名空间
extern "C"
JNIEXPORT void JNICALL Java_com_lll_commonjni_NDKCppInteface_executeCppConst
        (JNIEnv *env, jobject jobj) {
    const int a = 100;
    //    a = 200;  // 常量不能修改
    // 间接修改
    int *p = (int *) &a;
    *p = 200;
    __android_log_print(ANDROID_LOG_INFO, "main", "修改值：%d", a);// 采用andorid 的底层日志方式
    //指针修改的方式结果：100  结论，在C++ 中常量是不能修改的 ,在C语言中是可以修改的，但是和编译的环境有关系，Android 中都不能修改，VisualStudia 中可以修改C的常量

}

//int get_min(int a, int b) {
//    return a < b ? a : b;
//}

int get_min(int a, int b, int c, int d) {
    return a < b ? a : b;
}

typedef int(*GET_MIN_P)(int, int, int, int);// 为了方便给方法取别名 函数指针别名

JNIEXPORT void JNICALL Java_com_lll_commonjni_NDKCppInteface_executeCppFuncPointer
        (JNIEnv *, jobject) {
    //函数指针
//    int(* get_min_p) (int,int) = get_min;
//    int c = get_min(10,20);

    GET_MIN_P p = get_min;
    int c = p(10, 20, 30, 40);
    __android_log_print(ANDROID_LOG_INFO, "main", "最小值：%d", c);
}


//class Computer {
//private:
//    char *cpu;
//    char *display;
//    char *name;
//    int age;

// 自动生成的 get set 方法
//public:
//    char *getCpu() const {
//        return cpu;
//    }
//
//    void setCpu(char *cpu) {
//        Computer::cpu = cpu;
//    }
//
//    char *getName() const {
//        return name;
//    }
//
//    void setName(char *name) {
//        Computer::name = name;
//    }

//public:
//    void setCPU(char *cpu) {
//        this->cpu = cpu;
//    }
//
//    char *getCPU() {
//        return this->cpu;
//    }
//
//    void setDisplay(char *display) {
//        this->display = display;
//    }
//
//    char *getDisplay() {
//        return this->display;
//    }
//
//    void setAge(int age) {
//        this->age = age;
//    }
//
//    int getAge() {
//        return this->age;
//    }
//
//};
/**
 * C++ 中类的定义
 */
//#include "Computer.h" // 全局类的定义，引用的时候引入头文件执行
#include "Computer.h" // 这里的Cpp 实现类表示没有添加道编译工具中，直接添加头文件报错，添加实现Cpp类可以执行
#include "Student.h"
#include "Teacher.h"

JNIEXPORT void JNICALL Java_com_lll_commonjni_NDKCppInteface_executeCppClass
        (JNIEnv *, jobject) {
//    Computer computer; // 创建对象 可以不用 new
//    computer.setAge(5);
//    computer.setCPU("i7770HQ");
//    computer.setDisplay("2G独立显卡");
//    __android_log_print(ANDROID_LOG_INFO, "main", "显卡4：%s,CPU：%s,年龄：%d", computer.getDisplay(),
//                        computer.getCpu(), computer.getAge());
    // 上面的这种方式 析构函数执行，下面的new 的方式 析构函数不执行？？？ new 关键字创建的对象 要手动释放内存才会执行

//    Computer computer1 = new Computer();//Types 'Computer' and 'Computer *' are not compatible 这样的写法类型不兼容

    Computer *computer = new Computer(); /// 可以new 一个对象 传递 对象的 引用（指针地址）
    computer->setDisplay("2G独立显卡");
    computer->setCPU("i7770hq");
    computer->setAge(4);
    __android_log_print(ANDROID_LOG_INFO, "main", "显卡4：%s,CPU：%s,年龄：%d", computer->getDisplay(),
                        computer->getCpu(), computer->getAge());
    delete computer; // 手动释放内存 析构函数会执行

}

/**
 * 浅拷贝和深拷贝
 */
JNIEXPORT void JNICALL Java_com_lll_commonjni_NDKCppInteface_executeCppCopy
        (JNIEnv *env, jobject jobj) {
    // 1.系统默认的就是浅拷贝 值
    // 浅拷贝默认拷贝的是值，如果是引用则拷贝引用地址 ，如果拷贝后去释放两个对象的内存，就会出错，第二次释放的是一个无效的对象
    //
    Computer computer("北京地铁", 80);
    __android_log_print(ANDROID_LOG_INFO, "main", "name:%s--age:%d", computer.getName(),
                        computer.getAge());
    // 2.深拷贝
    //开辟一块内存区域在堆中，结果对应两个对象 ，两次释放两个对象
}


// 对象属性的初始化
// 在创建C++ 的类中 添加一个对象的属性会报错，这个对象的属性必须要初始化..
// 初始化的方式：(语法规定)
// 1.对应提供对象的类添加无参数的构造方法
// 2.提供对象属性的这个对象添加一个默认的值 或者在属性创建的时候直接创建这个对象
JNIEXPORT void JNICALL Java_com_lll_commonjni_NDKCppInteface_initObjectAttribute
        (JNIEnv *env, jobject jobj) {
    //
//    Teacher teacher1 =  Teacher("龙龙班主任");// Teacher *teacher1 = Teacher("龙龙班主任");  这种方式也不对
//    Teacher teacher2 =  Teacher("天翔老师");
//    Student student = Student("sisi");
//    Student student = Student("陈国军", teacher1, teacher2);// 注意，和java中初始化对象属性不同
    // 上述初始化的代码报错。检测不到错误所在...
}


// C++ 中new 关键字和 delete 关键字的使用
// 基本数据类型要 用new
// int *p = new int[10];
// 释放内存 delete [] p;// 或者 free(p)

// 对象的创建和释放
// *** Teacher teacher = Teacher();// 这种方式开辟的是栈内存 自动管理
// Teacher *teacher = new Teacher(); // 开辟的是堆内存 手动释放
// teacher->.setName("刘老师");
// free(teacher); //delete teacher;  //new 关键字创建的对象要手动释放才会调用析构函数


// static 关键字
//
#include "StaticClass.h"
//StaticClass
JNIEXPORT void JNICALL Java_com_lll_commonjni_NDKCppInteface_executeStaticKey
        (JNIEnv *, jobject) {
    StaticClass staticClass = StaticClass("dream");
    //staticClass.age = 100; //静态属性能不能赋值？ 编译报错
}

// 指针和 引用的区别（什么时候用指针，什么时候用引用？）
extern "C"
JNIEXPORT void JNICALL Java_com_lll_commonjni_NDKCppInteface_callCppPointerAndRefDiff
        (JNIEnv *, jobject) {
    // 指针和引用：
    //1.指针是内存地址，引用只是内存地址的别名，并且程序要为指针变量分配内存，引用不需要分配内存区域
//    int a = 100;
//    int &b = a; // b是a的引用
//    int *p = &a;// p是a的指针
//    __android_log_print(ANDROID_LOG_INFO, "main", "引用b的地址%p", &b);
//    __android_log_print(ANDROID_LOG_INFO, "main", "变量a的地址%p", &a);
//    __android_log_print(ANDROID_LOG_INFO, "main", "指针p的地址%p", &p);
    // 结果是：
    //    03-05 10:27:04.255 30582-30582/com.lll.commonjni I/main: 引用b的地址0xffb540a8
    //    03-05 10:27:04.255 30582-30582/com.lll.commonjni I/main: 变量a的地址0xffb540a8
    //    03-05 10:27:04.255 30582-30582/com.lll.commonjni I/main: 指针p的地址0xffb540a4

    //2.引用在使用的时候不需要*接引用，但是指针需要解引用
//    int a = 100;
//    int &b = a; // b是a的引用
//    int *p = &a;// p是a的指针
//    __android_log_print(ANDROID_LOG_INFO, "main", "变量a的地址%p", a);// 直接写a 结果就是a的值
//    __android_log_print(ANDROID_LOG_INFO, "main", "指针p的地址%p", &p);// a 的值需要 【*p】才能获取到 ，这就是使用*解引用，p是指针是不能直接打印的

    //3.引用只能被初始化一次，之后不能再更改信息，但是指针可以
//    int a = 100;
//    int b = 200; // b是a的引用
//    int &c = a;
//    int *p = &a;// p是a的指针
//    &c = b; // 这种写法是错误的，不能修改赋值
//    p = &b; // 指针可以修改重新赋值，指向b的内存地址

    // 4.引用不能为NULL,指针可以
//    int a = 100;
//    int b = 200; // b是a的引用
//    int &c = NULL;// 这写法是错误的
//    int *p = NULL;// p可以是一个NULL

    // 5.sizeof(引用)得到的是引用所指向的变量的大小，sizeof(指针)得到的是指针本身的大小
//    double a = 100;
//    double &b = a;
//    double *p = &a;// p是a的指针
//    __android_log_print(ANDROID_LOG_INFO,"main","b引用的大小：%d", sizeof(b));//引用的大小，引用是值本身的大小 是double 类型的，占8字节
//    __android_log_print(ANDROID_LOG_INFO,"main","p指针的大小:%d", sizeof(p));// 指针的大小，指针本身是一个地址，地址是int 类型的占4个字节
    // 6.指针（++ 或者-- ）代表的是地址的位移，引用实际上对应值的改变
    int a = 100;
    int &b = a;
    int *p = &a;
    __android_log_print(ANDROID_LOG_INFO, "main", "p++前p指针的值:%p", p);// 打印地址
    b++;
    p++;
    __android_log_print(ANDROID_LOG_INFO, "main", "b引用的大小:%d", b);// 打印值
    __android_log_print(ANDROID_LOG_INFO, "main", "p++后p指针的值:%p", p);// 打印地址
    // 结果：
//    03-05 11:51:12.800 13912-13912/com.lll.commonjni I/main: p++前p指针的值:0xffb540a8
//    03-05 11:51:12.800 13912-13912/com.lll.commonjni I/main: b引用的大小:101
//    03-05 11:51:12.800 13912-13912/com.lll.commonjni I/main: p++后p指针的值:0xffb540ac
    // 指针p++ 后的结果可能已经是一个未知的数据了，也可能报错

//    cout<< ""<<endl; // 输出运算符

}

// 输出函数，重载输入输出运算符: <<
//    cout<< ""<<endl; // 输出运算符

//    ostream 是 系统 iostream 的属性，我们不能在其他类中访问，提供一个友元函数解决
// 当我们无法给已经存在的类添加成员函数的时候，可以采用友元函数。这里不能访问 iostream 中的ostream属性 提供友元函数
ostream &operator<<(ostream &out, Computer &computer) {
    // 实例 Computer 类中提供了友元函数 重写C++ 输出付 << ，这里（在外部类中）实现这个友元函数
    // 输出对象computer -->>相当于java 中重写toString();
//    out<<"computer对象的值Name："<<computer.getName()<<"--age:"<<computer.getAge()<<endl; // 在Vsual studio 中输出的方式 android 中不能这样
    __android_log_print(ANDROID_LOG_INFO, "main", "重写operator<< 操作付友元函数输出"); // 只能是android 的方式输出
    return out; // 返回引用
}
/**
 * 运算符操作 （+，-, * ,/, ++ ,-- ,= , << ,() ，!= >,<）
 * 不可以重载的运算符：.：成员访问运算符；,；->：成员指针访问运算符；:域运算符；sizeof：长度运算符；?:：条件运算符#
 *
 * */
JNIEXPORT void JNICALL Java_com_lll_commonjni_NDKCppInteface_callCppOperator
        (JNIEnv *, jobject) {
    Computer computer = Computer("联系小新", 5);
    cout << computer; // 重写了输出符号 << 后就可以输出对象了
    // 连续打印异常
//    cout<<computer<<computer; // 给<< 的重写方法添加返回值，获取输入输出对象
    cout << computer << computer; // 调用两次输出符号
}

extern "C"
JNIEXPORT void JNICALL Java_com_lll_commonjni_NDKCppInteface_callCppBackets
        (JNIEnv *, jobject) {
    Computer computer = Computer("联想G480", 6);
    int sum = computer(10,
                       205);// 重载 了（）运算符后的调用，这里computer(10, 205) 不是一个构造方法，是Computer 类头文件中申明的括号运算符
    __android_log_print(ANDROID_LOG_INFO, "main", "重写的（）运算符结果是：%d", sum);
}

/**
 * 继承 和初始化父类属性
 */
#include "LLCompany.h"

JNIEXPORT void JNICALL Java_com_lll_commonjni_NDKCppInteface_callCppextends
        (JNIEnv *, jobject) {
//    LLCompany llCompany = LLCompany("地瓜科技有限公司", "一家生产地瓜的公司");
//    llCompany.toString();
    // 子类和父类分开写 执行报错 //Error:(291) undefined reference to 'LLCompany::LLCompany(char*, char*)'
}


//***********************************************分割线*******************************************************//
// 方法的重写
// 父类提供一个方法，子类重写同样的方法
// 调用方法不同于java
// 子类对象.父类名称:方法名称();// 子类必须继承修饰符为public 的父类

//***********************************************分割线*******************************************************//
//多继承
// 问题：A类有一个属性 name,类有一个属性name,C类继承了A和B类，这时候C类有两个name属性，如何区别这两个name?
// 解决方案：采用虚继承
// 关键字：virtual  采用这个关键字表示多继承 解决了不同路径继承来的同名属性 添加了这个关键字在内存中会合并两个名字的
// 内存，两个父类通用一个name，不会再有歧义，不会报错
//
// 多继承的虚函数
// 多继承除了面对不同父类的同一个属性的问题，还有不同父类的同一个父类方法问题，也是没有办法区别
// 采用虚函数的方式实现
// 什么是多态？写一个案例说明！
// 静态多态：很多类，对应一个管理Mananger 类，通过子类传递对象的方式，调用公用的方法。（问题，一个子类就要重复同样的方法，占用多余空间）
// 虚函数：定义函数的时候函数中添加关键字virtual，子类重写父类的方法也添加virtual 关键字 。
// （一个类添加了虚函数，这个对象的大小不再是属性的大小，原因：添加了virtual 修饰关键字后，对象会多一个指针，这个指针指向对象的虚函数的集合，虚函数表包含了对象中
// 所有的虚函数的指针。也就是这个对象的大小增加了4个字节）
// 调用的时候就可以像java一样采用父类【引用】调用子类的方法
// 这样我们就不需要改业务类，是需要提供实现类。
// 动态多态：程序再编译的阶段并不知道要执行的目标函数，二十等到运行的时候才指定目标函数，这就是动态多态。（基于继承）
//***********************************************分割线*******************************************************//

// 纯虚构函数（C++ 中的抽象类）

int getMin(int a, int b) {
    __android_log_print(ANDROID_LOG_INFO, "main", "重载函数案例");
    return a * b;
}

template<typename T>
T getMin(T a, T b) {
    __android_log_print(ANDROID_LOG_INFO, "main", "函数模板案例");
    return a < b ? a : b;
}

JNIEXPORT void JNICALL Java_com_lll_commonjni_NDKCppInteface_callCppAbstractClass
        (JNIEnv *, jobject) {
//    __android_log_print(ANDROID_LOG_INFO, "main", "纯虚构函数案例");
    // 定义：一般的虚函数子类不去实现也不会报错。纯虚函数子类不实现，会报错
    // class A{
    //    public :
    //           void salary() = 0;  虚函数定义
    // }
    // 子类必须实现这个方法
    // C++ 中的【接口】 可以采用纯虚函数模拟--》 把类中的方法全部申明为virtual 就相当于接口

    int result = getMin(100, 23);
    __android_log_print(ANDROID_LOG_INFO, "main", "模板函数案例：%d", result);

    // C++ 类中有一个模板方法和一个普通方法 同名的时候（getMin方法），程序默认先调用普通方法，普配不上再去调用模板方法。
    // 模板函数原理：
    // 编译过程：（上述方法的编译过程）
    // 1.编译成预处理文件（后缀名.i）
    // 2.转成汇编文件（后缀名.s文件）
    // 3.专成目标文件（后缀名.o文件）
    // 4.链接生成目标文件（可执行文件）
}

//模板类的创建：
//typename  约等于 class
//
//template<typename T>
template<class T>
class BaseDao {
private:
    T t;
public:
    BaseDao(T t) {
        this->t = t;
    }
};

class UserDao : public BaseDao<int> {// :表示继承，类似java 中类泛型
public :
    UserDao(int a) : BaseDao<int>(a) {// 子类调用了父类的构造
        // 模板类的创建
    }
};

// 父类是模板类，子类也是模板类，该怎么做？
// 子类也要申明他的类型 比如申明是 T
template<class T>
class TeacherDao : public BaseDao<T> {// :表示继承，类似java 中类泛型
public :
    TeacherDao(T value) : BaseDao<T>(value) {// 子类调用了父类的构造，传递参数value
        // 模板类的创建
    }
};

class TechnologyTeacherDao : TeacherDao<double> {
public :
    TechnologyTeacherDao(double salory) : TeacherDao<double>(salory) {
        // 子类模板类的实现
    }
};

//***********************************************分割线*******************************************************//

//函数指针作为函数参数传递
//1.函数的别名方式实现
int getMax(int a, int b) {
    __android_log_print(ANDROID_LOG_INFO, "main", "重载函数案例");
    return a > b ? a : b;
}

// 定义函数指针别名
typedef int(*get_max_p)(int a, int b);

/**
 * 函数指针作为函数参数
 * @param p
 */
void biz(get_max_p p) {
    int result = p(102, 345);
    __android_log_print(ANDROID_LOG_INFO, "main", "函数指针的【别名】作为函数参数传递result：%d", result);
}

// 直接使用 函数指针 作为参数使用
//void biz2(int(*get_max_p)(int a, int b), int a,int b) { // get_max_p
void biz2(int(*p)(int a, int b), int a, int b) {
//    int result = get_max_p(102, 345);
    int result = p(a, b);
    __android_log_print(ANDROID_LOG_INFO, "main", "函数指针作为函数参数传递result：%d", result);
}
/**
 * 函数指针作为函数参数
 */
JNIEXPORT void JNICALL Java_com_lll_commonjni_NDKCppInteface_callFuncPointer
        (JNIEnv *, jobject) {
    get_max_p p = getMax;// 函数指针
    int result = p(100, 253);
    biz(getMax);// 指针参数
    biz(p);
//    biz2(p,142,256);
    biz2(getMax, 142, 256);
}

// 注意：函数指针 结合模板类不能使用 不能定义template 模板 作为参数

//***********************************************分割线*******************************************************//

//typename  约等于 class
//模板类结合方法的重载
// 重写 运算符（+，-，*，/等）
//1.
// 这种定义只能再当前的方法中使用
template <typename T>
class BaseDao1 {
private:
    T t;
public:
    BaseDao1(T t) {
        this->t = t;
    }
};

//class BaseDao2{
//private:
//    T t; // 报错了
//};

//2.实现和申明分开
// 如果你的类为模板类或者模板函数
// 如果申明（之定义方法名没有方法体）和实现类（方法体实现）在不同的文件，那么在使用的时候，需要引入实现类，不能引入头文件。
// 上述写法有可能不成立报错，根据编译器情况。不推荐遮掩分开写 引入头文件的方式。
// .h文件和.cpp文件合并 为.hpp文件

