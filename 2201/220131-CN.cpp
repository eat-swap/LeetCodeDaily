#include <iostream>

/**
 * 1342. Number of Steps to Reduce a Number to Zero
 * Given an integer num, return the number of steps to reduce it to zero.
 * In one step, if the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.
 */

class Solution {
public:
	static constexpr int numberOfSteps(int num) {
		int ret = 0;
		for (; num & 0xFFFFFFFE; num >>= 1)
			ret += 1 + (num & 1);
		return ret + num;
	}
};

int main() {
	std::printf("%d\n", Solution::numberOfSteps(14));
	std::printf("%d\n", Solution::numberOfSteps(8));
	std::printf("%d\n", Solution::numberOfSteps(123));
}