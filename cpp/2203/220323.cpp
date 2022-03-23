#include <iostream>

/**
 * 991. Broken Calculator
 * There is a broken calculator that has the integer startValue on its display initially. In one operation, you can:
 * - multiply the number on display by 2, or
 * - subtract 1 from the number on display.
 * Given two integers startValue and target, return the minimum number of operations needed to display target on the calculator.
 *
 */

class Solution {
public:
	static constexpr int brokenCalc(int startValue, int target) {
		return (startValue >= target) ? startValue - target : 1 + ((target & 1) ? brokenCalc(startValue, target + 1) : brokenCalc(startValue, target / 2));
	}
};

int main() {
	Solution s;
	std::cout << s.brokenCalc(1, 1000000000) << "\n";
}
