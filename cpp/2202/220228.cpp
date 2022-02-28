#include <vector>
#include <string>
#include <iostream>

typedef long long LL;

/**
 * 228. Summary Ranges
 * You are given a sorted unique integer array nums.
 * Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.
 * Each range [a,b] in the list should be output as:
 * - "a->b" if a != b
 * - "a" if a == b
 */

class Solution {
public:
	static std::vector<std::string> summaryRanges(const std::vector<int>& nums) {
		if (nums.empty())
			return {};
		std::vector<std::string> ret;
		int prev = nums[0], intStart = nums[0];
		for (int i : nums) {
			if (LL(i) - LL(prev) > 1) {
				if (intStart == prev)
					ret.push_back(std::to_string(intStart));
				else
					ret.push_back(std::to_string(intStart) + "->" + std::to_string(prev));
				intStart = i;
			}
			prev = i;
		}
		if (intStart == nums.back())
			ret.push_back(std::to_string(intStart));
		else
			ret.push_back(std::to_string(intStart) + "->" + std::to_string(nums.back()));
		return ret;
	}
};

int main() {
	auto ret = Solution::summaryRanges({0,2,3,4,6,8,9});
	for (const auto& i : ret) {
		std::cout << i << std::endl;
	}
	return 0;
}
