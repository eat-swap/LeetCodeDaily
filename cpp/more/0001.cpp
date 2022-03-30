#include <vector>
#include <unordered_set>

/**
 * 1. Two Sum
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * You can return the answer in any order.
 */

class Solution {
public:
	static std::vector<int> twoSum(const std::vector<int>& nums, int target) {
		std::unordered_multiset<int> s(nums.begin(), nums.end());
		for (int i : s) {
			if (s.count(target - i) > (i == target - i ? 1 : 0)) {
				int x = 0, y = nums.size() - 1;
				while (nums[x] != i)
					++x;
				while (nums[y] != target - i)
					--y;
				return {x, y};
			}
		}
		return {};
	}
};
