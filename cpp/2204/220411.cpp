#include <vector>
#include <cstdio>

/**
 * 1260. Shift 2D Grid
 * Given a 2D grid of size m x n and an integer k. You need to shift the grid k times.
 * In one shift operation:
 * Element at grid[i][j] moves to grid[i][j + 1].
 * Element at grid[i][n - 1] moves to grid[i + 1][0].
 * Element at grid[m - 1][n - 1] moves to grid[0][0].
 * Return the 2D grid after applying shift operation k times.
 */

class Solution {
public:
	static std::vector<std::vector<int>> shiftGrid(const std::vector<std::vector<int>>& grid, int k) {
		int m = grid.size(), n = grid.front().size();
		int x = 0, y = 0;
		k = m * n - (k % (m * n)) - 1;
		while (k--) {
			y = (1 + y) % n;
			x = (y ? x : ((1 + x) % m));
		}
		std::vector<std::vector<int>> ret(m);
		for (int i = 0; i < m; ++i) {
			auto& t = ret[i];
			t.reserve(n);
			for (int j = 0; j < n; ++j) {
				y = (1 + y) % n;
				t.push_back(grid[x = (y ? x : ((1 + x) % m))][y]);
			}
		}
		return ret;
	}
};

int main() {
	auto ret = Solution::shiftGrid({
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	}, 9);
	for (const auto& i : ret) {
		for (const auto& j : i) {
			std::printf("%d ", j);
		}
		std::printf("\n");
	}
	return 0;
}
