#include <algorithm>
#include <vector>

/**
 * 1984. Minimum Difference Between Highest and Lowest of K Scores
 * You are given a 0-indexed integer array nums, where nums[i] represents the score of the ith student. You are also given an integer k.
 * Pick the scores of any k students from the array so that the difference between the highest and the lowest of the k scores is minimized.
 * Return the minimum possible difference.
 */

class Solution {
public:
	int minimumDifference(std::vector<int>& nums, int k) {
		std::sort(nums.begin(), nums.end());
		int ans = 99999999;
		for (int i = k; i <= nums.size(); ++i)
			ans = std::min(ans, nums[i - 1] - nums[i - k]);
		return ans;
	}
};

int main() {
	// Submitted by phone, no test provided.
	return 0;
}
