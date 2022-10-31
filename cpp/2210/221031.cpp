#include <vector>
#include <algorithm>

/**
 * 766. Toeplitz Matrix
 *
 * Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return false.
 * A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.
 */

class Solution {
public:
	bool isToeplitzMatrix(const std::vector<std::vector<int>>& m) {
		for (int i = 1; i < m.size(); ++i)
			if (!std::equal(m[i].begin() + 1, m[i].end(), m[i - 1].begin()))
				return false;
		return true;
	}
};
