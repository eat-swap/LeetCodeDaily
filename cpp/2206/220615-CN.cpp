#include <vector>
#include <algorithm>

/**
 * 719. Find K-th Smallest Pair Distance
 * The distance of a pair of integers a and b is defined as the absolute difference between a and b.
 * Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.
 */

class Solution {
public:
	static int smallestDistancePair(std::vector<int>& nums, int k) {
		const int n = nums.size();
		std::sort(nums.begin(), nums.end());
		int L = 0, R = nums.back();
		while (L < R) {
			int M = (L + R) >> 1;
			int i = 0, c = 0;
			for (int j = 0; j < n; ++j) {
				while (nums[j] - nums[i] > M)
					++i;
				c += j - i;
			}
			if (c >= k)
				R = M;
			else
				L = M + 1;
		}
		return L;
	}
};
