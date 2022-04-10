#include <algorithm>
#include <vector>

/**
 * 31. Next Permutation
 *
 * Description too long, but it was 100% what the STL implements.
 */

class Solution {
public:
	static inline void nextPermutation(std::vector<int>& nums) {
		std::next_permutation(nums.begin(), nums.end());
	}
};
