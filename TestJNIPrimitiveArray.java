/**
 * 2. 在java和native代码之间传递数据
 * 2.3 传递基本类型数组
 */
public class TestJNIPrimitiveArray {
	static {
		System.loadLibrary("myjniPrimitiveArray");
	}

	private native double[] sumAndAverage(int[] numbers);

	public static void main (String[] args) {
		int[] numbers = {22, 33, 33};

		double[] results = new TestJNIPrimitiveArray().sumAndAverage(numbers);
		System.out.println("In Java, the sum is " + results[0]);
		System.out.println("In Java, the average is " + results[1]);
	}
}
