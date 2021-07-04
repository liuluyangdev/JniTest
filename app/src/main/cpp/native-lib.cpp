#include <jni.h>
#include <string>
#include<android/log.h>

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "native-activity", __VA_ARGS__))
#define LOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN, "native-activity", __VA_ARGS__))

extern "C" JNIEXPORT jstring JNICALL
Java_com_test_jnitest_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_test_jnitest_MainActivity_callFromJNI(JNIEnv *env, jobject thiz) {
    // TODO: implement callFromJNI()
    LOGI("liuluyang from c++");
    std::string hello = "hi, jni";
    return env->NewStringUTF(hello.c_str());
}