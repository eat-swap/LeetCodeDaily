#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <numeric>

/**
 * 1020. Number of Enclaves
 *
 * You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
 * A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
 * Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.
 */

class Solution {
private:
	static const inline int dX[] = {0, 1, 0, -1}, dY[] = {1, 0, -1, 0};
public:
	static int numEnclaves(std::vector<std::vector<int>>&);
};

int Solution::numEnclaves(std::vector<std::vector<int>>& G) {
	const int m = G.size(), n = G.front().size();
	auto setAs0 = [&](int x, int y) {
		if (G[x][y] == 0) return 0;
		std::queue<std::pair<int, int>> q;
		q.emplace(x, y);
		int ret = 0;
		std::vector<bool> vis(m * n);
		for (int nx, ny; !q.empty(); q.pop()) {
			auto&& [cx, cy] = q.front();
			G[cx][cy] = 0;
			++ret;
			for (int i = 0; i < 4; ++i) {
				nx = cx + dX[i];
				ny = cy + dY[i];
				if (nx >= 0 && nx < m && ny >= 0 && ny < n && G[nx][ny] != 0 && !vis[nx * n + ny]) {
					q.emplace(nx, ny);
					vis[nx * n + ny] = true;
				}
			}
		}
		return ret;
	};
	for (int i = 0; i < n; ++i)
		setAs0(0, i), setAs0(m - 1, i);
	for (int i = 1; i < m - 1; ++i)
		setAs0(i, 0), setAs0(i, n - 1);
	return std::transform_reduce(G.begin(), G.end(), 0, [](int x, int y){ return x + y; }, [](auto&& x) {
		return std::reduce(x.begin(), x.end(), 0);
	});
}

int main() {
	std::vector<std::vector<int>> a {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
	std::cout << Solution::numEnclaves(a);
	return 0;
}
