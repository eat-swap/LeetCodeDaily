#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

/**
 * 983. Minimum Cost For Tickets
 *
 * You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.
 *
 * Train tickets are sold in three different ways:
 *
 * a 1-day pass is sold for costs[0] dollars,
 * a 7-day pass is sold for costs[1] dollars, and
 * a 30-day pass is sold for costs[2] dollars.
 * The passes allow that many days of consecutive travel.
 *
 * For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
 * Return the minimum number of dollars you need to travel every day in the given list of days.
 */

class Solution {
public:
	static int mincostTickets(const std::vector<int>& d, const std::vector<int>& c) {
		int dp[400]{};
		std::vector<bool> vis(400);
		std::for_each(d.begin(), d.end(), [&vis](int x) { vis[x] = true; });
		for (int i = 365; i; --i) {
			if (!vis[i]) {
				dp[i] = dp[i + 1];
			} else {
				dp[i] = std::min(dp[i + 1] + c[0], dp[i + 7] + c[1]);
				dp[i] = std::min(dp[i], dp[i + 30] + c[2]);
			}
		}
		return dp[1];
	}
};

int main() {
	std::cout << Solution::mincostTickets(
		{1,2,3,4,5,6,7,8,9,10,30,31},
		{2,7,15}
	);
	return 0;
}
