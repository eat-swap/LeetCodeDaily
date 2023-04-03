#include <algorithm>
#include <iterator>
#include <vector>

/**
 * 1053. Previous Permutation With One Swap
 * Given an array of positive integers arr (not necessarily distinct), return the lexicographically largest permutation that is smaller than arr, that can be made with exactly one swap. If it cannot be done, then return the same array.
 * Note that a swap exchanges the positions of two numbers arr[i] and arr[j]
 */

class Solution {
public:
	std::vector<int> prevPermOpt1(std::vector<int> arr) {
		if (std::is_sorted(arr.begin(), arr.end()))
			return arr;
		const int n = arr.size();
		for (int i = n - 2; i >= 0; --i) {
			if (arr[i] <= arr[i + 1])
				continue;
			int j = n - 1;
			for (; arr[j] >= arr[i] || arr[j] == arr[j - 1]; --j);
			std::swap(arr[i], arr[j]);
			return arr;
		}
		// Should not reach here
		return arr;
	}
};
