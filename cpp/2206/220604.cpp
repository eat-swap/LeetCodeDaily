#include <vector>
#include <string>
#include <functional>

/**
 * 51. N-Queens
 * The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
 * Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
 * Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
 */

class Solution {
public:
	static std::vector<std::vector<std::string>> solveNQueens(const int n) {
		std::vector<std::vector<std::string>> ret;

		bool xs[10]{}, ds[20]{}, sds[20]{}, G[10][10]{};
		std::function<void(int)> dfs = [&](int d) {
			if (d >= n) {
				std::vector<std::string> ans(n);
				for (int i = 0; i < n; ++i) {
					std::string s(n, ' ');
					for (int j = 0; j < n; ++j)
						s[j] = G[i][j] ? 'Q' : '.';
					ans[i] = s;
				}
				ret.push_back(ans);
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
	auto ret = Solution::solveNQueens(4);
	return 0;
}
