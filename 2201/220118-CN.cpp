#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

/**
 * 539. Minimum Time Difference
 * Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
 */

class Solution {
public:
	static int findMinDifference(std::vector<std::string>& timePoints) {
		std::sort(timePoints.begin(), timePoints.end());
		int h1, m1, h2, m2, min = 1441, n = timePoints.size();
		std::sscanf(timePoints[0].c_str(), "%d:%d", &h1, &m1);
		std::sscanf(timePoints.back().c_str(), "%d:%d", &h2, &m2);
		min = (h1 - h2 + 24) * 60 + (m1 - m2);
		for (int i = 1; i < n; ++i) {
			std::sscanf(timePoints[i].c_str(), "%d:%d", &h2, &m2);
			min = std::min(min, (h2 - h1) * 60 + (m2 - m1));
			h1 = h2;
			m1 = m2;
		}
		return min;
	}
};

int main() {
	std::vector<std::string> args {"00:00", "23:59", "00:00"};
	std::cout << Solution::findMinDifference(args);
	return 0;
}