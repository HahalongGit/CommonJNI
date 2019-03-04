package com.lll.commonjni;

/**
 * Created by longlong on 2019/3/1.
 *
 * @ClassName: NDKCppInteface
 * @Description: jni 方法接口
 * @Date 2019/3/1
 */

public class NDKCppInteface {

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

}
