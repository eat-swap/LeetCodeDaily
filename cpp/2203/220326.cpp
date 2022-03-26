#include <vector>
#include <algorithm>

/**
 * 704. Binary Search
 * Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
 * You must write an algorithm with O(log n) runtime complexity.
 */

class Solution {
public:
	static int search(const std::vector<int>& nums, int target) {
		auto it = std::lower_bound(nums.begin(), nums.end(), target);
		return (it == nums.end() || *it != target) ? -1 : std::distance(nums.begin(), it);
	}
};
