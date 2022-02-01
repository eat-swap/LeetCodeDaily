#include <vector>
#include <cstdio>

/**
 * 121. Best Time to Buy and Sell Stock
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.
 * You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
 * Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
 */

class Solution {
public:
	static int maxProfit(const std::vector<int>& prices) {
		int toBuy = 0x7FFFFFFF, ret = 0;
		for (int price : prices) {
			ret = std::max(price - toBuy, ret);
			toBuy = std::min(price, toBuy);
		}
		return ret;
	}
};

int main() {
	std::printf("%d\n", Solution::maxProfit({7,6,4,3,1}));
	return 0;
}
