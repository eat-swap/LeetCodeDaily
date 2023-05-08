#include <vector>

/**
 * 1572. Matrix Diagonal Sum
 *
 * Given a square matrix mat, return the sum of the matrix diagonals.
 * Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.
 */

class LC230508 {
public:
	static int diagonalSum(const std::vector<std::vector<int>>&) noexcept;
};

int LC230508::diagonalSum(const std::vector<std::vector<int>>& mat) noexcept {
	const int n = mat.size();
	int ret = 0;
	for (int i = 0; i < n; ++i)
		ret += mat[i][i] + mat[i][n - 1 - i];
	return ret - (n & 1 ? mat[n >> 1][n >> 1] : 0);
}
