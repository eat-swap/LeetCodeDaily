#include <algorithm>
#include <random>
#include <ctime>
#include <cstdio>

/**
 * 29. Divide Two Integers
 * Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.
 * The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.
 * Return the quotient after dividing dividend by divisor.
 * - Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.
 */

class Solution {
public:
	static int divide(int dividend, int divisor) {
		unsigned ans = 0, cur = 1;
		bool neg = (dividend ^ divisor) & 0x80000000;

		unsigned r = 0x80000000 == divisor ? 0x80000000 : std::abs(divisor),
				 d = 0x80000000 == dividend ? 0x80000000 : std::abs(dividend);

		while (r < d) {
			r <<= 1;
			cur <<= 1;
		}

		while (cur) {
			if (d >= r) {
				ans += cur;
				d -= r;
			}
			cur >>= 1;
			r >>= 1;
		}
		if (neg)
			return ans > 0x80000000 ? (-2147483647 - 1) : -ans;
		return ans > 0x7FFFFFFF ? 2147483647 : ans;
	}
};

int main() {
	Solution::divide(-2147483647 - 1, -1);

	std::mt19937 r(std::time(nullptr));

	for (int N = 1048576; N--; ) {
		int x = r(), y = r();
		int d1 = x / y, d2 = Solution::divide(x, y);
		if (d1 != d2) {
			std::printf("Bad answer: (%d / %d) -> %d, but %d is expected.\n", x, y, d2, d1);
			return -1;
		}
	}

	return 0;
}
