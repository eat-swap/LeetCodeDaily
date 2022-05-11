#include <cstdio>

/**
 * 1641. Count Sorted Vowel Strings
 *
 * Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.
 * A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.
 */

class Solution {
public:
	static int countVowelStrings(int n) {
		int ans[5]{1, 1, 1, 1, 1};
		while (--n)
			ans[4] += (ans[3] += (ans[2] += ++ans[1]));
		return ans[0] + ans[1] + ans[2] + ans[3] + ans[4];
	}
};

int main() {
	std::printf("%d\n", Solution::countVowelStrings(33));
	return 0;
}
