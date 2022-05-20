#include <vector>
#include <functional>
#include <cstdio>

/**
 * 329. Longest Increasing Path in a Matrix
 * Given an m x n integers matrix, return the length of the longest increasing path in matrix.
 * From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).
 */

class Solution {
private:
	inline static int dX[] = {0, 1, 0, -1};
	inline static int dY[] = {1, 0, -1, 0};

public:
	static int longestIncreasingPath(const std::vector<std::vector<int>>& matrix) {
		const int m = matrix.size(), n = matrix.front().size();

		int* dp = new int[m * n]{};
		std::function<int(int)> d = [&](int id) {
			if (dp[id])
				return dp[id];

			const int x = id / n, y = id % n;
			// 4 directions
			int ans = 1;
			for (int i = 0; i < 4; ++i) {
				if (x + dX[i] < 0 || x + dX[i] >= m || y + dY[i] < 0 || y + dY[i] >= n || matrix[x + dX[i]][y + dY[i]] <= matrix[x][y])
					continue;
				ans = std::max(ans, 1 + d((x + dX[i]) * n + (y + dY[i])));
			}
			return dp[id] = ans;
		};

		int ret = 0;
		for (int i = 0; i < m * n; ++i)
			ret = std::max(ret, d(i));

		delete[] dp;
		return ret;
	}
};

int main() {
	std::printf("%d\n", Solution::longestIncreasingPath({{9,9,4},{6,6,8},{2,1,1}}));
	return 0;
}
