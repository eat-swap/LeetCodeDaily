#include <iostream>

/**
 * 258. Add Digits
 * Given an integer `num`, repeatedly add all its digits until the result has only one digit, and return it.
 */

class Solution {
public:
	static constexpr int addDigits(int num) {
		int ret = 0;
		for (; num; num /= 10)
			ret += num % 10;
		return ret < 10 ? ret : addDigits(ret);
	}
};

int main() {
	std::cout << Solution::addDigits(38);
	return 0;
}
