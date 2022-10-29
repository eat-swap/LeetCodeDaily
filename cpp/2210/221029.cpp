#include <vector>
#include <set>
#include <utility>
#include <algorithm>

/**
 * 2136. Earliest Possible Day of Full Bloom
 *
 * You have n flower seeds. Every seed must be planted first before it can begin to grow, then bloom. Planting a seed takes time and so does the growth of a seed. You are given two 0-indexed integer arrays plantTime and growTime, of length n each:
 * plantTime[i] is the number of full days it takes you to plant the ith seed. Every day, you can work on planting exactly one seed. You do not have to work on planting the same seed on consecutive days, but the planting of a seed is not complete until you have worked plantTime[i] days on planting it in total.
 * - growTime[i] is the number of full days it takes the ith seed to grow after being completely planted. After the last day of its growth, the flower blooms and stays bloomed forever.
 * - From the beginning of day 0, you can plant the seeds in any order.
 * Return the earliest possible day where all seeds are blooming.
 */

class Solution {
public:
	static int earliestFullBloom(const std::vector<int>& plantTime, const std::vector<int>& growTime) {
		std::multiset<std::pair<int, int>, std::greater<>> s;
		for (int i = 0; i < plantTime.size(); ++i)
			s.insert({growTime[i], plantTime[i]});
		int ans = 0, cur = 0;
		for (const auto& [gt, pt] : s)
			ans = std::max(ans, gt + (cur += pt));
		return ans;
	}
};

int main() {
	Solution::earliestFullBloom({1,2,3,2},{2,1,2,1});
	return 0;
}
