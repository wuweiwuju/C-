#define _CRT_SECURE_NO_WARNINGS 1
#include<math.h>
class Solution {
public:
	double Power(double base, int exponent) {
		if (exponent == 0)
			return (double)1;
		if (base == 0)
			return (double)0;
		double sum = 1;
		int count = abs(exponent);
		while (count)
		{
			if (count & 1)
				sum *= base;
			base *= base;
			count >>= 1;
		}
		return exponent > 0 ? sum : 1 / sum;
	}
};