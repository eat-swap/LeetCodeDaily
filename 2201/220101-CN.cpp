#include <vector>
#include <cstdio>

class Solution {
public:
	static std::vector<std::vector<int>> construct2DArray(std::vector<int>& original, int m, int n) {
		if (m * n != original.size()) return {};
		std::vector<std::vector<int>> ret;
		ret.reserve(m);
		for (int i = 0; i < m; ++i) {
			ret.emplace_back(original.begin() + (i * n), original.begin() + ((1 + i) * n));
		}
		return ret;
	}
};

int main() {
	std::vector<int> s {1, 2};
	const auto ret = Solution::construct2DArray(s, 1, 1);
	for (const auto& i : ret) {
		for (const auto& j : i) {
			std::printf("%d ", j);
		}
		std::printf("\n");
	}
	return 0;
}
