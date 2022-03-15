#include <vector>

class Solution {
public:
	static int countMaxOrSubsets(const std::vector<int>& nums) {
		int maxOr = 0;
		for (int i : nums)
			maxOr |= i;
		int n = nums.size(), LIM = 1 << n, ret = 0;
		for (int i = 1; i < LIM; ++i) {
			int ans = 0;
			for (int j = 0; j < n; ++j)
				ans |= ((1 << j) & i) ? nums[j] : 0;
			ret += ans == maxOr;
		}
		return ret;
	}
};
