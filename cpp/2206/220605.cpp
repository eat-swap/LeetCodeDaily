#include <functional>

/**
 * 52. N-Queens II
 * The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
 * Given an integer n, return the number of distinct solutions to the n-queens puzzle.
 */

class Solution {
public:
	static int totalNQueens(int n) {
		int ret = 0;

		bool xs[10]{}, ds[20]{}, sds[20]{}, G[10][10]{};
		std::function<void(int)> dfs = [&](int d) {
			if (d >= n) {
				++ret;
				return;
			}
			for (int i = 0; i < n; ++i) {
				if (xs[i] || ds[d - i + 10] || sds[d + i])
					continue;
				G[d][i] = xs[i] = ds[d - i + 10] = sds[d + i] = true;
				dfs(1 + d);
				G[d][i] = xs[i] = ds[d - i + 10] = sds[d + i] = false;
			}
		};

		dfs(0);

		return ret;
	}
};

int main() {
	auto ret = Solution::totalNQueens(4);
	return 0;
}
