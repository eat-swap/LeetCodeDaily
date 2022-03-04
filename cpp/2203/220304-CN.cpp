#include <vector>
#include <iostream>

/**
 * 2104. Sum of Subarray Ranges
 * You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.
 * Return the sum of all subarray ranges of nums.
 * A subarray is a contiguous non-empty sequence of elements within an array.
 */

class Solution {
private:
	static inline constexpr int MAX(int x, int y) {
		return x > y ? x : y;
	}

	static inline constexpr int MIN(int x, int y) {
		return x < y ? x : y;
	}
	
public:
	static long long subArrayRanges(const std::vector<int>& nums) {
		long long ret = 0;
		int n = nums.size(), min, max;
		for (int i = 1; i < n; ++i) {
			ret += (max = MAX(nums[i - 1], nums[i])) - (min = MIN(nums[i - 1], nums[i]));
			for (int j = i + 1; j < n; ++j)
				ret += (max = MAX(nums[j], max)) - (min = MIN(nums[j], min));
		}
		return ret;
	}
};

int main() {
	std::cout << Solution::subArrayRanges({4,-2,-3,4,1});
	return 0;
}
