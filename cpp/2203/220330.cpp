#include <vector>
#include <algorithm>

/**
 * 74. Search a 2D Matrix
 * Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
 * - Integers in each row are sorted from left to right.
 * - The first integer of each row is greater than the last integer of the previous row.
 */

class Solution {
public:
	static bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target) {
		auto it = std::upper_bound(matrix.begin(), matrix.end(), std::vector<int>{target}, [](const std::vector<int>& x, const std::vector<int>& y) {
			return x.front() < y.front();
		});
		if (it == matrix.begin())
			return false;
		it = std::prev(it);
		return std::binary_search(it->begin(), it->end(), target);
	}
};
