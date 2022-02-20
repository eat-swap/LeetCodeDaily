#include <queue>
#include <vector>
#include <cstdio>

/**
 * 1675. Minimize Deviation in Array
 * You are given an array nums of n positive integers.
 * You can perform two types of operations on any element of the array any number of times:
 * If the element is even, divide it by 2.
 * For example, if the array is [1,2,3,4], then you can do this operation on the last element, and the array will be [1,2,3,2].
 * If the element is odd, multiply it by 2.
 * For example, if the array is [1,2,3,4], then you can do this operation on the first element, and the array will be [2,2,3,4].
 * The deviation of the array is the maximum difference between any two elements in the array.
 * Return the minimum deviation the array can have after performing some number of operations.
 */

class Solution {
public:
	static int minimumDeviation(const std::vector<int>& nums) {
		std::priority_queue<int, std::vector<int>, std::less<>> q;
		int min = 0x7FFFFFFF, ret = 0x7FFFFFFF;
		for (int i : nums) {
			q.push(i << (i & 1 ? 1 : 0));
			min = std::min(min, i << (i & 1 ? 1 : 0));
		}
		for (int x; !(1 & (x = q.top())); ) {
			q.pop();
			ret = std::min(ret, x - min);
			min = std::min(min, x >> 1);
			q.push(x >> 1);
		}
		return std::min(ret, q.top() - min);
	}
};

int main() {
	std::printf("%d\n", Solution::minimumDeviation({1,2,3,4}));
	std::printf("%d\n", Solution::minimumDeviation({399, 908, 648, 357, 693, 502, 331, 649, 596, 698}));
//	std::printf("%d", Solution::minimumDeviation({399, 908, 648, 357, 693, 502, 331, 649, 596, 698}));
//	std::printf("%d", Solution::minimumDeviation({399, 908, 648, 357, 693, 502, 331, 649, 596, 698}));
//	std::printf("%d", Solution::minimumDeviation({399, 908, 648, 357, 693, 502, 331, 649, 596, 698}));
//	std::printf("%d", Solution::minimumDeviation({399, 908, 648, 357, 693, 502, 331, 649, 596, 698}));
	return 0;
}
