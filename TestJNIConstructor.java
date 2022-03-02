public class TestJNIConstructor {
	static {
		System.loadLibrary("myjniConstructor");
	}

	private native Integer getIntegerObject(int number);

	public static void main(String[] args) {
		TestJNIConstructor obj = new TestJNIConstructor();
		System.out.println("In Java, the number is :" + obj.getIntegerObject(9999));
	}
}
