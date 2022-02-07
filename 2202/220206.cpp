#include <vector>
#include <iostream>

/**
 * 80. Remove Duplicates from Sorted Array II
 * Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.
 * Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.
 * Return k after placing the final result in the first k slots of nums.
 * Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
 */

class Solution {
public:
	static int removeDuplicates(std::vector<int>& nums) {
		int prev, dup = 0;
		for (auto it = nums.begin(); it != nums.end();) {
			if (*it != prev) {
				dup = 1;
				prev = *(it++);
			} else if (++dup >= 3) {
				it = nums.erase(it, std::upper_bound(nums.begin(), nums.end(), *it));
			} else {
				++it;
			}
		}
		return nums.size();
	}
};

int main() {
	std::vector<int> args {1,1,1,2,2,3};
	std::cout << Solution::removeDuplicates(args) << std::endl;
	for (int i : args) {
		std::cout << i << ' ';
	}
	return 0;
}
