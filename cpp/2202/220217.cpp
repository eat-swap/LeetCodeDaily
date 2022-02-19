#include <vector>
#include <cstdio>

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
