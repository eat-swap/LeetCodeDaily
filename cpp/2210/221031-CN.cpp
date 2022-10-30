#include <bitset>
#include <iostream>

/**
 * 481. Magical String
 *
 * A magical string s consists of only '1' and '2' and obeys the following rules:
 * - The string s is magical because concatenating the number of contiguous occurrences of characters '1' and '2' generates the string s itself.
 * The first few elements of s is s = "1221121221221121122……". If we group the consecutive 1's and 2's in s, it will be "1 22 11 2 1 22 1 22 11 2 11 22 ......" and the occurrences of 1's or 2's in each group are "1 2 2 1 1 2 1 2 2 1 2 2 ......". You can see that the occurrence sequence is s itself.
 * Given an integer n, return the number of 1's in the first n number in the magical string s.
 */

class Solution {
public:
	static constexpr int magicalString(int n) {
		if (n <= 3) return 1;
		std::bitset<100000> s;
		int i = 2, c[2] = {1, 2};
		s[1] = s[2] = true;
		for (; c[0] + c[1] < n; ++i) {
			s[c[i & 1]++ + c[i & 1 ^ 1]] = i & 1;
			if (s[i])
				s[c[i & 1]++ + c[i & 1 ^ 1]] = i & 1;
		}
		return c[0] + (!(i & 1) ? 0 : (n - c[0] - c[1]));
	}
};

int main() {
	std::cout << Solution::magicalString(4) << "\n";
	std::cout << Solution::magicalString(5) << "\n";
	std::cout << Solution::magicalString(6) << "\n";
	std::cout << Solution::magicalString(7) << "\n";
	std::cout << Solution::magicalString(8) << "\n";
	std::cout << Solution::magicalString(9) << "\n";
	std::cout << Solution::magicalString(10) << "\n";
	std::cout << Solution::magicalString(11) << "\n";
	std::cout << Solution::magicalString(12) << "\n";
	std::cout << Solution::magicalString(13) << "\n";
	std::cout << Solution::magicalString(14) << "\n";
	std::cout << Solution::magicalString(15) << "\n";
	std::cout << Solution::magicalString(16) << "\n";
	std::cout << Solution::magicalString(17) << "\n";
	std::cout << Solution::magicalString(18) << "\n";
	std::cout << Solution::magicalString(19) << "\n";
	return 0;
}
