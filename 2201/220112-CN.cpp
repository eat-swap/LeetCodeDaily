#include <vector>

/**
 * 334. Increasing Triplet Subsequence
 * Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.
 */

class Solution {
public:
	static bool increasingTriplet(const std::vector<int>& nums) {
		int n = nums.size();
		int overallMinimum = nums[0], solutionMinimum = nums[0], mid = 0x7FFFFFFF;
		for (int i = 1; i < n; ++i) {
			overallMinimum = std::min(overallMinimum, nums[i]);
			if (nums[i] > mid) {
				return true;
			}
			if (nums[i] > overallMinimum && nums[i] <= mid) {
				solutionMinimum = overallMinimum;
				mid = nums[i];
			}
			if (nums[i] > solutionMinimum && nums[i] < mid) {
				mid = nums[i];
			}
		}
		return false;
	}
};

int main() {
	return !Solution::increasingTriplet({2, 1, 5, 0, 4, 6});
}
