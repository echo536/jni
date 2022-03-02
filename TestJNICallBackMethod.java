public class TestJNICallBackMethod {
	static {
		System.loadLibrary("myjniCallBackMethod");
	}

	private native void nativeMethod();

	private void callback() {
		System.out.println("In Java");
	}

	private void callback(String message) {
		System.out.println("In Java with " + message);
	}

	private double callbackAverage(int n1, int n2) {
		return ((double)n1 + n2) / 2.0;
	}

	private static String callbackStatic() {
		return "From static Java method";
	}

	public static void main(String[] args) {
		new TestJNICallBackMethod().nativeMethod();
	}
}
