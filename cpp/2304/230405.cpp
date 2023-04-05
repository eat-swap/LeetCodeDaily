#include <iostream>
#include <vector>

/**
 * 2439. Minimize Maximum of Array
 *
 * You are given a 0-indexed array nums comprising of n non-negative integers.
 *
 * In one operation, you must:
 *
 * Choose an integer i such that 1 <= i < n and nums[i] > 0.
 * Decrease nums[i] by 1.
 * Increase nums[i - 1] by 1.
 * Return the minimum possible value of the maximum integer of nums after performing any number of operations.
 */

class Solution {
public:
	static int minimizeArrayValue(const std::vector<int>& nums) {
		const int n = nums.size();
		int ret = 0;
		unsigned long long sum = 0;
		for (int i = 0; i < n; ++i) {
			sum += nums[i];
			ret = std::max(ret, static_cast<int>(sum / (i + 1) + !!(sum % (i + 1))));
		}
		return ret;
	}
};

int main() {
	std::cout << Solution::minimizeArrayValue({3,7,1,6});
	return 0;
}
