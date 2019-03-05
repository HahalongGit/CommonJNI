package com.lll.commonjni;

/**
 * Created by longlong on 2019/3/1.
 *
 * @ClassName: NDKCppInteface
 * @Description: jni 方法接口
 * @Date 2019/3/1
 */

public class NDKCppInteface  {

    /**
     * C++ 常量
     */
    public native void executeCppConst();

    /**
     * 函数指针 操纵
     */
    public native void executeCppFuncPointer();

    /**
     * C++ 中class 的定义
     */
    public native  void executeCppClass();

    /**
     * 浅拷贝和深拷贝
     */
    public native void executeCppCopy();

    /**
     * 初始化对象属性
     */
    public native void initObjectAttribute();

    /**
     * 静态关键字
     */
    public native void executeStaticKey();

    /**
     * 指针和引用
     */
    public native void callCppPointerAndRefDiff();

    /**
     * C++ 中的运算符 和 重载 重写
     */
    public native void callCppOperator();

    /**
     * () 运算符重写
     */
    public native void callCppBackets();

    /**
     * 继承关系，初始化父类属性
     */
    public native void callCppextends();

}
