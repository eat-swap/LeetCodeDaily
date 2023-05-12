#include <bitset>
#include <string>

/**
 * 1016. Binary String With Substrings Representing 1 To N
 *
 * Given a binary string s and a positive integer n, return true if the binary representation of all the integers in the range [1, n] are substrings of s, or false otherwise.
 * A substring is a contiguous sequence of characters within a string.
 */

class LC230511CN {
public:
	static bool queryString(const std::string& s, int n) noexcept;
};

bool LC230511CN::queryString(const std::string& s, int n) noexcept {
	if (n > 1000)
		return false;
	std::bitset<1024> set;
	set[s.front() & 1] = true;
	const int sn = s.length();
	for (int i = 1, mask = 1, cnt; i <= 10 && i < sn; (++i), (mask = mask << 1 | 1)) {
		// init
		int cur = 0;
		for (int j = 0; j < i; ++j)
			cur = (cur << 1) | (s[j] & 1);

		cnt = 1;
		set[cur] = true;
		for (int j = i; j < sn && cnt < (1 << i); ++j) {
			cur = ((cur << 1) | (s[j] & 1)) & mask;
			if (set[cur])
				continue;
			set[cur] = true;
			++cnt;
		}
	}

	for (int i = 1; i <= n; ++i)
		if (!set[i])
			return false;
	return true;
}

using Solution = LC230511CN;
