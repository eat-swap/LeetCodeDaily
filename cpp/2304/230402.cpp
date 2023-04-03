#include <cstdio>
#include <iterator>
#include <vector>
#include <algorithm>

/**
 * 2300. Successful Pairs of Spells and Potions
 *
 * You are given two positive integer arrays spells and potions, of length n and m respectively, where spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion.
 * You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths is at least success.
 * Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.
 */

class Solution {
	using VI = std::vector<int>;
	using LL = long long;
public:
	static VI successfulPairs(const VI& s, VI& p, LL t) {
		VI ret;
		std::sort(p.begin(), p.end());
		std::transform(s.begin(), s.end(), std::back_inserter(ret), [&](auto&& x) {
			return p.end() - std::lower_bound(p.begin(), p.end(), t / x + !!(t % x));
		});
		return ret;
	}
};

int main() {
	long long x = 7;
	std::vector<int> args_p {1, 2, 3, 4, 5};
	for (auto ret = Solution::successfulPairs({5, 1, 7}, args_p, x); auto&& i : ret) {
		std::printf("%d\n", i);
	}
	return 0;
}
