#include <iostream>
#include <numeric>

/**
 * 2427. Number of Common Factors
 *
 * Given two positive integers a and b, return the number of common factors of a and b.
 * An integer x is a common factor of a and b if x divides both a and b.
 */

class Solution {
public:
	static constexpr inline int commonFactors(int a, int b) {
		int x = std::gcd(a, b), ret = 0;
		for (int i = 1; i * i <= x; ++i)
			ret += ((x % i == 0) << 1) - (i * i == x);
		return ret;
	}
};

int main() {
	std::cout << Solution::commonFactors(452, 392);
	std::cout << std::gcd(452, 392);
	return 0;
}
