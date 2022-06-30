#include <vector>
#include <algorithm>

/**
 * 406. Queue Reconstruction by Height
 * You are given an array of people, people, which are the attributes of some people in a queue (not necessarily in order). Each people[i] = [hi, ki] represents the ith person of height hi with exactly ki other people in front who have a height greater than or equal to hi.
 * Reconstruct and return the queue that is represented by the input array people. The returned queue should be formatted as an array queue, where queue[j] = [hj, kj] is the attributes of the jth person in the queue (queue[0] is the person at the front of the queue).
 */

class Solution {
public:
	static std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>>& people) {
		std::sort(people.begin(), people.end(), [](const auto& x, const auto& y) {
			return (x[0] == y[0]) ? (x[1] < y[1]) : (x[0] > y[0]);
		});
		std::vector<std::vector<int>> ret;
		ret.reserve(people.size());
		for (const auto& i : people)
			ret.insert(ret.begin() + i[1], i);
		return ret;
	}
};
