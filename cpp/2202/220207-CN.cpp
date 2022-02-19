#include <string>
#include <vector>
#include <iostream>

/**
 * 1405. Longest Happy String
 * A string s is called happy if it satisfies the following conditions:
 * s only contains the letters 'a', 'b', and 'c'.
 * s does not contain any of "aaa", "bbb", or "ccc" as a substring.
 * s contains at most a occurrences of the letter 'a'.
 * s contains at most b occurrences of the letter 'b'.
 * s contains at most c occurrences of the letter 'c'.
 * Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".
 * A substring is a contiguous sequence of characters within a string.
 */

class Solution {
	static std::string gen(char xc, int x, char yc, int y) {
		if (x < y) {
			std::swap(xc, yc);
			std::swap(x, y);
		}
		if (!y)
			return std::string(std::min(2, x), xc);
		std::string ret;
		if (x > (y << 1)) {
			for (int i = 0; i < y; ++i)
				ret += std::string{xc, xc, yc};
			ret += std::string(std::min(2, x - (y << 1)), xc);
		} else {
			for (int i = x - y; i--; )
				ret += std::string{xc, xc, yc};
			for (int i = y - (x - y); i--; )
				ret += std::string{xc, yc};
		}
		return ret;
	}
public:
	static std::string longestDiverseString(int a, int b, int c) {
		std::vector<std::pair<int, char>> s {{a, 'a'}, {b, 'b'}, {c, 'c'}};
		std::sort(s.begin(), s.end(), [](const std::pair<int, char>& x, const std::pair<int, char>& y) { return x.first > y.first; });

		if (s[0].first > 2 * (s[1].first + s[2].first))
			return gen(s[0].second, s[1].first << 1, s[1].second, s[1].first) + gen(s[0].second, s[0].first - (s[1].first << 1), s[2].second, s[2].first);

		int for2 = std::min(s[0].first >> 1, s[2].first << 1), for1 = s[0].first - for2;
		if (for1 < s[1].first && s[2].first < for2)
			return gen(s[0].second, for2, s[2].second, s[2].first) + gen(s[0].second, for1, s[1].second, s[1].first);
		return gen(s[0].second, for1, s[1].second, s[1].first) + gen(s[0].second, for2, s[2].second, s[2].first);
	}
};

int main() {
	std::cout << Solution::longestDiverseString(1, 0, 3);
	return 0;
}
