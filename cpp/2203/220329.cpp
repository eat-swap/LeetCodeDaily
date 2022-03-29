#include <vector>
#include <bitset>

/**
 * 287. Find the Duplicate Number
 * Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
 * There is only one repeated number in nums, return this repeated number.
 * You must solve the problem without modifying the array nums and uses only constant extra space.
 */

class Solution {
public:
	static int findDuplicate(const std::vector<int>& nums) {
		std::bitset<100008> s;
		for (int i : nums) {
			if (s[i])
				return i;
			s[i] = true;
		}
		return -1;
	}
};
