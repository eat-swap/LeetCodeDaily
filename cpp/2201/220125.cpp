#include <vector>
#include <algorithm>
#include <cstdio>

/**
 * 941. Valid Mountain Array
 * Given an array of integers arr, return true if and only if it is a valid mountain array.
 * Recall that arr is a mountain array if and only if:
 *  - arr.length >= 3
 *  - There exists some i with 0 < i < arr.length - 1 such that:
 *    - arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
 *    - arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
 */

class Solution {
public:
	static bool validMountainArray(const std::vector<int>& arr) {
		return std::max_element(arr.begin(), arr.end()) != arr.end() - 1 && std::max_element(arr.begin(), arr.end()) != arr.begin() && std::adjacent_find(arr.begin(), std::max_element(arr.begin(), arr.end()), std::greater_equal<>()) == std::max_element(arr.begin(), arr.end()) && std::adjacent_find(std::max_element(arr.begin(), arr.end()), arr.end(), std::less_equal<>()) == arr.end();
	}
};

int main() {
	std::printf("%s\n", Solution::validMountainArray({0, 3, 2, 1}) ? "true" : "false");
	return 0;
}
