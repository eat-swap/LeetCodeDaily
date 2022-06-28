#include <string>
#include <set>
#include <iostream>

/**
 * 1647. Minimum Deletions to Make Character Frequencies Unique
 * A string s is called good if there are no two different characters in s that have the same frequency.
 * Given a string s, return the minimum number of characters you need to delete to make s good.
 * The frequency of a character in a string is the number of times it appears in the string. For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.
 */

class Solution {
public:
	static int minDeletions(const std::string& s) {
		int cnt[26]{};
		for (char c : s)
			++cnt[c - 'a'];
		std::set<int> t;
		int ans = 0;
		for (int n : cnt) {
			if (!n)
				continue;
			if (!t.count(n)) {
				t.insert(n);
				continue;
			}
			auto it = t.lower_bound(n);
			for (; it != t.begin() && *it - *std::prev(it) == 1; --it);
			if (*it - 1)
				t.insert(*it - 1);
			ans += n - (*it - 1);
		}
		return ans;
	}
};

int main() {
	std::cout << Solution::minDeletions("bbcebab");
	return 0;
}
