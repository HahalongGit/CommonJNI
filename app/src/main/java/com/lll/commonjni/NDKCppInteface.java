package com.lll.commonjni;

/**
 * Created by longlong on 2019/3/1.
 *
 * @ClassName: NDKCppInteface
 * @Description: jni 方法接口
 * @Date 2019/3/1
 */

public class NDKCppInteface {

    public native void executeCppConst();

    // 函数指针
    public native void executeCppFuncPointer();

    // C++ 中class 的定义
    public native  void executeCppClass();

}
