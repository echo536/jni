/**
 * 3. 访问java对象和回调Java方法
 * 3.1 访问Java对象实例的变量
 */
public class TestJNIInstanceVariable {
	static {
		System.loadLibrary("myjniInstanceVariable");
	}

	// 实例变量
	private int number = 88;
	private String message = "Hello from Java";

	private native void modifyInstanceVariable();

	public static void main(String[] args) {
		TestJNIInstanceVariable test = new TestJNIInstanceVariable();
		test.modifyInstanceVariable();
		System.out.println("In java, int is " + test.number);
		System.out.println("In java, String is " + test.message);
	}
}
