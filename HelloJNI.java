/**
 * 1. 使用c来实现JNI
 */
public class HelloJNI {
	static {
		// 在这个类被类加载器加载的时候来加载一个native库hello（这个库中实现了sayHello函数）。
		// 这个库在windows上对应了hello.dll，在类unix上对应hello.so。其包含在java的库路径上（使用Java.library.path系统变量表示）
		// 否则会出现UnsstisfiedLinkError错误，使用VM的参数-Djava.library.pth=path_to_lib来指定这个native库的路径
		System.loadLibrary("hello"); 
	}

	// native关键字将sayHello()方法声明位本地实例方法
	private native void sayHello();

	public static void main(String[] args) {
		new HelloJNI().sayHello();
	}
}