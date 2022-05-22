#include <string>
#include <iostream>

/**
 * 647. Palindromic Substrings
 * Given a string s, return the number of palindromic substrings in it.
 * A string is a palindrome when it reads the same backward as forward.
 * A substring is a contiguous sequence of characters within the string.
 */

class Solution {
private:
	int isPalindromeS[1002][1002]{{}};

	const char* str = nullptr;

	int isPalindrome(int L, int R) {
		if (L > R) return -1;
		if (isPalindromeS[L][R]) return isPalindromeS[L][R];
		switch (R - L) {
			case 0:
				return isPalindromeS[L][R] = 1;
			case 1:
				return isPalindromeS[L][R] = (str[L] == str[R] ? 1 : -1);
			default:
				return isPalindromeS[L][R] = (str[L] == str[R] ? isPalindrome(L + 1, R - 1) : -1);
		}
	}

public:
	int countSubstrings(const std::string& s) {
		this->str = s.c_str();
		const int len = s.length();

		int ans = 0;
		for (int i = 0; i < len; ++i) {
			for (int L = 0; L + i < len; ++L) {
				ans += isPalindrome(L, L + i) > 0 ? 1 : 0;
			}
		}
		return ans;
	}
};

int main() {
	auto s = new Solution;
	std::cout << s->countSubstrings("abc");
	return 0;
}
