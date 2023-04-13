#include <iterator>
#include <unordered_map>
#include <vector>
#include <algorithm>

/**
 * 2404. Most Frequent Even Element
 *
 * Given an integer array nums, return the most frequent even element.
 * If there is a tie, return the smallest one. If there is no such element, return -1.
 */

class Solution {
	using LL = long long;
public:
	static int mostFrequentEven(const std::vector<int>&);
};

int Solution::mostFrequentEven(const std::vector<int>& n) {
	std::unordered_map<int, int> m;
	std::for_each(n.begin(), n.end(), [&](int x) { if (!(x & 1)) ++m[x]; });
	return m.empty() ? -1 : std::max_element(m.begin(), m.end(), [](auto&& x, auto&& y) {
		auto&& [xk, xs] = x;
		auto&& [yk, ys] = y;
		return (LL(xs) << 32) - xk < (LL(ys) << 32) - yk;
	})->first;
}
