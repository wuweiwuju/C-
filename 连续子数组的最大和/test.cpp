#define _CRT_SECURE_NO_WARNINGS 1
public int calMaxSumOfArray(int[] a) {
	if (null == a) {
		return 0;
	}
	if (a.length == 1) {
		return a[0];
	}
	int sum = a[0];
	int temp = a[0];
	for (int i = 1; i < a.length; i++) {
		if (temp < 0) {
			temp = 0;
		}
		temp = temp + a[i];
		if (sum < temp) {
			sum = temp;
		}
	}
	return sum;
}