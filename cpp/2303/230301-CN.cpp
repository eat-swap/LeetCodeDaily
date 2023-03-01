#include <vector>

/**
 * 2373. Largest Local Values in a Matrix
 *
 * You are given an n x n integer matrix grid.
 *
 * Generate an integer matrix maxLocal of size (n - 2) x (n - 2) such that:
 *
 * maxLocal[i][j] is equal to the largest value of the 3 x 3 matrix in grid centered around row i + 1 and column j + 1.
 * In other words, we want to find the largest value in every contiguous 3 x 3 matrix in grid.
 *
 * Return the generated matrix.
 */

class Solution {
public:
	static std::vector<std::vector<int>> largestLocal(const std::vector<std::vector<int>>& grid) {
		const int n = grid.size(), t = n - 2;
		auto ret = std::vector<std::vector<int>>(t, std::vector<int>(t));
		for (int i = 0; i < t; ++i)
			for (int j = 0; j < t; ++j)
				for (int k = 0; k < 3; ++k)
					for (int l = 0; l < 3; ++l)
						ret[i][j] = std::max(ret[i][j], grid[i + k][j + l]);
		return ret;
	}
};
