#include <vector>
#include <cstdio>

/**
 * 39. Combination Sum
 * Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
 * The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
 * It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
 */

class Solution {
public:
	static std::vector<std::vector<int>> combinationSum(const std::vector<int>& candidates, int target, int prev = 0) {
		std::vector<std::vector<int>> ret;
		for (int v : candidates) {
			if (v >= prev && target - v >= v) {
				std::vector<std::vector<int>> t = combinationSum(candidates, target - v, v);
				for (std::vector<int>& i : t) {
					i.push_back(v);
				}
				ret.reserve(ret.size() + t.size());
				ret.insert(ret.end(), t.begin(), t.end());
			} else if (v == target) {
				ret.emplace_back(1, v);
			}
		}
		return ret;
	}
};

int main() {
	auto ret = Solution::combinationSum({2, 3, 5}, 8);
	for (const auto& i : ret) {
		for (auto j : i) {
			std::printf("%d ", j);
		}
		std::printf("\n");
	}
	return 0;
}
