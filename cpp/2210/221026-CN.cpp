#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

/**
 * 862. Shortest Subarray with Sum at Least K
 *
 * Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.
 * A subarray is a contiguous part of an array.
 */

class Solution {
public:
	static int shortestSubarray(const std::vector<int>& nums, int k) {
		const int n = nums.size();
		auto ans = unsigned(-1);
		long long s[100008]{0}, sum = 0;
		int t[100008]{-1}, pos = 1;
		for (int i = 0; i < n; ++i) {
			// pos -> i, current -> sum + nums[i]
			sum += nums[i];
			// Check whether it has OK solution
			if (nums[i] > 0) {
				auto it = std::upper_bound(s, s + pos, sum - k);
				if (it == s + pos || it != s && *it > sum - k)
					--it;
				if (*it <= sum - k && 1 == (ans = std::min(ans, unsigned(i - t[it - s]))))
					return 1;
			}
			while (pos && s[pos - 1] >= sum)
				--pos;
			s[pos] = sum;
			t[pos++] = i;
		}
		return int(ans);
	}
};

int main() {
	std::cout << Solution::shortestSubarray({2, -1, 2}, 3);
}
