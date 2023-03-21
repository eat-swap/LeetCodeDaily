#include <vector>
#include <iostream>

/**
 * 2348. Number of Zero-Filled Subarrays
 *
 * Given an integer array nums, return the number of subarrays filled with 0.
 * A subarray is a contiguous non-empty sequence of elements within an array.
 */

class Solution {
private:
	static constexpr long long f(long long x) {
		return x * (x + 1) / 2;
	}

public:
	static long long zeroFilledSubarray(const std::vector<int>& n) {
		long long ans = 0;
		int c = 0;
		for (int i : n) {
			if (i) {
				ans += f(c);
				c = 0;
			} else ++c;
		}
		return ans + f(c);
	}
};

int main() {
	std::cout << Solution::zeroFilledSubarray({2,10,2019});
	return 0;
}
