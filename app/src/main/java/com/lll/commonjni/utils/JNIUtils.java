package com.lll.commonjni.utils;

/**
 * Created by longlong on 2018/6/12.
 *
 * @ClassName: JNIUtils
 * @Description:
 * @Date 2018/6/12
 */

public class JNIUtils {

    // Used to load the 'native-lib' library on application startup.
    //加载生成的so 库
    static {
        System.loadLibrary("native-lib");
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     * 声明native 方法
     */
    public native String stringFromJNI();

}
