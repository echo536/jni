/**
 * 3. 访问java对象和回调java方法
 * 3.2 访问类中的static变量
 */
public class TestJNIStaticVariable {
	static {
		System.loadLibrary("myjniStaticVariable");
	}

	private static double number = 55.66;

	private native void modifyStaticVariable();

	public static void main(String[] args) {
		TestJNIStaticVariable test = new TestJNIStaticVariable();
		test.modifyStaticVariable();
		System.out.println("In java, the double is " + number);
	}
}
