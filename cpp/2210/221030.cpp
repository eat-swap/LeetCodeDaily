#include <vector>
#include <queue>
#include <tuple>
#include <iostream>

/**
 * 1293. Shortest Path in a Grid with Obstacles Elimination
 *
 * You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). You can move up, down, left, or right from and to an empty cell in one step.
 * Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.
 */

class Solution {
private:
	static constexpr inline bool OK(int x, int y, int m, int n) {
		return x >= 0 && y >= 0 && x < m && y < n;
	}

	static const inline int dX[] = {0, 1, 0, -1};
	static const inline int dY[] = {1, 0, -1, 0};

public:
	static int shortestPath(const std::vector<std::vector<int>>& G, const int k) {
		const int m = G.size(), n = G.front().size(), p = m * n;
		if (m == 1 && n == 1)
			return 0;

		auto dp = new int[40][40][1600]{};
		std::queue<std::tuple<uint8_t, uint8_t, short, int>> q;
		q.push({m - 1, n - 1, 0, 0});
		dp[m - 1][n - 1][0] = -1;
		while (!q.empty()) {
			const auto [x, y, d, l] = q.front();
			q.pop();
			for (int i = 0; i < 4; ++i) {
				int nx = x + dX[i], ny = y + dY[i];
				if (!OK(nx, ny, m, n) || dp[nx][ny][d + G[nx][ny]] || d + G[nx][ny] > k)
					continue;
				q.push({nx, ny, d + G[nx][ny], dp[nx][ny][d + G[nx][ny]] = 1 + l});
			}
		}
		int ans = 0x7FFFFFFF;
		for (int i = 0; i <= k; ++i)
			if (dp[0][0][i])
				ans = std::min(ans, dp[0][0][i]);
		delete[] dp;
		return ans == 0x7FFFFFFF ? -1 : ans;
	}
};

int main() {
	std::cout << Solution::shortestPath({{0,0,0},{1,1,0},{0,0,0},{0,1,1},{0,0,0}}, 1);
	return 0;
}
