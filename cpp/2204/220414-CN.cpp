/**
 * 1672. Richest Customer Wealth
 * You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i-th customer has in the j-th bank. Return the wealth that the richest customer has.
 * A customer's wealth is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum wealth.
 *
 * Refer: 2201/220131.cpp
 * 100% STL implementation this time!
 */

#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
	static int maximumWealth(const std::vector<std::vector<int>>& accounts) {
		int ret = 0;
		std::for_each(accounts.cbegin(), accounts.cend(), [&](const std::vector<int>& x) { ret = std::max(ret, std::accumulate(x.cbegin(), x.cend(), 0)); });
		return ret;
	}
};
