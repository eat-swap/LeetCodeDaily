#include <vector>
#include <unordered_set>

/**
 * 219. Contains Duplicate II
 *
 * Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
 */

class Solution {
public:
	static bool containsNearbyDuplicate(const std::vector<int>& nums, int k) {
		int n = nums.size();
		std::unordered_set<int> s(nums.begin(), nums.begin() + std::min(k, n));
		if (s.size() != std::min(k, n))
			return true;
		for (int i = k; i < n; ++i) {
			if (s.count(nums[i]))
				return true;
			s.insert(nums[i]);
			s.erase(nums[i - k]);
		}
		return false;
	}
};
