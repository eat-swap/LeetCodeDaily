#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

/**
 * 1254. Number of Closed Islands
 *
 * Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.
 * Return the number of closed islands.
 */

class Solution {
private:
	static const inline int dX[] = {0, 1, 0, -1}, dY[] = {1, 0, -1, 0};
public:
	static int closedIsland(std::vector<std::vector<int>>&);
};

int Solution::closedIsland(std::vector<std::vector<int>>& G) {
	const int m = G.size(), n = G.front().size();
	auto setAs1 = [&](int x, int y) {
		if (G[x][y]) return 0;
		std::queue<std::pair<int, int>> q;
		q.emplace(x, y);
		for (int nx, ny; !q.empty(); q.pop()) {
			auto&& [cx, cy] = q.front();
			G[cx][cy] = 1;
			for (int i = 0; i < 4; ++i) {
				nx = cx + dX[i];
				ny = cy + dY[i];
				if (nx >= 0 && nx < m && ny >= 0 && ny < n && G[nx][ny] == 0)
					q.emplace(nx, ny);
			}
		}
		return 1;
	};
	for (int i = 0; i < n; ++i)
		setAs1(0, i), setAs1(m - 1, i);
	for (int i = 1; i < m; ++i)
		setAs1(i, 0), setAs1(i, n - 1);
	int ret = 0;
	for (int i = 1; i < m - 1; ++i)
		for (int j = 1; j < n - 1; ++j)
			ret += setAs1(i, j);
	return ret;
}

int main() {
	std::vector<std::vector<int>> a {
		{1,1,1,1,1,1,1,0},
		{1,0,0,0,0,1,1,0},
		{1,0,1,0,1,1,1,0},
		{1,0,0,0,0,1,0,1},
		{1,1,1,1,1,1,1,0}
	};
	std::cout << Solution::closedIsland(a);
	return 0;
}
