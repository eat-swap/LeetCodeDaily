#include <vector>
#include <algorithm>

/**
 * 215. Kth Largest Element in an Array
 * Given an integer array nums and an integer k, return the kth largest element in the array.
 * Note that it is the kth largest element in the sorted order, not the kth distinct element.
 */

class Solution {
public:
	int findKthLargest(std::vector<int>& nums, int k) {
		std::nth_element(nums.begin(), nums.begin() + (k - 1), nums.end(), std::greater<>());
		return nums[k - 1];
	}
};
