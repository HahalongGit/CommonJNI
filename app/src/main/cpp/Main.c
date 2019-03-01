//
// Created by Administrator on 2019/2/28.
//

#include <jni.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

JNIEXPORT jstring JNICALL Java_com_lll_commonjni_utils_JNIUtils_stringFromJNI
        (JNIEnv *env, jobject jobj) {
    return (*env)->NewStringUTF(env, "C处理数据到Java端");
}