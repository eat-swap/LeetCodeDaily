#include <cstdio>
#include <cstring>

/**
 * 688. Knight Probability in Chessboard
 * On an n x n chessboard, a knight starts at the cell (row, column) and attempts to make exactly k moves. The rows and columns are 0-indexed, so the top-left cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).
 * A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.
 */

class Solution {
private:
	inline static constexpr int dX[] = {-2, -1, 1, 2, 2, 1, -1, -2};
	inline static constexpr int dY[] = {1, 2, 2, 1, -1, -2, -2, -1};

	inline static constexpr bool isValid(int n, int x, int y) {
		return x >= 0 && y >= 0 && x < n && y < n;
	}
public:
	inline static constexpr double knightProbability(int n, int k, int row, int column) {
		double dp[25][25], dpNext[25][25];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				dp[i][j] = 1.0;
		for (int i = 0; i < k; ++i) {
			for (int x = 0; x < n; ++x) {
				for (int y = 0; y < n; ++y) {
					dpNext[x][y] = 0.0;
					for (int idx = 0; idx < 8; ++idx) {
						if (isValid(n, x + dX[idx], y + dY[idx])) {
							dpNext[x][y] += dp[x + dX[idx]][y + dY[idx]];
						}
					}
					dpNext[x][y] /= 8.0;
				}
			}
			std::memcpy(dp, dpNext, sizeof dp);
		}
		return dp[row][column];
	}
};

int main() {
	std::printf("%lf\n", Solution::knightProbability(3, 2, 0, 0));
	return 0;
}
