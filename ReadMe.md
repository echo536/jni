### 1 开始：[HelloJNI](HelloJNI.java)
### 2 在java代码和Native代码之间传递参数返回值
- 2.1 传递基本类型：[TestJNIPrimitive](TestJNIPrimitive.java)
- 2.2 传递字符串：[TestJNIString](TestJNIString.java)
- 2.3 传递基本类型的数组：[TestJNIPrimitiveArray](TestJNIPrimitiveArray.java)
### 3 访问Java对象变量和回调Java方法
- 3.1 访问Java对象实例的变量：[TestJNIInstanceVariable](TestJNIInstanceVariable.java)
- 3.2 访问类中的static变量：[TestJNIStaticVariable](TestJNIStaticVariable.java)
- 3.3 回调实例的普通和static方法：[TestJNICallBackMethod](TestJNICallBackMethod.java)
- 3.4 回调复写的父类实例对象：[TestJNIObjectArray](TestJNIObjectArray.java)
>1. 首先获得Method ID，使用GetMethodID()
>2. 基于上获得的Method ID，通过调用 CallNonvirtual_Type_Method()函数来调用相应的方法，并且在参数中给出object，父类和参数列表。
```
NativeType CallNonvirtual<type>Method(JNIEnv *env, jobject obj, jclass cls, jmethodID methodID, ...);
NativeType CallNonvirtual<type>MethodA(JNIEnv *env, jobject obj, jclass cls, jmethodID methodID, const jvalue *args);
NativeType CallNonvirtual<type>MethodV(JNIEnv *env, jobject obj, jclass cls, jmethodID methodID, va_list args);
```
### 4 创建Object和Object arrays
- 4.1 回调Java构造器来创建一个新的java对象：[TestJNIConstructor](TestJNIConstructor.java)
- 4.2
### 5 附录
#### 5.1 开始
- 5.1.1 编写HelloJNI.java文件。使用以下命令生成HelloJNI.h文件
```
javac -encoding utf-8 HelloJNI.java
javah HelloJNI
```
- 5.1.2 将HelloJNI.h里的方法名复制到HelloJNI.c里，引入头文件，并编写该函数
- 5.1.3 使用以下命令将HelloJNI.c文件编译成hello.dll文件。jni.h头文件在 “\include” 和 “\include\win32”目录下。JAVA_HOME是环境变量里设置的java安装目录
```
gcc -Wl,--add-stdcall-alias -I"%JAVA_HOME%\include" -I"%JAVA_HOME%\include\win32" -shared -o hello.dll HelloJNI.c
```
#### 5.2 运行时报出java.lang.UnsatisfiedLinkError错误，使用-Djava.library.path指定加载库的位置可能可以解决
```
java -Djava.library.path=. HelloJNI
```
#### 5.3 如果实在觉得jni的签名不好记忆的话，我们可以是用JDK为我们提供的工具javap来获得某个class类中的所有方法的签名，使用-s选项表示打印签名，-p表示显示private成员：
```
> javap --help
> javap -s -p TestJNICallBackMethod
  .......
  private void callback();
    Signature: ()V

  private void callback(java.lang.String);
    Signature: (Ljava/lang/String;)V

  private double callbackAverage(int, int);
    Signature: (II)D

  private static java.lang.String callbackStatic();
    Signature: ()Ljava/lang/String;
  .......
```
参考链接：[Java Native Interface(JNI)从零开始详细教程](https://blog.csdn.net/createchance/article/details/53783490)