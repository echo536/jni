/**
 * 2. 在java和native代码之间传递数据
 * 2.2 传递字符串
 */
public class TestJNIString {
	static {
		System.loadLibrary("myjnistring");
	}

	private native String sayHello(String msg);

	public static void main(String[] args) {
		String result = new TestJNIString().sayHello("Hello from java");
		System.out.println("In Java, the returned string is " + result);
	}
}
