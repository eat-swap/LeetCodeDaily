#include <vector>
#include <cstdio>

/**
 * 969. Pancake Sorting
 * Given an array of integers arr, sort the array by performing a series of pancake flips.
 * In one pancake flip we do the following steps:
 * Choose an integer k where 1 <= k <= arr.length.
 * Reverse the sub-array arr[0...k-1] (0-indexed).
 * For example, if arr = [3,2,1,4] and we performed a pancake flip choosing k = 3, we reverse the sub-array [3,2,1], so arr = [1,2,3,4] after the pancake flip at k = 3.
 * Return an array of the k-values corresponding to a sequence of pancake flips that sort arr. Any valid answer that sorts the array within 10 * arr.length flips will be judged as correct.
 */

class Solution {
public:
	static std::vector<int> pancakeSort(std::vector<int>& arr) {
		std::vector<int> ret;
		int n = arr.size();
		ret.reserve(n << 1);
		for (int i = n; i; --i) {
			auto intervalLast = std::next(arr.begin(), i);
			auto maxElement = std::max_element(arr.begin(), intervalLast);
			ret.push_back(1 + std::distance(arr.begin(), maxElement));
			ret.push_back(i);
			std::reverse(arr.begin(), std::next(maxElement));
			std::reverse(arr.begin(), intervalLast);
		}
		return ret;
	}
};

int main() {
	std::vector<int> args = {1,2,3};
	auto ret = Solution::pancakeSort(args);
	for (int i : ret) {
		std::printf("%d ", i);
	}
	return 0;
}
