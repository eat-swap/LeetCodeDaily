#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <iostream>

/**
 * 1147. Longest Chunked Palindrome Decomposition
 *
 * You are given a string text. You should split it to k substrings (subtext[1], subtext[2], ..., subtext[k]) such that:
 *
 * subtext[i] is a non-empty string.
 * The concatenation of all the substrings is equal to text (i.e., subtext[1] + subtext[2] + ... + subtext[k] == text).
 * subtext[i] == subtext[k] - i + 1 for all valid values of i (i.e., 1 <= i <= k).
 * Return the largest possible value of k.
 */

class Solution {
private:
	int len;
	std::vector<int> d;
	int dp(int);
	const char* ptr;

public:
	int longestDecomposition(const std::string&);
};

int Solution::longestDecomposition(const std::string& text) {
	len = text.size();
	d = std::vector<int>(len / 2 + 5);
	ptr = text.c_str();
	return dp(0);
}

int Solution::dp(int p) {
	int& ans = d[p];
	if (ans)
		return ans;
	const int end = len - p, cnt = end - p;
	if (cnt < 2)
		return ans = cnt;
	for (int i = 1; i <= cnt / 2; ++i)
		if (!std::memcmp(ptr + p, ptr + end - i, i))
			return 2 + dp(p + i);
	return 1;
}

int main() {
	Solution s;
	std::cout << s.longestDecomposition("antaprezatepzapreanta");
	return 0;
}
