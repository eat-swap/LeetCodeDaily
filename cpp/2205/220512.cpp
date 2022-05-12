#include <vector>
#include <algorithm>
#include <cstdio>

/**
 * 47. Permutations II
 * Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
 */

class Solution {
public:
	static std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
		std::sort(nums.begin(), nums.end());
		std::vector<std::vector<int>> ret {nums};
		while (std::next_permutation(nums.begin(), nums.end())) {
			ret.push_back(nums);
		}
		return ret;
	}
};

int main() {
	std::vector<int> arg {1, 1, 2};
	auto r = Solution::permuteUnique(arg);
	for (const auto& i : r) {
		for (const auto& j : i) {
			std::printf("%d ", j);
		}
		std::putchar('\n');
	}
	return 0;
}
