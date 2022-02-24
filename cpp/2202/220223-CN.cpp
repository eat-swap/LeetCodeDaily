#include <string>
#include <cctype>
#include <iostream>

/**
 * 917. Reverse Only Letters
 * Given a string s, reverse the string according to the following rules:
 * All the characters that are not English letters remain in the same position.
 * All the English letters (lowercase or uppercase) should be reversed.
 * Return s after reversing it.
 */

class Solution {
public:
	static std::string reverseOnlyLetters(std::string s) {
		int L = 0, R = s.length() - 1;
		for (; L < R && !std::isalpha(s[L]); ++L);
		for (; R && !std::isalpha(s[R]); --R);
		for (; L < R; ++L, --R) {
			for (; L < R && !std::isalpha(s[L]); ++L);
			for (; R && !std::isalpha(s[R]); --R);
			if (L >= R)
				break;
			std::swap(s[L], s[R]);
		}
		return s;
	}
};

int main() {
	std::cout << Solution::reverseOnlyLetters("-");
	return 0;
}
