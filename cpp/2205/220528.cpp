#include <vector>

/**
 * 268. Missing Number
 * Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
 */

class Solution {
public:
	int missingNumber(const std::vector<int>& nums) {
		int ans = 0;
		for (int i = 1; i <= nums.size(); ++i)
			ans ^= i ^ nums[i - 1];
		return ans;
	}
};
