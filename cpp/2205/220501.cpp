#include <string>
#include <algorithm>

/**
 * 844. Backspace String Compare
 * Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
 * Note that after backspacing an empty text, the text will continue empty.
 */

class Solution {
public:
	static bool backspaceCompare(const std::string& s, const std::string& t) {
		std::string ss, tt;
		std::for_each(s.cbegin(), s.cend(), [&](char c) { if (c == '#') { if (!ss.empty()) ss.pop_back(); } else ss.push_back(c); });
		std::for_each(t.cbegin(), t.cend(), [&](char c) { if (c == '#') { if (!tt.empty()) tt.pop_back(); } else tt.push_back(c); });
		return ss == tt;
	}
};
