#include <string>

/**
 * 796. Rotate String
 * Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
 * A shift on s consists of moving the leftmost character of s to the rightmost position.
 * For example, if s = "abcde", then it will be "bcdea" after one shift.
 */

class Solution {
public:
	static bool rotateString(const std::string& s, const std::string& g) {
		const std::size_t n = s.length();
		for (std::size_t np = g.find(s[0], 0); np != std::string::npos; np = g.find(s[0], np + 1))
			if (g.substr(np) + g.substr(0, np) == s)
				return true;
		return false;
	}
};
