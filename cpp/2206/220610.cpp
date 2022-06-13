#include <unordered_set>
#include <string>

/**
 * 3. Longest Substring Without Repeating Characters
 * Given a string s, find the length of the longest substring without repeating characters.
 *
 * 100% same algorithm as -> 220612.cpp
 */

class Solution {
public:
	static int lengthOfLongestSubstring(const std::string& str) {
		std::unordered_set<int> s;
		const int n = str.length();
		int sum = 0, ret = 0;
		for (int i = 0, l = 0; i < n; ++i) {
			std::printf("In loop, i = %d, l = %d\nStart inserting: ", i, l);
			for (; i < n && !s.count(str[i]); ++i) {
				++sum; // sum += str[i];
				s.insert(str[i]);
				std::printf("%d ", str[i]);
			}
			ret = std::max(ret, sum);

			if (i == n)
				break;

			std::printf("\nEnd inserting at position %d, str[i] = %d, updating ret <- %d\nStart popping: ", i, str[i], ret);

			// pop until reach str[i]
			for (; str[l] != str[i]; ++l) {
				s.erase(str[l]);
				--sum; // sum -= str[l];
				std::printf("%d ", str[l]);
			}
			++l; // where str[l] == str[i]
			std::printf("\nEnd loop, where i = %d, l = %d\n\n", i, l);
		}

		return ret;
	}
};
