#include <vector>

/**
 * 64. Minimum Path Sum
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
 * Note: You can only move either down or right at any point in time.
 */

class Solution {
public:
	static int minPathSum(std::vector<std::vector<int>>& G) {
		const int m = G.size(), n = G.front().size();
		for (int i = m - 1; i >= 0; --i)
			for (int j = n - 1; j >= 0; --j)
				G[i][j] +=
					(i + 1 < m && j + 1 < n) ?
					std::min(G[i + 1][j], G[i][j + 1]) :
					((i + 1 < m ? G[i + 1][j] : 0) + (j + 1 < n ? G[i][j + 1] : 0));
		return G[0][0];
	}
};
