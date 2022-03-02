#include <jni.h>
#include <stdio.h>
#include "TestJNIPrimitiveArray.h"

JNIEXPORT jdoubleArray JNICALL Java_TestJNIPrimitiveArray_sumAndAverage (JNIEnv *env, jobject thisObj, jintArray inJNIArray) {
	// 使用jint* GetIntArrayElements(JNIEnv *env, jintArray a, jboolean *iscopy)将jintarray转换成C的jint[]
	jint *inCArray = (*env)->GetIntArrayElements(env, inJNIArray, NULL);
	if(NULL == inCArray) {
		return NULL;
	}
	jsize length = (*env)->GetArrayLength(env, inJNIArray);

	// 计算
	jint sum = 0;
	int i;
	for(i = 0; i < length; i++) {
		sum += inCArray[i];
	}
	jdouble average = (jdouble)sum / length;
	(*env)->ReleaseIntArrayElements(env, inJNIArray, inCArray, 0);
	jdouble outCArray[] = {sum, average};

	// 使用jintArray NewIntArray(JNIEnv *env, jsize len)函数来分配一个len字节大小的空间
	jdoubleArray outJNIArray = (*env)->NewDoubleArray(env, 2);
	if(NULL == outJNIArray) {
		return NULL;
	}
	// 使用void SetIntArrayRegion(JNIEnv *env, jintArray a, jsize start, jsize len, const jint *buf)函数讲jint[]中的数据拷贝到jintArray中去
	(*env)->SetDoubleArrayRegion(env, outJNIArray, 0, 2, outCArray);

	return outJNIArray;
}