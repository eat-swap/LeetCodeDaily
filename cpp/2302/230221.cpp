#include <vector>
#include <iostream>

/**
 * 540. Single Element in a Sorted Array
 *
 * You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
 * Return the single element that appears only once.
 * Your solution must run in O(log n) time and O(1) space.
 */

class Solution {
public:
	static int singleNonDuplicate(const std::vector<int>& nums) {
		int L = 0, R = nums.size() >> 1; // inclusive
		while (L < R) {
			int M = (L + R) >> 1;
			if (nums[(M << 1) | 1] - nums[M << 1]) R = M;
			else L = M + 1;
		}
		return nums[L << 1];
	}
};

int main() {
	std::cout << Solution::singleNonDuplicate({3,3,7,7,10,11,11});
	return 0;
}
