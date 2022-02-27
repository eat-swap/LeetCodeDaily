#include <vector>
#include <string>
#include <iostream>

/**
 * 553. Optimal Division
 * You are given an integer array nums. The adjacent integers in nums will perform the float division.
 * For example, for nums = [2,3,4], we will evaluate the expression "2/3/4".
 * However, you can add any number of parenthesis at any position to change the priority of operations. You want to add these parentheses such the value of the expression after the evaluation is maximum.
 * Return the corresponding expression that has the maximum value in string format.
 * Note: your expression should not contain redundant parenthesis.
 */

class Solution {
public:
	static std::string optimalDivision(const std::vector<int>& nums) {
		int n = nums.size();
		if (n == 1)
			return std::to_string(nums[0]);
		else if (n == 2)
			return std::to_string(nums[0]) + "/" + std::to_string(nums[1]);
		std::string ret = std::to_string(nums[0]) + "/(";
		for (int i = 1; i < n; ++i) {
			ret += std::to_string(nums[i]) + "/";
		}
		ret.back() = ')';
		return ret;
	}
};

int main() {
	std::cout << Solution::optimalDivision({1000, 100, 10, 2});
	return 0;
}
