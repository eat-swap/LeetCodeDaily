#include <iterator>
#include <vector>
#include <algorithm>

/**
 * 1431. Kids With the Greatest Number of Candies
 *
 * There are n kids with candies. You are given an integer array candies, where each candies[i] represents the number of candies the ith kid has, and an integer extraCandies, denoting the number of extra candies that you have.
 * Return a boolean array result of length n, where result[i] is true if, after giving the ith kid all the extraCandies, they will have the greatest number of candies among all the kids, or false otherwise.
 * Note that multiple kids can have the greatest number of candies.
 */

class Solution {
public:
	static std::vector<bool> kidsWithCandies(const std::vector<int>&, int);
};

std::vector<bool> Solution::kidsWithCandies(const std::vector<int>& c, int ec) {
	std::vector<bool> ret;
	int max = *std::max_element(c.begin(), c.end());
	std::transform(c.begin(), c.end(), std::back_inserter(ret), [&](int x) { return x + ec >= max; });
	return ret;
}
