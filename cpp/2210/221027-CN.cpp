#include <vector>

/**
 * 1822. Sign of the Product of an Array
 *
 * There is a function signFunc(x) that returns:
 * - 1 if x is positive.
 * - -1 if x is negative.
 * - 0 if x is equal to 0.
 * You are given an integer array nums. Let product be the product of all values in the array nums.
 * Return signFunc(product).
 */

class Solution {
private:
	static constexpr int sgn(int n) {
		return n ? ((n >> 31) | 1) : 0;
	}

public:
	static int arraySign(const std::vector<int>& nums) {
		const int MASK = 0xFFFFFFFE, n = nums.size();
		int ans = sgn(nums[0]);
		if (!ans)
			return 0;
		for (int i = 1; i < n; ++i) {
			switch (sgn(nums[i])) {
				case 0:
					return 0;
				case -1:
					ans ^= MASK;
			}
		}
		return ans;
	}
};
