#include <jni.h>
#include <stdio.h>
#include "TestJniPrimitive.h"


JNIEXPORT jdouble JNICALL Java_TestJNIPrimitive_average (JNIEnv *env, jobject thisOb, jint n1, jint n2) {
	jdouble result;

	printf("In C, the numbers are %d and %d\n", n1, n2);
	result = ((jdouble)n1 + n2) / 2.0;

	return result;
}
