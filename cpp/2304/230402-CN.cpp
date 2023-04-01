#include <vector>

/**
 * 1039. Minimum Score Triangulation of Polygon
 *
 * You have a convex n-sided polygon where each vertex has an integer value. You are given an integer array values where values[i] is the value of the ith vertex (i.e., clockwise order).
 * You will triangulate the polygon into n - 2 triangles. For each triangle, the value of that triangle is the product of the values of its vertices, and the total score of the triangulation is the sum of these values over all n - 2 triangles in the triangulation.
 * Return the smallest possible total score that you can achieve with some triangulation of the polygon.
 */

class Solution {
private:
	std::vector<int> val;
	int n = -1;

	int dp[51][51]{};

	int func(int f, int t) {
		int& ans = dp[f][t];
		if (ans)
			return ans;
		const int d = t - f;
		if (d < 2)
			return 0;
		if (d == 2) {
			ans = val[t];
			for (int i = f; i < t; ++i)
				ans *= val[i];
			return ans;
		}
		ans = 0x7FFFFFFF;
		for (int i = 1 + f, bp = val[f] * val[t]; i < t; ++i)
			ans = std::min(ans, bp * val[i] + func(f, i) + func(i, t));
		return ans;
	}

public:
	int minScoreTriangulation(std::vector<int> values) {
		val = std::move(values);
		n = val.size();
		return func(0, n - 1);
	}
};
