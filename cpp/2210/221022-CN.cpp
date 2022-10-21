#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <tuple>
#include <functional>
#include <iostream>

/**
 * 1235. Maximum Profit in Job Scheduling
 *
 * We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].
 * You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.
 * If you choose a job that ends at time X you will be able to start another job that starts at time X.
 */

class Solution {
public:
	static int jobScheduling(const std::vector<int>& st, const std::vector<int>& et, const std::vector<int>& p) {
		std::vector<std::tuple<int, int, int>> info;
		int maxTS;
		{
			std::set<int> s(st.begin(), st.end());
			s.insert(et.begin(), et.end());
			maxTS = s.size();
			int i = 0;
			std::unordered_map<int, int> tm;
			for (const int t : s)
				tm[t] = i++;
			info.reserve(st.size());
			for (int j = st.size(); j--; )
				info.emplace_back(tm[st[j]], tm[et[j]], p[j]);
		}
		std::sort(info.begin(), info.end());

		std::vector<int> psa(maxTS, -1);
		std::function<int(int)> dp = [&](int sp) {
			if (psa[sp] >= 0)
				return psa[sp];
			auto pos = std::lower_bound(info.begin(), info.end(), std::make_tuple(sp, 0, 0));
			if (pos == info.end())
				return psa[sp] = 0;
			int ans = 0, lim = 0x7FFFFFFF;
			for (auto it = pos; it != info.end() && std::get<0>(*it) < lim; ++it) {
				const auto [_, ets, cp] = *it;
				ans = std::max(ans, dp(ets) + cp);
				lim = std::min(lim, ets);
			}
			return psa[sp] = ans;
		};

		return dp(0);
	}
};

int main() {
	std::cout << Solution::jobScheduling({1,2,3,3}, {3,4,5,6}, {50,10,40,70}) << "\n";
	std::cout << Solution::jobScheduling({1,2,3,4,6}, {3,4,10,6,9}, {20,20,100,70,60}) << "\n";
	std::cout << Solution::jobScheduling({1,1,1}, {2,3,4}, {5,6,4}) << "\n";
	return 0;
}
