#include <vector>

/**
 * 2016. Maximum Difference Between Increasing Elements
 * Given a 0-indexed integer array nums of size n, find the maximum difference between nums[i] and nums[j] (i.e., nums[j] - nums[i]), such that 0 <= i < j < n and nums[i] < nums[j].
 * Return the maximum difference. If no such i and j exists, return -1.
 */

class Solution {
public:
	static int maximumDifference(const std::vector<int>& nums) {
		int ret = -1;
		int s[1005]{}, pos = 0;
		for (int i : nums) {
			for (; pos && s[pos - 1] > i; pos--)
				ret = std::max(s[pos - 1] - s[0], ret);
			s[pos++] = i;
		}
		ret = std::max(ret, pos ? s[pos - 1] - s[0] : -1);
		return ret ? ret : -1;
	}
};

int main() {
	Solution::maximumDifference({9,4,3,2});
	return 0;
}
