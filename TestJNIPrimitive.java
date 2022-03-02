/**
 * 2. 在java和native代码之间传递参数和返回值
 * 2.1 传递基本类型
 */
public class TestJNIPrimitive {
	static {
		System.loadLibrary("myjni");
	}

	private native double average (int n1, int n2);

	public static void main (String[] args) {
		System.out.println("In Java, the average is " + new TestJNIPrimitive().average(3, 2));
	}
}
