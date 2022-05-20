#include <vector>
#include <cstdio>
#include <tuple>
#include <algorithm>

/**
 * 436. Find Right Interval
 * You are given an array of intervals, where intervals[i] = [starti, endi] and each starti is unique.
 * The right interval for an interval i is an interval j such that startj >= endi and startj is minimized. Note that i may equal j.
 * Return an array of right interval indices for each interval i. If no right interval exists for interval i, then put -1 at index i.
 */

class Solution {
public:
	static std::vector<int> findRightInterval(const std::vector<std::vector<int>>& intervals) {
		std::vector<std::tuple<int, int, int>> s;
		for (int i = 0; i < intervals.size(); ++i) {
			s.emplace_back(intervals[i][0], intervals[i][1], i);
		}
		std::sort(s.begin(), s.end());

		std::vector<int> ret(intervals.size());
		for (const auto& [f, t, id] : s) {
			auto it = std::lower_bound(s.begin(), s.end(), std::tuple<int, int, int>{t, -0x7FFFFFFF, -0x7FFFFFFF});
			if (it == s.end())
				ret[id] = -1;
			else
				ret[id] = std::get<2>(*it);
		}
		return ret;
	}
};

int main() {
	auto r = Solution::findRightInterval({{-100,-98},{-99,-97},{-98,-96},{-97,-95}});
	for (int i : r) {
		std::printf("%d ", i);
	}
	return 0;
}
