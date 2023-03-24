#include <vector>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <iostream>

/**
 * 1466. Reorder Routes to Make All Paths Lead to the City Zero
 *
 * There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.
 * Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.
 * This year, there will be a big event in the capital (city 0), and many people want to travel to this city.
 * Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.
 * It's guaranteed that each city can reach city 0 after reorder.
 */

class Solution {
public:
	static int minReorder(int n, const std::vector<std::vector<int>>& connections) {
		std::vector<std::unordered_set<int>> vs(n);
		for (const auto& i : connections) {
			vs[i[0]].insert(-i[1]);
			vs[i[1]].insert(i[0]);
		}
		std::vector<bool> vis(n);
		std::function<int(int)> dfs = [&](int cur) {
			vis[cur] = true;
			int ret = 0;
			for (int nx : vs[cur])
				if (!vis[std::abs(nx)])
					ret += (nx < 0) + dfs(std::abs(nx));
			return ret;
		};
		return dfs(0);
	}
};

int main() {
	std::cout << Solution::minReorder(6, {
		{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}
	});
	return 0;
}
