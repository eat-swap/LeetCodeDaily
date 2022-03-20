#include <vector>

/**
 * 2044. Count Number of Maximum Bitwise-OR Subsets
 * Given an integer array nums, find the maximum possible bitwise OR of a subset of nums and return the number of different non-empty subsets with the maximum bitwise OR.
 * An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b. Two subsets are considered different if the indices of the elements chosen are different.
 * The bitwise OR of an array a is equal to a[0] OR a[1] OR ... OR a[a.length - 1] (0-indexed).
 */

class Solution {
public:
	static int countMaxOrSubsets(const std::vector<int>& nums) {
		int maxOr = 0;
		for (int i : nums)
			maxOr |= i;
		int n = nums.size(), LIM = 1 << n, ret = 0;
		for (int i = 1; i < LIM; ++i) {
			int ans = 0;
			for (int j = 0; j < n; ++j)
				ans |= ((1 << j) & i) ? nums[j] : 0;
			ret += ans == maxOr;
		}
		return ret;
	}
};
