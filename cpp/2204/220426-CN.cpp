#include <vector>
#include <algorithm>
#include <numeric>

/**
 * 883. Projection Area of 3D Shapes
 * You are given an n x n grid where we place some 1 x 1 x 1 cubes that are axis-aligned with the x, y, and z axes.
 * Each value v = grid[i][j] represents a tower of v cubes placed on top of the cell (i, j).
 * We view the projection of these cubes onto the xy, yz, and zx planes.
 * A projection is like a shadow, that maps our 3-dimensional figure to a 2-dimensional plane. We are viewing the "shadow" when looking at the cubes from the top, the front, and the side.
 * Return the total area of all three projections.
 */

class Solution {
public:
	static int projectionArea(const std::vector<std::vector<int>>& G) {
		const int n = G.size();
		int xy = 0, yz = 0, zx = 0;
		std::for_each(G.begin(), G.end(), [&](const std::vector<int>& v) {
			xy += std::count_if(v.begin(), v.end(), [](int x) { return x > 0; });
			zx += *std::max_element(v.begin(), v.end());
		});
		for (int i = 0; i < n; ++i) {
			int t = 0;
			for (int j = 0; j < n; ++j) {
				t = std::max(t, G[j][i]);
			}
			yz += t;
		}
		return xy + yz + zx;
	}
};
