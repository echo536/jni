#include <jni.h>
#include <stdio.h>
#include "TestJNICallBackMethod.h"


JNIEXPORT void JNICALL Java_TestJNICallBackMethod_nativeMethod (JNIEnv *env, jobject thisObj) {
	jclass thisClass = (*env)->GetObjectClass (env, thisObj);


	// 1. 方法ID，methodID表示了实例中的某个方法的抽象。你需要提供这个方法的名字和签名信息，签名规则和变量类似
	// 签名的格式是这样的：(parameters)return-type
	jmethodID midCallBack = (*env)->GetMethodID(env, thisClass, "callback", "()V");
	if(NULL == midCallBack) {
		return;
	}
	printf("In C, callback Java's callback()\n");
	// 2. 基于上面我们获得的Method ID，调用_Primitive-type_Method() 或者 CallVoidMethod() 或者 CallObjectMethod()来调用这个方法。如果某个方法需要参数的话，就在后面跟上参数即可
	// 调用无参无返回值方法
	(*env)->CallVoidMethod(env, thisObj, midCallBack);


	jmethodID midCallBackStr = (*env)->GetMethodID(env, thisClass, "callback", "(Ljava/lang/String;)V");
	if(NULL == midCallBackStr) {
		return;
	}
	printf("In C, callback Java's called(String)\n");
	// 调用有参方法
	jstring message = (*env)->NewStringUTF(env, "Hello from C");
	(*env)->CallVoidMethod(env, thisObj, midCallBackStr, message);


	// 两个基本类型参数int，返回double类型
	jmethodID midCallBackAverage = (*env)->GetMethodID(env, thisClass, "callbackAverage", "(II)D");
	if(NULL == midCallBackAverage) {
		return;
	}
	jdouble average = (*env)->CallDoubleMethod(env, thisObj, midCallBackAverage, 2, 3);
	printf("In C, the average is %f\n", average);


	// 如果想要调用一个static方法的话，使用GetMethodID(), CallStatic_Primitive-type_Method(), CallStaticVoidMethod() 或者 CallStaticObjectMethod()
	// 返回字符串对象的静态方法
	jmethodID midCallBackStatic = (*env)->GetStaticMethodID(env, thisClass, "callbackStatic", "()Ljava/lang/String;");
	if(NULL == midCallBackStatic) {
		return;
	}
	jstring resultJNIStr = (*env)->CallStaticObjectMethod(env, thisClass, midCallBackStatic);
	const char *resultCStr = (*env)->GetStringUTFChars(env, resultJNIStr, NULL);
	if(NULL == resultCStr) {
		return;
	}
	printf("In C, the returned string is %s\n", resultCStr);
	(*env)->ReleaseStringUTFChars(env, resultJNIStr, resultCStr);
}
