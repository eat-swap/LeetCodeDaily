#include <string>
#include <cctype>
#include <iostream>

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
