#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

/**
 * 473. Matchsticks to Square
 * You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.
 * Return true if you can make this square and false otherwise.
 */

class Solution {
public:
	static bool makesquare(std::vector<int>& matchsticks) {
		std::sort(matchsticks.begin(), matchsticks.end(), std::greater<>());
		int sum = std::accumulate(matchsticks.begin(), matchsticks.end(), 0);
		if ((sum & 3) || (sum >> 2) < matchsticks.front())
			return false;
		int length[4]{}, n = matchsticks.size();

		std::function<bool(int)> dfs = [&](int depth) {
			if (depth >= n) {
				return !std::any_of(length + 1, length + 4, [&](int x) { return x != length[0]; });
			}
			bool ok = false;
			for (int& i : length) {
				i += matchsticks[depth];
				if (i <= (sum >> 2) && dfs(depth + 1))
					ok = true;
				i -= matchsticks[depth];
				if (ok) break;
			}
			return ok;
		};

		return dfs(0);
	}
};

int main() {
	std::vector<int> arg {3,3,3,3,4};
	Solution::makesquare(arg);
	return 0;
}
