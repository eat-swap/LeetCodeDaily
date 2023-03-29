#include <vector>
#include <algorithm>

/**
 * 1402. Reducing Dishes
 *
 * A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.
 * Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].
 * Return the maximum sum of like-time coefficient that the chef can obtain after dishes preparation.
 * Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.
 */

class Solution {
public:
	static int maxSatisfaction(const std::vector<int>& sa) {
		const int n = sa.size();
		std::vector<int> s(n);
		std::partial_sort_copy(sa.begin(), sa.end(), s.begin(), s.end());
		int ans = std::max(0, s[n - 1]);
		for (int i = n - 2, cur = s[n - 1]; i >= 0; --i)
			ans = std::max(ans, cur += (s[i] += s[i + 1]));
		return ans;
	}
};

int main() {
	Solution::maxSatisfaction({-1,-8,0,5,-9});
	return 0;
}
