#include <algorithm>
#include <string>
#include <iostream>

/**
 * 516. Longest Palindromic Subsequence
 *
 * Given a string s, find the longest palindromic subsequence's length in s.
 * A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
 */

class Solution {
private:
	std::string s;
	int ans[1001][1001]{};

	int dp(int, int);

public:
	int longestPalindromeSubseq(std::string);
};

int Solution::longestPalindromeSubseq(std::string str) {
	this->s = std::move(str);
	return dp(0, s.size() - 1);
}

int Solution::dp(int x, int y) {
	int& a = ans[x][y];
	if (a)
		return a;
	if (x == y)
		return a = 1;
	if (1 == y - x)
		return a = 1 + (s[x] == s[y]);
	return a = std::max(
		(s[x] == s[y]) * 2 + dp(x + 1, y - 1),
		std::max(dp(x + 1, y), dp(x, y - 1))
	);
}

int main() {
	auto* s = new Solution;
	std::cout << s->longestPalindromeSubseq("cbbd");
	return 0;
}
