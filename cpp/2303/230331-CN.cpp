#include <unordered_set>
#include <vector>
#include <algorithm>

/**
 * 2367. Number of Arithmetic Triplets
 *
 * You are given a 0-indexed, strictly increasing integer array nums and a positive integer diff. A triplet (i, j, k) is an arithmetic triplet if the following conditions are met:
 *
 * i < j < k,
 * nums[j] - nums[i] == diff, and
 * nums[k] - nums[j] == diff.
 * Return the number of unique arithmetic triplets.
 */

class Solution {
public:
	static int arithmeticTriplets(const std::vector<int>& nums, int diff) {
		std::unordered_set<int> s(nums.begin(), nums.end());
		return std::count_if(nums.begin(), nums.end(), [&](int x) {
			return s.count(x + diff) && s.count(x + 2 * diff);
		});
	}
};
