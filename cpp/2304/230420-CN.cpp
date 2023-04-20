#include <algorithm>
#include <functional>
#include <unordered_map>
#include <vector>
#include <iostream>

/**
 * 1187. Make Array Strictly Increasing
 *
 * Given two integer arrays arr1 and arr2, return the minimum number of operations (possibly zero) needed to make arr1 strictly increasing.
 * In one operation, you can choose two indices 0 <= i < arr1.length and 0 <= j < arr2.length and do the assignment arr1[i] = arr2[j].
 * If there is no way to make arr1 strictly increasing, return -1.
 */

class Solution {
public:
	static int makeArrayIncreasing(const std::vector<int>&, std::vector<int>);
};

int Solution::makeArrayIncreasing(const std::vector<int>& p, std::vector<int> q) {
	std::sort(q.begin(), q.end());
	std::unordered_map<int, int> ans[2048];
	std::function<int(int, int)> dp = [&](int pos, int prev) {
		if (pos >= p.size())
			return 0;
		if (ans[pos].count(prev))
			return ans[pos][prev];
		int ret = 0x7FFFFFFE;
		if (auto it = std::upper_bound(q.begin(), q.end(), prev); it != q.end())
			ret = std::min(ret, dp(pos + 1, *it) + 1);
		if (p[pos] > prev)
			ret = std::min(ret, dp(pos + 1, p[pos]));
		return ans[pos][prev] = ret;
	};
	return dp(0, -1) > 99999 ? -1 : dp(0, -1);
}

int main() {
	std::cout << Solution::makeArrayIncreasing({1,5,3,6,7},{6,3,3,1});
	return 0;
}
