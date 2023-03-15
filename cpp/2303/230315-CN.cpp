#include <vector>

/**
 * 1615. Maximal Network Rank
 *
 * There is an infrastructure of n cities with some number of roads connecting these cities. Each roads[i] = [ai, bi] indicates that there is a bidirectional road between cities ai and bi.
 * The network rank of two different cities is defined as the total number of directly connected roads to either city. If a road is directly connected to both cities, it is only counted once.
 * The maximal network rank of the infrastructure is the maximum network rank of all pairs of different cities.
 * Given the integer n and the array roads, return the maximal network rank of the entire infrastructure.
 */

class Solution {
public:
	static int maximalNetworkRank(int n, const std::vector<std::vector<int>>& roads) {
		bool G[105][105]{};
		int cnt[105]{};
		for (const auto& i : roads) {
			G[i[0]][i[1]] = G[i[1]][i[0]] = true;
			++cnt[i[0]];
			++cnt[i[1]];
		}
		int ans = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (i != j)
					ans = std::max(ans, cnt[i] + cnt[j] - G[i][j]);
		return ans;
	}
};
