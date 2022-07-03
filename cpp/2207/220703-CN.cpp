#include <string>
#include <algorithm>
#include <stdexcept>

/**
 * 556. Next Greater Element III
 * Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.
 * Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.
 */

class Solution {
public:
	static int nextGreaterElement(int n) {
		auto s = std::to_string(n);
		if (!std::next_permutation(s.begin(), s.end()))
			return -1;
		try {
			return std::stoi(s);
		} catch (const std::out_of_range& e) {
			return -1;
		}
	}
};
