#include <vector>
#include <algorithm>

/**
 * 81. Search in Rotated Sorted Array II
 * There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).
 * Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].
 * Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.
 * You must decrease the overall operation steps as much as possible.
 *
 * Analysis:
 * class Solution has a complexity of O(n).
 * class SolutionBinary has O(n + 2 * log(n)) -> O(n).
 *
 * But which is faster? I sorely have no idea.
 */

class Solution {
public:
	static bool search(const std::vector<int>& nums, int target) {
		return std::any_of(nums.begin(), nums.end(), [&](int x){ return x == target; });
	}
};

class SolutionBinary {
public:
	static bool search(const std::vector<int>& nums, int target) {
		auto it = std::next(nums.begin());
		for (; it != nums.end(); ++it)
			if (*it < *std::prev(it))
				break;
		if (it == nums.end())
			return std::binary_search(nums.begin(), nums.end(), target);
		return std::binary_search(nums.begin(), it, target) || std::binary_search(it, nums.end(), target);
	}
};
