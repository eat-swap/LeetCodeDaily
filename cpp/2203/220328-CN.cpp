#include <iostream>

/**
 * 693. Binary Number with Alternating Bits
 * Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.
 */

class Solution {
public:
	static constexpr bool hasAlternatingBits(int n) {
		unsigned x = unsigned(1 << (32 - __builtin_clz(n))) - 1;
		return ((n ^ 0x55555555) & x) == x || ((n ^ 0xAAAAAAAA) & x) == x;
	}
};

int main() {
	std::printf("%s", Solution::hasAlternatingBits(33) ? "true" : "false");
	return 0;
}
