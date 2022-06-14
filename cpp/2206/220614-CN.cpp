#include <vector>
#include <algorithm>

/**
 * 498. Diagonal Traverse
 * Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.
 */

class Solution {
public:
	static std::vector<int> findDiagonalOrder(const std::vector<std::vector<int>>& mat) {
		const int m = mat.size(), n = mat.front().size();
		std::vector<int> ans;
		ans.reserve(m * n);
		for (int i = 0; i < m + n; ++i)
			// if (i & 1) -> from x min to x max (m)
			// else       -> from y min to y max (n)
			if (!(i & 1))
				for (int x = std::min(i, m - 1), y = std::min(n, i - x); y < n && x >= 0; --x, ++y)
					ans.push_back(mat[x][y]);
			else
				for (int y = std::min(i, n - 1), x = std::min(m, i - y); x < m && y >= 0; ++x, --y)
					ans.push_back(mat[x][y]);
		return ans;
	}
};

int main() {
	auto ret = Solution::findDiagonalOrder({{1,2,3},{4,5,6},{7,8,9},{10,11,12}});
	return 0;
}
