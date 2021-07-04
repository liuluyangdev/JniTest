//
// Created by qliul on 2021/7/4.
//

#include "hello-lib.h"
#include <jni.h>
#include <string>
#include<android/log.h>

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "native-activity", __VA_ARGS__))

extern "C"
JNIEXPORT jstring JNICALL
Java_com_test_jnitest_JniTest_callFromHelloJNI(JNIEnv *env, jobject thiz) {
    // TODO: implement callFromHelloJNI()
    LOGI("liuluyang from callFromHelloJNI");
    std::string hello = "callFromHelloJNI--jni";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT void JNICALL
Java_com_test_jnitest_JniTest_callStaticMethod(JNIEnv *env, jobject thiz) {
    // TODO: implement callStaticMethod()
    //调用java的static方法 start
    jclass cls_hello = env->FindClass("com/test/jnitest/JniTest");
    if (cls_hello == NULL) {
        return;
    }
    jmethodID mtd_static_method = env->GetStaticMethodID(cls_hello, "staticMethod", "(Ljava/lang/String;)V");
    if (mtd_static_method == NULL) {
        return;
    }

    //修改java类中的静态成员变量 start
    jfieldID fid_name = env->GetStaticFieldID(cls_hello,"name","Ljava/lang/String;");
    if (fid_name == NULL) {
        return;
    }
    jstring name = env->NewStringUTF("tom");
    env->SetStaticObjectField(cls_hello,fid_name,name);
    //修改java类中的静态成员变量 end

    jstring date = env->NewStringUTF("call static method");
    env->CallStaticVoidMethod(cls_hello,mtd_static_method,date);
    //调用java的static方法 end

    env->DeleteLocalRef(cls_hello);
    env->DeleteLocalRef(date);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_test_jnitest_JniTest_callInstanceMethod(JNIEnv *env, jobject thiz) {
    // TODO: implement callInstanceMethod()
    jclass cls_hello = env->FindClass("com/test/jnitest/JniTest");
    if (cls_hello == NULL) {
        return;
    }
    jmethodID mtd_method = env->GetMethodID(cls_hello,"method","(Ljava/lang/String;)V");
    if (mtd_method == NULL) {
        return;
    }
    jmethodID mtd_construct = env->GetMethodID(cls_hello,"<init>","()V");
    if (mtd_construct == NULL) {
        return;
    }
    jobject hello = env->NewObject(cls_hello,mtd_construct,NULL);

    jstring message = env->NewStringUTF("Call instance method");

    env->CallVoidMethod(hello,mtd_method,message);

    env->DeleteLocalRef(cls_hello);
    env->DeleteLocalRef(message);
    env->DeleteLocalRef(hello);

}