#include <vector>
#include <numeric>
#include <cstdio>
#include <algorithm>

/**
 * 396. Rotate Function
 * You are given an integer array nums of length n.
 * Assume arrk to be an array obtained by rotating nums by k positions clock-wise. We define the rotation function F on nums as follow:
 * F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1].
 * Return the maximum value of F(0), F(1), ..., F(n-1).
 * The test cases are generated so that the answer fits in a 32-bit integer.
 */

class Solution {
public:
	static int maxRotateFunction(const std::vector<int>& nums) {
		const int sum = std::accumulate(nums.begin(), nums.end(), 0), n = nums.size();
		int val = 0, ret = 0;
		for (int i = 0; i < n; ++i) {
			val += i * nums[i];
		}
		ret = val;
		std::printf("%d\n", val);
		for (int i = 1; i < n; ++i) {
			val = val - sum + n * nums[i - 1];
			std::printf("%d\n", val);
			ret = std::max(ret, val);
		}
		return ret;
	}
};

int main() {
	std::printf("\n\n%d\n", Solution::maxRotateFunction({4, 3, 2, 6}));
	return 0;
}
