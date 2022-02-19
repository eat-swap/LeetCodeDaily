#include <iostream>
#include <vector>
#include <map>
#include <cstring>

/**
 * Usage of dynamic programming
 *
 * Initial attempt:
 * try to merge 2 arrays which is calculated before.
 * [3, 1, 7] => 49; [5, 8] => 48
 * [3, 1, 7, 5, 8] => 501
 * dp[L][R] <- max{merge(dp[L][L + i], dp[L + i + 1][R])}
 *
 * Why it fails:
 * Since the solution might be in a completely shuffled
 * order, making the previous results useless.
 *
 * How the solution solved it:
 * The solution iterates from smaller intervals to
 * larger intervals.
 * dp[L][R] <- max{dp[L][L + i - 1] + dp[L + i + 1][R] + n[L + i] * n[L - 1] * n[R + 1]}
 *
 * Why solution works?
 * In my previous attempt, There is no information such as
 * *Which one is eliminated the first [Elimination Order]?*
 * thus the order to eliminate remains unknown.
 * The solution iterates *the last number to eliminate*,
 * avoided to consider the order. (by brute force)
 *
 */

class Solution {
public:
	static int maxCoins(const std::vector<int>& nums) {
		const auto n = nums.size();
		int num[n + 2];
		std::memcpy(num + 1, &nums[0], n * sizeof(int));
		num[0] = num[n + 1] = 1;

		int dp[n + 2][n + 2];
		std::memset(dp, 0, sizeof dp);
		for (int i = 1; i <= n; ++i)
			dp[i][i] = num[i - 1] * num[i] * num[i + 1];
		dp[0][0] = num[1];
		dp[n + 1][n + 1] = num[n];

		for (int interval = 2; interval <= n; ++interval)
			for (int L = 1, R = interval; R <= n; ++L, ++R)
				for (int M = L; M <= R; ++M)
					dp[L][R] = std::max(dp[L][R], dp[L][M - 1] + dp[M + 1][R] + num[M] * num[L - 1] * num[R + 1]);

		return dp[1][n];
	}
};

std::map<std::vector<int>, int> m;
int cnt = 0;

int bruteForce(const std::vector<int>& nums) {
	if (m[nums]) { return m[nums]; }
	++cnt;
	if (nums.size() == 1)
		return nums[0];
	else if (nums.empty())
		return 0;
	int ret = -1;
	for (auto it = nums.begin(); it != nums.end(); ++it) {
		std::vector<int> d(nums.begin(), it);
		d.insert(d.end(), it + 1, nums.end());
		int t = (*it * (it == nums.begin() ? 1 : *(it - 1)) * ((it + 1 == nums.end()) ? 1 : *(it + 1))) + bruteForce(d);
		ret = (t > ret) ? t : ret;
	}
	return m[nums] = ret;
}

int betterBruteForce(const std::vector<int>& nums, int append) {
	return 0;
}

int main() {
	// 3, 1, 5, 87, 9 --> 4101
	// 3, 1, 5, 87, 9, 51 --> 63102
	srand(time(nullptr));
	const int LIM = 15;
	std::vector<int> s;
	s.reserve(LIM);
	for (int i = 0; i < LIM; ++i) {
		s.push_back(rand() % 100 + 1);
	}
	std::printf("%d\n", Solution::maxCoins(s));
	std::printf("%d\n", bruteForce(s));
	std::printf("Count = %d\n", cnt);
	return 0;
}