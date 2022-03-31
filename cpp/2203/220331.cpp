#include <vector>
#include <iostream>

/**
 * 410. Split Array Largest Sum
 * Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.
 * Write an algorithm to minimize the largest sum among these m subarrays.
 */

class Solution {
private:
	// dp[remaining][startPoint]
	int dp[51][1002]{};
	int prefixSum[1002]{};
	int n = -1;
	const std::vector<int>* num = nullptr;

	// [remaining] segments to split,
	// from [startPoint] (inclusive) to the end.
	int d(int remaining, int startPoint) {
		if (dp[remaining][startPoint])
			return dp[remaining][startPoint];
		if (remaining <= 1)
			return dp[1][startPoint] = prefixSum[n - 1] - (startPoint ? prefixSum[startPoint - 1] : 0);
		// We should make sure that we will never
		// let remaining < n - startPoint.
		// nextRemaining <- remaining - 1;
		// from startPoint + 1, while i + nextRemaining < n;
		int currentSum = num->at(startPoint), ret = 0x7FFFFFFF;
		for (int i = 1 + startPoint; i + remaining - 1 <= n; ++i) {
			ret = std::min(ret, std::max(currentSum, d(remaining - 1, i)));
			currentSum += num->at(i);
		}
		return dp[remaining][startPoint] = ret;
	}

public:
	int splitArray(const std::vector<int>& nums, int m) {
		std::vector<int> processed;
		processed.reserve(nums.size() / 2);
		for (int i : nums)
			if (i)
				processed.push_back(i);
		n = processed.size();
		if (!n)
			return 0;
		num = &processed;
		m = std::min(m, n);
		prefixSum[0] = processed[0];
		for (int i = 1; i < n; ++i)
			prefixSum[i] = prefixSum[i - 1] + processed[i];
		return d(m, 0);
	}
};

int main() {
	Solution s;
	std::cout << s.splitArray({7,2,5,10,8}, 2);
	// std::cout << s.splitArray({1,2,3,4,5}, 2);
	// std::cout << s.splitArray({1,4,4}, 3);
	return 0;
}
