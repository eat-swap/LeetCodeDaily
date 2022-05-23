#include <vector>
#include <cstdint>
#include <utility>
#include <algorithm>
#include <functional>
#include <queue>
#include <iostream>

/**
 * 675. Cut Off Trees for Golf Event
 * You are asked to cut off all the trees in a forest for a golf event. The forest is represented as an m x n matrix. In this matrix:
 * 0 means the cell cannot be walked through.
 * 1 represents an empty cell that can be walked through.
 * A number greater than 1 represents a tree in a cell that can be walked through, and this number is the tree's height.
 * In one step, you can walk in any of the four directions: north, east, south, and west. If you are standing in a cell with a tree, you can choose whether to cut it off.
 * You must cut off the trees in order from shortest to tallest. When you cut off a tree, the value at its cell becomes 1 (an empty cell).
 * Starting from the point (0, 0), return the minimum steps you need to walk to cut off all the trees. If you cannot cut off all the trees, return -1.
 * You are guaranteed that no two trees have the same height, and there is at least one tree needs to be cut off.
 */

class Solution {
private:
	inline static int dX[] = {0, 1, 0, -1};
	inline static int dY[] = {1, 0, -1, 0};

public:
	static int cutOffTree(const std::vector<std::vector<int>>& forest) {
		const int m = forest.size(), n = forest.front().size();

		// bit 15-8: X pos, bit 7-0: Y pos
		std::vector<std::pair<int, uint16_t>> treePos;
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				if (forest[i][j] > 1)
					treePos.emplace_back(forest[i][j], (i << 8) | j);
		std::sort(treePos.begin(), treePos.end());
		const int trees = treePos.size();

		auto dijkstra = [&](int start) {
			std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
			q.push({0, start});
			std::vector<bool> vis(m * n);
			std::vector<int> d(m * n, 0x7FFF0000);
			while (!q.empty()) {
				const auto [len, node] = q.top();
				q.pop();

				if (vis[node])
					continue;

				for (int i = 0; i < 4; ++i) {
					int nX = dX[i] + (node / n), nY = dY[i] + (node % n);
					if (nX < 0 || nY < 0 || nX >= m || nY >= n || !forest[nX][nY])
						continue;
					if (d[nX * n + nY] > 1 + d[node]) {
						d[nX * n + nY] = 1 + d[node];
						q.push({d[nX * n + nY], nX * n + nY});
					}
				}
			}
			return d;
		};

		auto bfs = [&](int start) {
			std::queue<std::pair<int, int>> q;
			q.push({0, start});
			std::vector<bool> vis(m * n);
			vis[start] = true;
			std::vector<int> d(m * n, 0x7FFF0000);
			while (!q.empty()) {
				const auto [len, node] = q.front();
				q.pop();
				d[node] = len;
				for (int i = 0; i < 4; ++i) {
					int nX = dX[i] + (node / n), nY = dY[i] + (node % n);
					if (nX < 0 || nY < 0 || nX >= m || nY >= n || !forest[nX][nY] || vis[nX * n + nY])
						continue;
					vis[nX * n + nY] = true;
					q.push({1 + len, nX * n + nY});
				}
			}
			return d;
		};

		std::vector<std::vector<int>> lengths(m * n);
		lengths[0] = bfs(0);
		for (int i = 1; i < m * n; ++i) {
			if (forest[i / n][i % n] > 1)
				lengths[i] = bfs(i);
		}

		int pos = 0, ans = 0;
		for (const auto [h, p] : treePos) {
			int px = (p >> 8) * n + (p & 0xFF);

			if (lengths[pos][px] >= 0x7FFF0000)
				return -1;

			ans += lengths[pos][px];
			pos = px;
		}

		return ans;
	}
};

int main() {
	std::cout << Solution::cutOffTree({{1,2,3},{0,0,4},{7,6,5}});
	return 0;
}
