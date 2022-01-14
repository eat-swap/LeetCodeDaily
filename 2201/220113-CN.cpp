#include <vector>
#include <iostream>

/**
 * 747. Largest Number At Least Twice of Others
 * You are given an integer array nums where the largest integer is unique.
 * Determine whether the largest element in the array is at least twice as much as every other number in the array. If it is, return the index of the largest element, or return -1 otherwise.
 */

class Solution {
public:
	static int dominantIndex(const std::vector<int>& nums) {
		int a = 0, b = -1, n = nums.size();
		if (n == 1)
			return 0;
		for (int i = 1; i < n; ++i) {
			if (nums[i] > nums[a]) {
				b = a;
				a = i;
			} else if (b < 0 || nums[i] > nums[b]) {
				b = i;
			}
		}
		if (b < 0 || (nums[a]) < (nums[b] << 1))
			return -1;
		return a;
	}
};

int main() {
	std::cout << Solution::dominantIndex({1, 0});
}