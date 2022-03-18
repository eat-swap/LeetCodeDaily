#include <string>

/**
 * 316. Remove Duplicate Letters
 * 1081. Smallest Subsequence of Distinct Characters
 *
 * Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.
 */

class Solution {
public:
	static std::string removeDuplicateLetters(const std::string& s) {
		int lastViewed[26]{}, n = s.length();
		for (int i = 0; i < n; ++i)
			lastViewed[s[i] - 'a'] = i;
		char ans[30]{};
		bool used[26]{};
		int top = -1;
		for (int i = 0; i < n; ++i) {
			if (!used[s[i] - 'a']) {
				while (top >= 0 && ans[top] > s[i] && lastViewed[ans[top] - 'a'] > i) {
					used[ans[top] - 'a'] = false;
					ans[top--] = 0;
				}
				used[(ans[++top] = s[i]) - 'a'] = true;
			}
		}
		return ans;
	}
};
