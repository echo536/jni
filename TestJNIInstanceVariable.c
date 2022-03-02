#include <jni.h>
#include <stdio.h>
#include "TestJNIInstanceVariable.h"


JNIEXPORT void JNICALL Java_TestJNIInstanceVariable_modifyInstanceVariable (JNIEnv *env, jobject thisObj) {
	// 调用GetObjectClass()获得目标对象的类引用
	jclass thisClass = (*env)->GetObjectClass(env, thisObj);

	// 1. 获取实例变量number的域id
	jfieldID fidNumber = (*env)->GetFieldID(env, thisClass, "number", "I");
	if(NULL == fidNumber) {
		return;
	}
	// 2. 获取实例变量的值
	jint number = (*env)->GetIntField(env, thisObj, fidNumber);
	printf("In C, the int is %d\n", number);

	// 修改
	number = 99;
	(*env)->SetIntField(env, thisObj, fidNumber, number);
	


	// 字符串
	// 1. 获取fieldID
	// 提供这个变量的名字，变量的描述符（也称为签名）
	// 对于java类而言，描述符是这样的形式：“Lfully-qualified-name;”(注意最后有一个英文半角分号)，其中的包名点号换成斜杠(/)，比如java的String类的描述符就是“Ljava/lang/String;”
	// 对于基本类型而言，I代表int，B代表byte，S代表short，J代表long，F代表float，D代表double，C代表char，Z代表boolean
	// 对于array而言，使用左中括号”[“来表示，比如“[Ljava/lang/Objectj;”表示Object的array，“[I”表示int型的array
	jfieldID fidMessage = (*env)->GetFieldID(env, thisClass, "message", "Ljava/lang/String;");
	if(NULL == fidMessage) {
		return;
	}

	// 2. 通过fieldID获取字符串对象
	// 基于上面获得的Field ID，使用GetObjectField() 或者 Get_primitive-type_Field()函数来从中解析出我们想要的数据
	jstring message = (*env)->GetObjectField(env, thisObj, fidMessage);

	// 3. 获取获取字符串对象里的内容
	const char *cStr = (*env)->GetStringUTFChars(env, message, NULL);
	if(NULL == cStr) {
		return;
	}

	// 释放内存
	printf("In C, the string is %s\n", cStr);
	(*env)->ReleaseStringUTFChars(env, message, cStr);

	// 修改
	// 使用SetObjectField() 或者 Set_primitive-type_Field()函数来修改变量
	message = (*env)->NewStringUTF(env, "Hello from C");
	if(NULL == message) {
		return;
	}

	(*env)->SetObjectField(env, thisObj, fidMessage, message);
}