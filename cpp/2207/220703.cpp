#include <vector>
#include <algorithm>
#include <iostream>

/**
 * 376. Wiggle Subsequence
 * A wiggle sequence is a sequence where the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.
 * For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences (6, -3, 5, -7, 3) alternate between positive and negative.
 * In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences. The first is not because its first two differences are positive, and the second is not because its last difference is zero.
 * A subsequence is obtained by deleting some elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.
 * Given an integer array nums, return the length of the longest wiggle subsequence of nums.
 */

class Solution {
public:
	static int wiggleMaxLength(const std::vector<int>& nums) {
		const int n = nums.size();
		int dp[2][1024]{{1}, {1}};
		for (int i = 1; i < n; ++i) {
			const int t = nums[i] - nums[i - 1];
			dp[0][i] = t > 0 ? 1 + dp[1][i - 1] : dp[0][i - 1];
			dp[1][i] = t < 0 ? 1 + dp[0][i - 1] : dp[1][i - 1];
		}
		return std::max(dp[0][n - 1], dp[1][n - 1]);
	}
};

int main() {
	std::cout << Solution::wiggleMaxLength({1,17,5,10,13,15,10,5,16,8});
	return 0;
}
