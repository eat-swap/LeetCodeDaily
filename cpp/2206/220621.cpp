#include <vector>
#include <queue>
#include <iostream>

/**
 * 1642. Furthest Building You Can Reach
 * You are given an integer array heights representing the heights of buildings, some bricks, and some ladders.
 * You start your journey from building 0 and move to the next building by possibly using bricks or ladders.
 * While moving from building i to building i+1 (0-indexed),
 * If the current building's height is greater than or equal to the next building's height, you do not need a ladder or bricks.
 * If the current building's height is less than the next building's height, you can either use one ladder or (h[i+1] - h[i]) bricks.
 * Return the furthest building index (0-indexed) you can reach if you use the given ladders and bricks optimally.
 */

class Solution {
public:
	static int furthestBuilding(const std::vector<int>& h, int bricks, int ladders) {
		const int n = h.size();
		std::priority_queue<int, std::vector<int>, std::greater<>> q;
		int sum = 0;
		for (int i = 1; i < n; ++i) {
			if (h[i] - h[i - 1] <= 0)
				continue;
			q.push(h[i] - h[i - 1]);
			if (q.size() > ladders) {
				sum += q.top();
				q.pop();
			}
			if (sum > bricks)
				return i - 1;
		}
		return n - 1;
	}
};

int main() {
	std::cout << Solution::furthestBuilding({4,2,7,6,9,14,12}, 5, 1) << "\n";
	std::cout << Solution::furthestBuilding({4,12,2,7,3,18,20,3,19}, 10, 2) << "\n";
	std::cout << Solution::furthestBuilding({14,3,19,3}, 17, 0) << "\n";
	return 0;
}
