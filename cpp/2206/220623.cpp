#include <vector>
#include <queue>
#include <algorithm>

/**
 * 630. Course Schedule III
 * There are n different online courses numbered from 1 to n. You are given an array courses where courses[i] = [duration[i], lastDay[i]] indicate that the ith course should be taken continuously for durationi days and must be finished before or on lastDayi.
 * You will start on the 1st day and you cannot take two or more courses simultaneously.
 * Return the maximum number of courses that you can take.
 */

class Solution {
public:
	static int scheduleCourse(std::vector<std::vector<int>>& c) {
		std::sort(c.begin(), c.end(), [](const auto& x, const auto& y) {
			return x[1] < y[1];
		});
		std::priority_queue<int> q;
		int t = 0;
		for (const auto& x : c) {
			if (t + x[0] <= x[1]) {
				q.push(x[0]);
				t += x[0];
			} else if (!q.empty() && q.top() > x[0]) {
				t += x[0] - q.top();
				q.pop();
				q.push(x[0]);
			}
		}
		return q.size();
	}
};
