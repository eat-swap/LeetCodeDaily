#include <vector>

/**
 * 1480. Running Sum of 1d Array
 * Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
 */

class Solution {
public:
	static std::vector<int> runningSum(const std::vector<int>& nums) {
		std::vector<int> ret(nums.size());
		ret[0] = nums[0];
		for (int i = 1; i < nums.size(); ++i)
			ret[i] = ret[i - 1] + nums[i];
		return ret;
	}
};
