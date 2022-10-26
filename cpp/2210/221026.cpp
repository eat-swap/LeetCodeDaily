#include <unordered_set>
#include <vector>
#include <iostream>

/**
 * 523. Continuous Subarray Sum
 *
 * Given an integer array nums and an integer k, return true if nums has a continuous subarray of size at least two whose elements sum up to a multiple of k, or false otherwise.
 * An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.
 */

class Solution {
public:
	static bool checkSubarraySum(const std::vector<int>& nums, int k) {
		int sum = nums[0] % k, n = nums.size(), prev = 0;
		if (n < 2)
			return false;
		if (k == 1)
			return true;
		if (n == 2)
			return (nums[0] + nums[1]) % k == 0;
		std::unordered_set<int> s{0, nums[0] % k};
		for (int i = 1; i < n; ++i) {
			if (!(nums[i] % k) && !(nums[i - 1] % k))
				return true;
			prev = sum;
			sum = (sum + nums[i]) % k;
			if (s.count(sum) && prev != sum)
				return true;
			s.insert(sum);
		}
		return false;
	}
};

int main() {
	std::cout << Solution::checkSubarraySum({1,2,12}, 6);
	return 0;
}
