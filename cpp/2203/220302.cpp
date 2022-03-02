#include <string>

/**
 * 392. Is Subsequence
 * Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
 * A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
 */

class Solution {
public:
	static bool isSubsequence(const std::string& t, const std::string& s) {
		int m = s.length(), n = t.length(), i = 0, j = 0;
		while (i < m && j < n) {
			if (s[i++] == t[j])
				++j;
		}
		return j == n;
	}
};

int main() {
	return 0;
}
