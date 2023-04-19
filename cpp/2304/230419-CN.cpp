#include <algorithm>
#include <iostream>
#include <vector>

/**
 * 1043. Partition Array for Maximum Sum
 *
 * Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.
 * Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.
 */

class Solution {
private:
	int dp[512]{};
	const std::vector<int>* ptr = nullptr;
	int k = 0;

	int d(int pos) noexcept;

public:
	int maxSumAfterPartitioning(const std::vector<int>&, int) noexcept;
};

int Solution::maxSumAfterPartitioning(const std::vector<int>& arr, int k) noexcept {
	this->ptr = &arr;
	this->k = k;
	return d(0);
}

int Solution::d(int pos) noexcept {
	if (pos >= ptr->size())
		return 0;
	auto& ans = dp[pos];
	if (ans)
		return ans;
	for (int i = 0, m = 0; i < k; ++i) {
		int c_pos = pos + i;
		if (c_pos >= ptr->size())
			break;
		m = std::max(m, ptr->operator[](i + pos));
		ans = std::max(ans, m * (i + 1) + d(pos + i + 1));
	}
	return ans;
}

int main() {
	Solution s;
	std::cout << s.maxSumAfterPartitioning(
		{1,15,7,9,2,5,10},
		3
	);
	return 0;
}