#include <vector>
#include <unordered_set>

/**
 * 2395. Find Subarrays With Equal Sum
 *
 * Given a 0-indexed integer array nums, determine whether there exist two subarrays of length 2 with equal sum. Note that the two subarrays must begin at different indices.
 * Return true if these subarrays exist, and false otherwise.
 * A subarray is a contiguous non-empty sequence of elements within an array.
 */

class Solution {
public:
	static bool findSubarrays(const std::vector<int>& nums) {
		const int n = nums.size();
		std::unordered_set<int> s;
		for (int i = 1; i < n; ++i)
			if (s.count(nums[i] + nums[i - 1]))
				return true;
			else
				s.insert(nums[i] + nums[i - 1]);
		return false;
	}
};
