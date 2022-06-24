#include <vector>
#include <queue>
#include <numeric>
#include <iostream>

/**
 * 1354. Construct Target Array With Multiple Sums
 * You are given an array target of n integers. From a starting array arr consisting of n 1's, you may perform the following procedure :
 * - let x be the sum of all elements currently in your array.
 * - choose index i, such that 0 <= i < n and set the value of arr at index i to x.
 * - You may repeat this procedure as many times as needed.
 * Return true if it is possible to construct the target array from arr, otherwise, return false.
 */

class Solution {
public:
	static bool isPossible(const std::vector<int>& target) {
		if (target.size() == 1 && target[0] != 1)
			return false;

		std::priority_queue<int> q(target.begin(), target.end());
		auto sum = std::accumulate(target.begin(), target.end(), 0LL);
		while (q.top() > 1) {
			long long x = q.top();
			q.pop();
			long long y = q.top(), delta = sum - x;

			if (x - delta < 1)
				return false;
			long long nx = x - ((x - y) / delta + ((x - y) % delta ? 1 : 0)) * delta;
			if (nx < 1)
				nx += delta;
			q.push(nx);
			sum = sum - x + nx;
		}
		return true;
	}
};

int main() {
	std::cout << Solution::isPossible({1,1,10});
	return 0;
}
