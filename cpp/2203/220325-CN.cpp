#include <iostream>

/**
 * 172. Factorial Trailing Zeroes
 * Given an integer n, return the number of trailing zeroes in n!.
 */

class Solution {
public:
	// This algorithm is far NOT optimal.
	static constexpr int trailingZeroes(int n) {
		// Main algorithm: 2 * 5 = 10.
		// Time complexity: O(n * sqrt(n))
		int cnt2 = 0, cnt5 = 0;
		for (int i = 2; i <= n; ++i) {
			for (int x = i; !(x % 2); x /= 2)
				++cnt2;
			for (int x = i; !(x % 5); x /= 5)
				++cnt5;
		}
		return std::min(cnt2, cnt5);
	}
};

int main() {
	std::cout << Solution::trailingZeroes(5);
	return 0;
}
