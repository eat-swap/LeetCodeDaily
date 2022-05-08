#include <vector>
#include <bitset>

/**
 * 442. Find All Duplicates in an Array
 * Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.
 * You must write an algorithm that runs in O(n) time and uses only constant extra space.
 */

class Solution {
public:
	static std::vector<int> findDuplicates(const std::vector<int>& nums) {
		std::bitset<100001> s;
		std::vector<int> v;
		v.reserve(nums.size());
		for (auto i : nums) {
			if (s.test(i))
				v.push_back(i);
			else
				s.set(i);
		}
		return v;
	}
};
