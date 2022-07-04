#include <vector>
#include <set>
#include <algorithm>

/**
 * 1200. Minimum Absolute Difference
 * Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.
 * Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows
 * a, b are from arr
 * a < b
 * b - a equals to the minimum absolute difference of any two elements in arr
 */

class Solution {
public:
	static std::vector<std::vector<int>> minimumAbsDifference(const std::vector<int>& arr) {
		std::set<int> s;
		int min_diff = 0x7FFFFFFF;
		for (int i : arr) {
			const auto [it, ok] = s.insert(i);
			if (!ok)
				continue;
			if (it != s.begin())
				min_diff = std::min(min_diff, std::abs(*std::prev(it) - i));
			if (std::next(it) != s.end())
				min_diff = std::min(min_diff, std::abs(*std::next(it) - i));
		}
		std::vector<std::vector<int>> ret;
		int prev = -0x3FFFFFFF;
		for (int i : s) {
			if (i - prev == min_diff)
				ret.push_back({prev, i});
			prev = i;
		}
		return ret;
	}
};

int main() {
	auto r = Solution::minimumAbsDifference({3,8,-10,23,19,-4,-14,27});
	return 0;
}
