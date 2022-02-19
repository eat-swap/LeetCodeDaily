#include <iostream>
#include <vector>
#include <cstring>

/**
 * 1463. Cherry Pickup II
 * You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.
 * You have two robots that can collect cherries for you:
 * Robot #1 is located at the top-left corner (0, 0), and
 * Robot #2 is located at the top-right corner (0, cols - 1).
 * Return the maximum number of cherries collection using both robots by following the rules below:
 * From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
 * When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
 * When both robots stay in the same cell, only one takes the cherries.
 * Both robots cannot move outside of the grid at any moment.
 * Both robots should reach the bottom row in grid.
 *
 * Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
 * Output: 24
 * Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
 * Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
 * Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
 * Total of cherries: 12 + 12 = 24.
 */

class Solution {
private:
	int dp[2][70][70];
public:
	int cherryPickup(const std::vector<std::vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();

		// Set as -INF
		std::memset(this->dp, 0xC0, sizeof this->dp);
		this->dp[0][0][n - 1] = grid[0][0] + grid[0][n - 1];
		for (int i = 1; i < m; ++i) { // i <- row
			for (int j = 0; j < n; ++j) { // j <- col of robot 1
				for (int k = 0; k < n; ++k) { // k <- robot 2
					int thisPick = (j == k) ? (grid[i][j]) : (grid[i][j] + grid[i][k]);
					dp[i & 1][j][k] = std::max(dp[i & 1][j][k], dp[(i & 1) ^ 1][j][k] + thisPick);
					if (k > 0)
						dp[i & 1][j][k] = std::max(dp[i & 1][j][k], dp[(i & 1) ^ 1][j][k - 1] + thisPick);
					if (k < n - 1)
						dp[i & 1][j][k] = std::max(dp[i & 1][j][k], dp[(i & 1) ^ 1][j][k + 1] + thisPick);
					if (j > 0) {
						dp[i & 1][j][k] = std::max(dp[i & 1][j][k], dp[(i & 1) ^ 1][j - 1][k] + thisPick);
						if (k > 0)
							dp[i & 1][j][k] = std::max(dp[i & 1][j][k], dp[(i & 1) ^ 1][j - 1][k - 1] + thisPick);
						if (k < n - 1)
							dp[i & 1][j][k] = std::max(dp[i & 1][j][k], dp[(i & 1) ^ 1][j - 1][k + 1] + thisPick);
					}
					if (j < n - 1) {
						dp[i & 1][j][k] = std::max(dp[i & 1][j][k], dp[(i & 1) ^ 1][j + 1][k] + thisPick);
						if (k > 0)
							dp[i & 1][j][k] = std::max(dp[i & 1][j][k], dp[(i & 1) ^ 1][j + 1][k - 1] + thisPick);
						if (k < n - 1)
							dp[i & 1][j][k] = std::max(dp[i & 1][j][k], dp[(i & 1) ^ 1][j + 1][k + 1] + thisPick);
					}
				}
			}
		}
		int ret = -(0x7FFFFFFF) - 1;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				ret = std::max(ret, dp[(m ^ 1) & 1][i][j]);
		return ret;
	}
};

int main() {
	Solution solver{};
	auto ret = solver.cherryPickup({{1,0,0,0,0,0,1},{2,0,0,0,0,3,0},{2,0,9,0,0,0,0},{0,3,0,5,4,0,0},{1,0,2,3,0,0,6}});
	std::cout << ret;
	return 0;
}