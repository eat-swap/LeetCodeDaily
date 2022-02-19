#include <vector>
#include <iostream>

/**
 * 1219. Path with Maximum Gold
 * In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.
 *
 * Return the maximum amount of gold you can collect under the conditions:
 * - Every time you are located in a cell you will collect all the gold in that cell.
 * - From your position, you can walk one step to the left, right, up, or down.
 * - You can't visit the same cell more than once.
 * - Never visit a cell with 0 gold.
 * - You can start and stop collecting gold from any position in the grid that has some gold.
 */

class Solution {
private:
	static int dfs(const std::vector<std::vector<int>>& grid, int x, int y, bool* const vis) {
		int ret = 0;
		const auto m = grid.size(), n = grid.front().size();
		vis[x * n + y] = true;
		if (x > 0 && !vis[(x - 1) * n + y] && grid[x - 1][y]) {
			ret = dfs(grid, x - 1, y, vis);
		}
		if (y > 0 && !vis[x * n + y - 1] && grid[x][y - 1]) {
			ret = std::max(ret, dfs(grid, x, y - 1, vis));
		}
		if (x + 1 < m && !vis[(x + 1) * n + y] && grid[x + 1][y]) {
			ret = std::max(ret, dfs(grid, x + 1, y, vis));
		}
		if (y + 1 < n && !vis[x * n + y + 1] && grid[x][y + 1]) {
			ret = std::max(ret, dfs(grid, x, y + 1, vis));
		}
		vis[x * n + y] = false;
		return ret + grid[x][y];
	}
public:
	static int getMaximumGold(const std::vector<std::vector<int>>& grid) {
		auto m = grid.size(), n = grid.front().size();
		bool* const vis = new bool[m * n]{};
		int ret = 0;
		for (decltype(m) i = 0; i < m; ++i) {
			for (decltype(n) j = 0; j < n; ++j) {
				if (grid[i][j]) {
					ret = std::max(ret, dfs(grid, i, j, vis));
				}
			}
		}
		delete[] vis;
		return ret;
	}
};

int main() {
	std::cout << Solution::getMaximumGold({{0,0,1},{1,1,0},{1,1,0}});
	return 0;
}
