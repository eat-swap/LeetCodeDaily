#include <vector>
#include <cstdio>
#include <algorithm>

/**
 * 63. Unique Paths II
 * You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m-1][n-1]). The robot can only move either down or right at any point in time.
 * An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.
 * Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
 * The testcases are generated so that the answer will be less than or equal to 2 * 109.
 */

class Solution {
public:
	static int uniquePathsWithObstacles(const std::vector<std::vector<int>>& obstacleGrid) {
		const int m = obstacleGrid.size(), n = obstacleGrid.front().size(), k = std::min(m, n);
		auto* dp = new unsigned[n * m]{static_cast<unsigned int>(obstacleGrid[0][0] ^ 1)};

		for (int i = 1; i < k; ++i) {
			dp[i * n] = obstacleGrid[i][0] ? 0 : dp[(i - 1) * n]; // X axis
			dp[i] = obstacleGrid[0][i] ? 0 : dp[i - 1]; // Y axis
			for (int j = 1; j < i; ++j) {
				dp[i * n + j] = obstacleGrid[i][j] ? 0 : (dp[i * n + j - 1] + dp[(i - 1) * n + j]);
				dp[i + n * j] = obstacleGrid[j][i] ? 0 : (dp[i - 1 + n * j] + dp[i + n * (j - 1)]);
			}
			dp[i * n + i] = obstacleGrid[i][i] ? 0 : (dp[i - 1 + i * n] + dp[(i - 1) * n + i]);
		}

		if (m > n) {
			for (int i = k; i < m; ++i) {
				dp[i * n] = obstacleGrid[i][0] ? 0 : dp[(i - 1) * n]; // X axis
				for (int j = 1; j < n; ++j)
					dp[i * n + j] = obstacleGrid[i][j] ? 0 : (dp[i * n + j - 1] + dp[(i - 1) * n + j]);
			}
		} else if (n > m) {
			for (int i = k; i < n; ++i) {
				dp[i] = obstacleGrid[0][i] ? 0 : dp[i - 1]; // Y axis
				for (int j = 1; j < m; ++j)
					dp[i + n * j] = obstacleGrid[j][i] ? 0 : (dp[i - 1 + n * j] + dp[i + n * (j - 1)]);
			}
		}

		auto ret = dp[m * n - 1];
		delete[] dp;
		return ret;
	}
};

int main() {
	std::printf("%d\n", Solution::uniquePathsWithObstacles({{0,1,0,0,0},{1,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}}));
	return 0;
}
