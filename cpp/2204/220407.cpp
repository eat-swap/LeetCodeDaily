#include <vector>
#include <queue>
#include <iostream>

/**
 * 1046. Last Stone Weight
 * You are given an array of integers stones where stones[i] is the weight of the ith stone.
 *
 * We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:
 *
 * If x == y, both stones are destroyed, and
 * If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
 * At the end of the game, there is at most one stone left.
 *
 * Return the smallest possible weight of the left stone. If there are no stones left, return 0.
 */

class Solution {
public:
	static int lastStoneWeight(const std::vector<int>& stones) {
		std::priority_queue<int> q(stones.begin(), stones.end());
		while (q.size() > 1) {
			int x = q.top();
			q.pop();
			x = std::abs(q.top() - x);
			q.pop();
			if (x)
				q.push(x);
		}
		return q.empty() ? 0 : q.top();
	}
};

int main() {
	std::cout << Solution::lastStoneWeight({1, 3});
	return 0;
}
