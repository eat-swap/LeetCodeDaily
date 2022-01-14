#include <vector>
#include <algorithm>
#include <iostream>

/**
 * 452. Minimum Number of Arrows to Burst Balloons
 * There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. You do not know the exact y-coordinates of the balloons.
 * Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.
 * Given the array points, return the minimum number of arrows that must be shot to burst all balloons.
 */

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