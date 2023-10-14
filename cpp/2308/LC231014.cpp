#include "defs.h"
#include <algorithm>
#include <functional>
#include <unordered_map>

int LC231014::paintWalls(const std::vector<int>& cost, const std::vector<int>& time) {
	int n = cost.size();

	std::unordered_map<int, int> ans;
	std::function<int(int, int)> dp = [&](int pos, int rem_free) {
		if (pos + rem_free >= n)
			return 0;
		if (pos == n - 1)
			return (rem_free + time[pos] < 0) ? 0x70000000 : cost[pos];
		// rem_free < (1 << 21)
		int& ret = ans[((rem_free + 505 * 505) << 10) | pos];
		return ret ? ret : ret = std::min(dp(pos + 1, rem_free + time[pos]) + cost[pos], dp(pos + 1, rem_free - 1));
	};

	return dp(0, 0);
}

using Solution = LC231014;
