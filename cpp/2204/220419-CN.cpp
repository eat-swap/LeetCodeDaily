#include <algorithm>
#include <string>
#include <vector>

/**
 * 821. Shortest Distance to a Character
 * Given a string s and a character c that occurs in s, return an array of integers answer where answer.length == s.length and answer[i] is the distance from index i to the closest occurrence of character c in s.
 * The distance between two indices i and j is abs(i - j), where abs is the absolute value function.
 */

class Solution {
public:
	static std::vector<int> shortestToChar(const std::string& s, char c) {
		int n = s.length();
		std::vector<int> ret(n, 0x7FFFFFFF);
		for (int prev = -1, i = 0; i < n; ++i) {
			if (s[i] == c)
				prev = i;
			if (prev != -1)
				ret[i] = std::min(ret[i], std::abs(prev - i));
		}
		for (int prev = -1, i = n - 1; i >= 0; --i) {
			if (s[i] == c)
				prev = i;
			if (prev != -1)
				ret[i] = std::min(ret[i], std::abs(prev - i));
		}
		return ret;
	}
};
