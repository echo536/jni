#include <jni.h>
#include <stdio.h>
#include "TestJNIString.h"

// JNI环境指针JNIEnv *已经为我们定义了非常丰富的接口函数用来处理数据的转换
JNIEXPORT jstring JNICALL Java_TestJNIString_sayHello (JNIEnv *env, jobject thisObj, jstring inJNIStr) {
	// 从java发来的字符串
	// 调用const char* GetStringUTFChars(JNIEnv*, jstring, jboolean*)来将JNI的jstring转换成C的char *
	// 第三个函数是isCopy，传进一个指针，如果内容是JNI_TRUE，代表返回的数据是jstring数据的拷贝。	
	// 如果是JNI_FALSE，则代表返回的字符串是直接指向哪个String对象实例的。这时修改本地内容会一起修改java中的内容
	// 用完字符串后必须调用ReleaseStringUTFChars()来释放内存，否则会内存泄漏，且上层java中的GC也不能进行
	const char *inCStr = (*env)->GetStringUTFChars(env, inJNIStr, NULL);
	// 如果系统的内容分配失败的话，这个函数会返回NULL。因此，最好检查返回的是不是NULL
	if (NULL == inCStr) {
		return NULL;
	}

	printf("In C, the received string is: %s\n", inCStr);

	// 发送给java的字符串
	char outCStr[128];
	printf("Enter a String: ");
	scanf("%s", outCStr);

	// 调用jstring NewStringUTF(JNIEnv*, char*)来将C的char *转换成JNI的jstring
	return (*env)->NewStringUTF(env, outCStr);
}