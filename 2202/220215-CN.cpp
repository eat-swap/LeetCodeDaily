#include <vector>
#include <cstdio>

/**
 * 1380. Lucky Numbers in a Matrix
 * Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.
 * A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.
 */

class Solution {
public:
	static std::vector<int> luckyNumbers (const std::vector<std::vector<int>>& matrix) {
		int m = matrix.size(), n = m ? matrix.front().size() : 0;
		std::vector<int> rowMin(m), colMax(n, -0x7FFFFFFF);
		for (int i = 0; i < m; ++i)
			rowMin[i] = *std::min_element(matrix[i].begin(), matrix[i].end());
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				colMax[i] = std::max(matrix[j][i], colMax[i]);

		std::vector<int> ret;
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				if (matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j])
					ret.push_back(matrix[i][j]);
		return ret;
	}
};

int main() {
	const auto ret = Solution::luckyNumbers({{3,7,8},{9,11,13},{15,16,17}});
	for (int i : ret) {
		std::printf("%d ", i);
	}
	return 0;
}
