#include <iostream>

/**
 * 1009. Complement of Base 10 Integer
 * The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.
 *
 * For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
 * Given an integer n, return its complement.
 */

class Solution {
public:
	static int bitwiseComplement(int n) {
		return n ? ((1 << ((31 ^ __builtin_clz(n)) + 1)) - 1) ^ n : 1;
	}
};

int main() {
	std::printf("%d\n", Solution::bitwiseComplement(0));
}