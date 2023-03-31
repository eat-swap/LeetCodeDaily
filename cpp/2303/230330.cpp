#include <string>

/**
 * 87. Scramble String
 * We can scramble a string s to get a string t using the following algorithm:
 *
 * If the length of the string is 1, stop.
 * If the length of the string is > 1, do the following:
 * Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
 * Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
 * Apply step 1 recursively on each of the two substrings x and y.
 * Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.
 */

class Solution {
private:
	// Const Char Pointer
	using CCP = const char*;

	CCP s = nullptr, t = nullptr;
	int dp[31][31][31][31]{};

	bool f(int m, int n, int p, int q) {
		if (m + 1 == n)
			return s[m] == t[p];
		int& ans = dp[m][n][p][q];
		if (ans)
			return (ans + 1);
		ans = 1;
		for (int i = m, j = p; i < n; ++i, ++j) {
			if (s[i] != t[j]) {
				ans = 0;
				break;
			}
		}
		if (ans)
			return ans;
		for (int i = m + 1; i < n; ++i) {
			if (f(m, i, p, p - m + i) && f(i, n, p - m + i, q))
				return ans = 1;
			if (f(m, i, q - (i - m), q) && f(i, n, p, q - (i - m)))
				return ans = 1;
		}
		ans = -1;
		return false;
	}

public:
	bool isScramble(const std::string& s1, const std::string& s2) {
		s = s1.c_str();
		t = s2.c_str();
		return f(0, s1.length(), 0, s2.length());
	}
};
