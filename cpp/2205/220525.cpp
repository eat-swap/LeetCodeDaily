#include <vector>
#include <algorithm>

/**
 * 354. Russian Doll Envelopes
 * You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.
 * One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.
 * Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
 * Note: You cannot rotate an envelope.
 */

class Solution {
public:
	static int maxEnvelopes(std::vector<std::vector<int>>& e) {
		std::sort(e.begin(), e.end(), [](const std::vector<int>& x, const std::vector<int>& y) {
			return (x[0] == y[0]) ? (x[1] > y[1]) : (x[0] < y[0]);
		});
		std::vector<int> ans;
		std::for_each(e.begin(), e.end(), [&](const std::vector<int>& x) {
			// Put this into list
			int idx = std::lower_bound(ans.begin(), ans.end(), x[1]) - ans.begin();
			if (idx >= ans.size())
				ans.push_back(x[1]);
			else
				ans[idx] = x[1];
		});
		return ans.size();
	}
};
