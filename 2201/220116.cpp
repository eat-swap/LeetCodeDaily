#include <iostream>
#include <vector>

/**
 * 849. Maximize Distance to Closest Person
 * You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat, and seats[i] = 0 represents that the ith seat is empty (0-indexed).
 * There is at least one empty seat, and at least one person sitting.
 * Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized.
 * Return that maximum distance to the closest person.
 */

class Solution {
public:
	static int maxDistToClosest(const std::vector<int>& seats) {
		int pos = 0;
		for (; !seats[pos]; ++pos);

		// pos is now the 1st '1'.
		int ret = pos, prev = pos, n = seats.size();
		for (++pos; pos < n; ++pos) {
			if (seats[pos]) {
				ret = ret > (pos - prev) >> 1 ? ret : (pos - prev) >> 1;
				prev = pos;
			}
		}
		return std::max(ret, n - 1 - prev);
	}
};

int main() {
	std::printf("%d\n", Solution::maxDistToClosest({1, 0, 0, 0, 1, 0, 1}));
	return 0;
}