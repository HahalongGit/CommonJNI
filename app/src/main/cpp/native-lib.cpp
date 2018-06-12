#include <jni.h>
#include <string>
//#include "jni/com_lll_commonjni_utils_JNIUtils.h"

extern "C"
JNIEXPORT jstring JNICALL
Java_com_lll_commonjni_utils_JNIUtils_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
