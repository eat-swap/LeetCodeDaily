#include <vector>
#include <numeric>
#include <algorithm>

/**
 * 462. Minimum Moves to Equal Array Elements II
 * Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.
 * In one move, you can increment or decrement an element of the array by 1.
 * Test cases are designed so that the answer will fit in a 32-bit integer.
 */

class Solution {
public:
	static int minMoves2(std::vector<int>& nums) {
		int psum = 0, ssum = std::accumulate(nums.begin(), nums.end(), 0);
		long long ans = 0x7FFFFFFF;
		const int n = nums.size();
		std::sort(nums.begin(), nums.end());
		for (int i = 0; i < n; ++i) {
			const long long t = nums[i];
			ssum -= t;
			ans = std::min(ans, t * (i - n + i + 1) + ssum - psum);
			psum += t;
		}
		return ans;
	}
};
