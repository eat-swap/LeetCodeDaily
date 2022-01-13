#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
	static int findMinArrowShots(std::vector<std::vector<int>>& points) {
		std::sort(points.begin(), points.end(), [](const std::vector<int>& l, const std::vector<int>& r) { return l[1] < r[1]; });
		int ret = 0, n = points.size();
		for (int i = 0, r; i < n;) {
			++ret;
			r = points[i][1];
			while (i < n && points[i][0] <= r)
				++i;
		}
		return ret;
	}
};

int main() {
	std::vector<std::vector<int>> v {{3,9},{7,12},{3,8},{6,8},{9,10},{2,9},{0,9},{3,9},{0,6},{2,8}}; // {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
	std::cout << Solution::findMinArrowShots(v);
	return 0;
}