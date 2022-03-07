#include <string>
#include <iostream>

/**
 * 521. Longest Uncommon Subsequence I
 * Given two strings a and b, return the length of the longest uncommon subsequence between a and b. If the longest uncommon subsequence does not exist, return -1.
 * An uncommon subsequence between two strings is a string that is a subsequence of one but not the other.
 * A subsequence of a string s is a string that can be obtained after deleting any number of characters from s.
 * For example, "abc" is a subsequence of "aebdc" because you can delete the underlined characters in "aebdc" to get "abc". Other subsequences of "aebdc" include "aebdc", "aeb", and "" (empty string).
 */

class Solution {
public:
	// clang does not accept constexpr
	static inline int findLUSlength(const std::string& a, const std::string& b) {
		return a == b ? -1 : static_cast<int>(std::max(a.length(), b.length()));
	}
};

int main() {
	std::cout << Solution::findLUSlength("aaa", "bbb");
	return 0;
}
