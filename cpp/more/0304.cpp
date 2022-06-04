#include <vector>

/**
 * 304. Range Sum Query 2D - Immutable
 * Given a 2D matrix matrix, handle multiple queries of the following type:
 * Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
 * Implement the NumMatrix class:
 * NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
 * int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
 */

class NumMatrix {
private:
	const int* prefixSum = nullptr;
	int m, n;

public:
	explicit NumMatrix(const std::vector<std::vector<int>>& G) {
		m = G.size();
		n = G.front().size();
		int* p = new int[(m + 1) * (1 + n)]{};
		for (int i = 1; i <= m; ++i)
			for (int j = 1; j <= n; ++j)
				p[i * n + j] = p[(i - 1) * n + j] + p[i * n + j - 1] - p[(i - 1) * n + j - 1] + G[i - 1][j - 1];
		prefixSum = p;
	}

	~NumMatrix() {
		delete[] prefixSum;
	}

	int sumRegion(int x0, int y0, int x1, int y1) {
		x1++;
		y1++;
		return prefixSum[x1 * n + y1] - prefixSum[x0 * n + y1] - prefixSum[x1 * n + y0] + prefixSum[x0 * n + y0];
	}
};
