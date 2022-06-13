#include <vector>
#include <algorithm>
#include <iostream>

/**
 * 120. Triangle
 * Given a triangle array, return the minimum path sum from top to bottom.
 * For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
 */

class Solution {
public:
	static int minimumTotal(std::vector<std::vector<int>>& triangle) {
		const int m = triangle.size();
		for (int i = 1; i < m; ++i) {
			auto& t = triangle[i];
			const auto& p = triangle[i - 1];
			const int n = t.size();
			t[0] += p[0];
			for (int j = 1; j < n - 1; ++j) {
				t[j] += std::min(p[j - 1], p[j]);
			}
			t[n - 1] += p[n - 2];
		}
		return *std::min_element(triangle.back().begin(), triangle.back().end());
	}
};

int main() {
	std::vector<std::vector<int>> a {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
	std::cout << Solution::minimumTotal(a);

	return 0;
}
