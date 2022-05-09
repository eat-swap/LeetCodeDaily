#include <vector>
#include <string>
#include <iostream>

/**
 * 942. DI String MatchA permutation perm of n + 1 integers of all the integers in the range [0, n] can be represented as a string s of length n where:
 *
 * s[i] == 'I' if perm[i] < perm[i + 1], and
 * s[i] == 'D' if perm[i] > perm[i + 1].
 * Given a string s, reconstruct the permutation perm and return it. If there are multiple valid permutations perm, return any of them.
 *
 */

class Solution {
public:
    static std::vector<int> diStringMatch(const std::string& s) {
		int p = 1, n = -1;
		std::vector<int> ret;
		ret.reserve(s.length() + 1);
		ret.push_back(0);
		for (char c : s)
			ret.push_back(c == 'I' ? p++ : n--);
		n = (-n) - 1;
		for (int& i : ret)
			i += n;
		return ret;
    }
};

int main() {
	auto r = Solution::diStringMatch("DDI");
	for (const auto& i : r)
		std::cout << i << ' ';
	return 0;
}
