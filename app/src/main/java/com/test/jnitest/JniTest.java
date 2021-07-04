package com.test.jnitest;

import android.util.Log;

/**
 * 作者：qliuluyang@qq.com
 * 日期：2021/7/4
 *
 * class路径：C:\Users\qliul\AndroidStudioProjects\JNITest\app\build\intermediates\javac\debug\classes\com\test\jnitest
 */
public class JniTest {
    private static final String TAG = "JniTest";

    public static String name = "Cook";
    
    static {
        System.loadLibrary("hello-lib");
    }

    public native String callFromHelloJNI();
    public native void callStaticMethod();
    public native void callInstanceMethod();


    /**
     * jni调用java静态方法
     * @param date
     */
    public static void staticMethod(String date) {
        Log.d(TAG, "staticMethod--date: " + date);
        Log.d(TAG, "staticMethod--name: " + name);
    }

    public void method(String date) {
        Log.d(TAG, "method: " + date);
    }
}
