#include <vector>
#include <unordered_set>

struct tripletHash {
	std::size_t operator()(const std::vector<int>& v) const {
		return (size_t(v[0]) << 36) ^ (size_t(v[1]) << 18) ^ size_t(v[2]);
	}
};

class Solution {
public:
	static std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
		std::vector<std::vector<int>> ret;
		std::sort(nums.begin(), nums.end());
		std::unordered_set<int> s(nums.begin(), nums.end());
		for (auto it = std::upper_bound(nums.begin(), nums.end(), 0); it != nums.end(); ++it)
			for (auto it2 = std::next(it); it2 != nums.end(); ++it2)
				if (s.count(-(*it + *it2)))
					ret.push_back({-(*it + *it2), *it, *it2});
		for (auto it = nums.begin(), lim = std::lower_bound(nums.begin(), nums.end(), 0); it != lim; ++it)
			for (auto it2 = std::next(it); it2 != lim; ++it2)
				if (s.count(-(*it + *it2)))
					ret.push_back({*it, *it2, -(*it + *it2)});
		if (s.count(0))
			for (auto it = std::upper_bound(nums.begin(), nums.end(), 0); it != nums.end(); ++it)
				if (s.count(-*it))
					ret.push_back({-*it, 0, *it});
		if (3 <= std::distance(std::lower_bound(nums.begin(), nums.end(), 0), std::upper_bound(nums.begin(), nums.end(), 0)))
			ret.push_back({0, 0, 0});
		std::unordered_set<std::vector<int>, tripletHash> retSet(ret.begin(), ret.end());
		return {retSet.begin(), retSet.end()};
	}
};

int main() {
	std::vector<int> args = {1,1,-2};
	auto ret = Solution::threeSum(args);
	return 0;
}
