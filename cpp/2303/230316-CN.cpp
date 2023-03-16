#include <vector>
#include <unordered_map>
#include <iostream>

/**
 * 2488. Count Subarrays With Median K
 *
 * You are given an array nums of size n consisting of distinct integers from 1 to n and a positive integer k.
 *
 * Return the number of non-empty subarrays in nums that have a median equal to k.
 *
 * Note:
 *
 * The median of an array is the middle element after sorting the array in ascending order. If the array is of even length, the median is the left middle element.
 * For example, the median of [2,3,1,4] is 2, and the median of [8,4,3,5,1] is 4.
 * A subarray is a contiguous part of an array.
 */

class Solution {
private:
	static inline constexpr int sgn(int x) { return (x > 0) - (x < 0); }

public:
	static int countSubarrays(const std::vector<int>& nums, int k) {
		const int n = nums.size(), pos = std::find(nums.begin(), nums.end(), k) - nums.begin();
		std::vector<int> prefix(n);
		prefix[0] = sgn(nums[0] - k);
		for (int i = 1; i < n; ++i)
			prefix[i] = prefix[i - 1] + sgn(nums[i] - k);
		std::unordered_map<int, int> m;
		for (int i = 0; i < pos; ++i)
			++m[prefix[i]];
		++m[0];
		int ans = 0;
		for (int i = pos; i < n; ++i)
			ans += m[prefix[i]] + m[prefix[i] - 1];
		return ans;
	}
};

int main() {
	std::cout << Solution::countSubarrays({3,2,1,4,5}, 4);
	return 0;
}
