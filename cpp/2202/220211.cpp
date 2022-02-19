#include <string>

/**
 * 567. Permutation in String
 * Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
 * In other words, return true if one of s1's permutations is the substring of s2.
 */

class Solution {
private:
	bool ok(int* c) {
		for (int i = 0; i < 26; ++i)
			if (c[i]) return false;
		return true;
	}
public:
	bool checkInclusion(string s1, string s2) {
		int n1 = s1.length(), n2 = s2.length();
		if (n1 > n2) return false;
		int cnt[26]{};
		for (char c: s1)++cnt[c - 'a'];
		for (int i = 0; i < n1; ++i)
			--cnt[s2[i] - 'a'];
		if (ok(cnt)) return true;
		for (int i = n1; i < n2; ++i) {
			--cnt[s2[i] - 'a'];
			++cnt[s2[i - n1] - 'a'];
			if (ok(cnt)) return true;
		}
		return false;
	}
};