#include <string>

/**
 * 1638. Count Substrings That Differ by One Character
 *
 * Given two strings s and t, find the number of ways you can choose a non-empty substring of s and replace a single character by a different character such that the resulting substring is a substring of t. In other words, find the number of substrings in s that differ from some substring in t by exactly one character.
 * For example, the underlined substrings in "computer" and "computation" only differ by the 'e'/'a', so this is a valid way.
 * Return the number of substrings that satisfy the condition above.
 * A substring is a contiguous sequence of characters within a string.
 */

class Solution {
public:
	static int countSubstrings(const std::string& s, const std::string& t) {
		const int m = s.length(), n = t.length();
		auto count = [m, n, &s, &t](int x, int y) {
			bool cap = false;
			int cnt = 0;
			for (int i = x, j = y; i < m && j < n; ++i, ++j) {
				if (s[i] != t[j]) {
					if (cap) break;
					else cap = true;
				}
				if (cap) ++cnt;
			}
			return cnt;
		};
		int ans = 0;
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				ans += count(i, j);
		return ans;
	}
};
