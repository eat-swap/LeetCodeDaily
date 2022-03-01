#include <vector>
#include <cstdio>

/**
 * 338. Counting Bits
 * Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
 */

class Solution {
public:
	static std::vector<int> countBits(int n) {
		std::vector<int> ans(n + 1);
		for (int i = 0; i <= n; ++i)
			ans[i] = __builtin_popcount(i);
		return ans;
	}
};

int main() {
	auto ret = Solution::countBits(5);
	for (int i : ret)
		std::printf("%d ", i);
	return 0;
}
