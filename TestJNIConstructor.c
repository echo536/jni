#include <jni.h>
#include <stdio.h>
#include "TestJNIConstructor.h"

JNIEXPORT jobject JNICALL Java_TestJNIConstructor_getIntegerObject (JNIEnv *env, jobject thisObj, jint number) {
	// 获取Integer类
	jclass cls = (*env)->FindClass(env, "java/lang/Integer");

	// 获取构造器
	jmethodID midInit = (*env)->GetMethodID(env, cls, "<init>", "(I)V");
	if(NULL == midInit) {
		return NULL;
	}
	// 调用构造器来创建一个实例
	jobject newObj = (*env)->NewObject(env, cls, midInit, number);

	// 创建一个toString函数
	jmethodID midToString = (*env)->GetMethodID(env, cls, "toString", "()Ljava/lang/String;");
	if(NULL == midToString) {
		return NULL;
	}
	// 运行toString函数
	jstring resultStr = (*env)->CallObjectMethod(env, newObj, midToString);
	const char *resultCStr = (*env)->GetStringUTFChars(env, resultStr, NULL);
	printf("In C: the number is %s\n", resultCStr);

	return newObj;
}