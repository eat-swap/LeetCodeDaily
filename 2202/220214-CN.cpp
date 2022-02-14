#include <vector>
#include <cstdio>

/**
 * 540. Single Element in a Sorted Array
 * You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
 * Return the single element that appears only once.
 * Your solution must run in O(log n) time and O(1) space.
 */

class Solution {
public:
	static int singleNonDuplicate(const std::vector<int>& nums) {
		int L = 0, R = nums.size();
		if (R == 1)
			return nums[0];

		// Interval [L, R)
		while (R - L > 1) {
			int M = (L + R) >> 1;
			if (nums[M] == nums[M ^ 1]) {
				L = 1 + (M | 1);
			} else {
				R = (M & (~1)) + 1;
			}
		}

		return nums[L];
	}
};

int main() {
	std::printf("%d\n", Solution::singleNonDuplicate({1,1,2,3,3}));
	return 0;
}
