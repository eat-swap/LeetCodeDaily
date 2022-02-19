#include <vector>
#include <iostream>

/**
 * 134. Gas Station
 * There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].
 * You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.
 * Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique
 */

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
