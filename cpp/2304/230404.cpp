#include <string>
#include <iostream>

/**
 * 2405. Optimal Partition of String
 *
 * Given a string s, partition the string into one or more substrings such that the characters in each substring are unique. That is, no letter appears in a single substring more than once.
 * Return the minimum number of substrings in such a partition.
 * Note that each character should belong to exactly one substring in a partition.
 */

class Solution {
public:
	static int partitionString(const std::string& s) {
		int set = 0, ans = 0;
		for (auto&& ch : s) {
			if (int c = 1 << (ch - 'a'); set & c) {
				set = c;
				++ans;
			} else set |= c;
		}
		return ans + !!set;
	}
};

int main() {
	std::cout << Solution::partitionString("abacaba");
	return 0;
}
