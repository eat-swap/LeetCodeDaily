#include <vector>

/**
 * 867. Transpose Matrix
 * Given a 2D integer array matrix, return the transpose of matrix.
 * The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.
 */

class Solution {
public:
	static std::vector<std::vector<int>> transpose(std::vector<std::vector<int>>& matrix) {
		const int m = matrix.size(), n = matrix.front().size();
		std::vector<std::vector<int>> ret(n, std::vector<int>(m));
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				ret[j][i] = matrix[i][j];
		return ret;
	}
};
