#include <vector>
#include <queue>
#include <iostream>

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
