#include <cstdio>

/**
 * 1342. Number of Steps to Reduce a Number to Zero
 * Given an integer num, return the number of steps to reduce it to zero.
 * In one step, if the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.
 *
 * Refer: 220131-CN.cpp
 * __builtin functions this time.
 */

class Solution {
public:
	static int numberOfSteps(int num) {
		return num ? 31 - __builtin_clz(num) + __builtin_popcount(num) : 0;
	}
};

int main() {
	std::printf("%d\n", Solution::numberOfSteps(14));
	return 0;
}
