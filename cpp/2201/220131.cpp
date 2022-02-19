#include <vector>
#include <cstdio>

/**
 * 1672. Richest Customer Wealth
 * You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i-th customer has in the j-th bank. Return the wealth that the richest customer has.
 * A customer's wealth is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum wealth.
 */

class Solution {
public:
	static int maximumWealth(const std::vector<std::vector<int>>& accounts) {
		int ret = 0;
		for (const auto& i : accounts) {
			int t = 0;
			std::for_each(i.begin(), i.end(), [&t](const int& v) { t += v; });
			ret = std::max(t, ret);
		}
		return ret;
	}
};

int main() {
	std::printf("%d\n", Solution::maximumWealth({{1,2,3},{3,2,1}}));
}
