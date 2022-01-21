#include <vector>
#include <iostream>

class Solution {
public:
	static int canCompleteCircuit(const std::vector<int>& gas, const std::vector<int>& cost) {
		int n = gas.size(), min = 0x7FFFFFFF, minPos = -1, sum = 0;
		for (int i = 0; i < n; ++i) {
			if ((sum += gas[i] - cost[i]) < min) {
				min = sum;
				minPos = i;
			}
		}
		if (sum < 0)
			return -1;
		return (minPos + 1) % n;
	}
};

int main() {
	std::cout << Solution::canCompleteCircuit({2,3,4}, {3,4,3});
	return 0;
}
