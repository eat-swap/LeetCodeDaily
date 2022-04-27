#include <vector>
#include <cstdint>
#include <queue>

/**
 * 417. Pacific Atlantic Water Flow
 * There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.
 * The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).
 * The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.
 * Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.
 */

class Solution {
private:
	static inline int dX[] = {0, 1, 0, -1};
	static inline int dY[] = {1, 0, -1, 0};
public:
	static std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights) {
		const int m = heights.size(), n = heights.front().size();

		auto* buf = new std::uint8_t[n * m]{};

		std::queue<int> q;
		{
			std::vector<bool> vis(n * m);
			for (int i = 0; i < n; ++i) {
				vis[i] = true;
				q.push(i);
			}
			for (int i = 0; i < m; ++i) {
				vis[i * n] = true;
				q.push(i * n);
			}
			while (!q.empty()) {
				int id = q.front();
				q.pop();
				buf[id] |= 1;
				const int x = id / n, y = id % n, nh = heights[x][y];
				for (int i = 0; i < 4; ++i) {
					int nX = x + dX[i], nY = y + dY[i];
					if (nX < 0 || nX >= m || nY < 0 || nY >= n || vis[nX * n + nY] || heights[nX][nY] < nh)
						continue;
					vis[nX * n + nY] = true;
					q.push(nX * n + nY);
				}
			}
		}
		{
			std::vector<bool> vis(n * m);
			for (int i = 0; i < n; ++i) {
				vis[i + (m - 1) * n] = true;
				q.push(i + (m - 1) * n);
			}
			for (int i = 0; i < m; ++i) {
				vis[i * n + (n - 1)] = true;
				q.push(i * n + (n - 1));
			}
			while (!q.empty()) {
				int id = q.front();
				q.pop();
				buf[id] |= 2;
				const int x = id / n, y = id % n, nh = heights[x][y];
				for (int i = 0; i < 4; ++i) {
					int nX = x + dX[i], nY = y + dY[i];
					if (nX < 0 || nX >= m || nY < 0 || nY >= n || vis[nX * n + nY] || heights[nX][nY] < nh)
						continue;
					vis[nX * n + nY] = true;
					q.push(nX * n + nY);
				}
			}
		}
		std::vector<std::vector<int>> ret;
		for (int i = 0; i < m * n; ++i) {
			if (buf[i] == 3)
				ret.push_back({i / n, i % n});
		}
		delete[] buf;
		return ret;
	}
};
