#include <vector>
#include <cstdio>

/**
 * 78. Subsets
 * Given an integer array nums of unique elements, return all possible subsets (the power set).
 * The solution set must not contain duplicate subsets. Return the solution in any order.
 */

class Solution {
public:
	static std::vector<std::vector<int>> subsets(const std::vector<int>& nums) {
		int s = (1 << nums.size()), n = nums.size();
		std::vector<std::vector<int>> ret(s);
		for (int i = 0; i < s; ++i) {
			std::vector<int>& t = ret[i];
			t.reserve(n);
			for (int j = 0; j < n; ++j)
				if (i & (1 << j))
					t.push_back(nums[j]);
		}
		return ret;
	}
};

int main() {
	const auto ret = Solution::subsets({1,2,3});
	for (const auto& i : ret) {
		for (const auto& j : i) {
			std::printf("%d ", j);
		}
		std::printf("\n");
	}
	return 0;
}
