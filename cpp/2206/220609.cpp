#include <vector>
#include <algorithm>

/**
 * 167. Two Sum II - Input Array Is Sorted
 * Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
 * Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
 * The tests are generated such that there is exactly one solution. You may not use the same element twice.
 * Your solution must use only constant extra space.
 */

class Solution {
public:
	std::vector<int> twoSum(const std::vector<int>& numbers, int target) {
		for (int i = 0; numbers[i] <= target - numbers[i]; ++i) {
			int pos = std::lower_bound(numbers.begin() + i + 1, numbers.end(), target - numbers[i]) - numbers.begin();
			if (pos == numbers.size() || numbers[pos] + numbers[i] != target)
				continue;
			return {i + 1, pos + 1};
		}
		return {};
	}
};
