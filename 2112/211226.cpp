#include <vector>
#include <algorithm>

struct EuclideanDistanceCompare {
	bool operator()(const std::vector<int>& lhs, const std::vector<int>& rhs) const {
		return lhs[0] * lhs[0] + lhs[1] * lhs[1] < rhs[0] * rhs[0] + rhs[1] * rhs[1];
	}
};

class Solution {
public:
	static std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
		std::sort(points.begin(), points.end(), EuclideanDistanceCompare{});
		return {points.begin(), points.begin() + k};
	}
};

int main() {
	std::vector<std::vector<int>> s = {
			{3, 3},
			{5, -1},
			{-2, 4}
	};
	auto ret = Solution::kClosest(s, 2);
	for (const auto& i : ret)
		std::printf("%d, %d\n", i[0], i[1]);
	return 0;
}