#include <algorithm>
#include <vector>
#include <unordered_set>

/**
 * 2441. Largest Positive Integer That Exists With Its Negative
 *
 * Given an integer array nums that does not contain any zeros, find the largest positive integer k such that -k also exists in the array.
 * Return the positive integer k. If there is no such integer, return -1.
 */

class LC230513 {
public:
	static int findMaxK(const std::vector<int>&) noexcept;
};

int LC230513::findMaxK(const std::vector<int>& n) noexcept {
	std::unordered_set<int> s(n.begin(), n.end());
	int ret = -1;
	for (int i: s)
		if (s.count(-i))
			ret = std::max(ret, std::abs(i));
	return ret;
}
