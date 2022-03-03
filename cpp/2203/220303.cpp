#include <iostream>
#include <vector>

/**
 * 413. Arithmetic Slices
 * An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
 * For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
 * Given an integer array nums, return the number of arithmetic subarrays of nums.
 * A subarray is a contiguous subsequence of the array.
 */

class Solution {
public:
	static int numberOfArithmeticSlices(std::vector<int>& args) {
		int n = args.size();
		if (n < 3)
			return 0;
		args.push_back(0xFFFFFFF);
		int prev = args[1], diff = args[1] - args[0], sliceBegin = 0, ret = 0;
		for (int i = 2; i <= n; ++i) {
			if (args[i] - prev != diff) {
				// Last slice terminates at position i - 1
				// Length i - sliceBegin
				int len = i - sliceBegin - 2;
				if (len > 0)
					ret += (len * (1 + len)) >> 1;
				diff = args[i] - prev;
				sliceBegin = i - 1;
			}
			prev = args[i];
		}
		return ret;
	}
};

int main() {
	std::vector<int> args = {1,2,3,8,9,10};
	std::cout << Solution::numberOfArithmeticSlices(args);
	return 0;
}
