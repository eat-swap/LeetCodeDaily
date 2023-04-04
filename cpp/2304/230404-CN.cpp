#include <vector>

/**
 * 1000. Minimum Cost to Merge Stones
 *
 * There are n piles of stones arranged in a row. The ith pile has stones[i] stones.
 * A move consists of merging exactly k consecutive piles into one pile, and the cost of this move is equal to the total number of stones in these k piles.
 * Return the minimum cost to merge all piles of stones into one pile. If it is impossible, return -1.
 */

class Solution {
public:
	static int mergeStones(const std::vector<int>& stones, int k) {
		const int n = stones.size();
		if (n == 1)
			return 0;
		if (n < k || k != 2 && (n % (k - 1)) != 1)
			return -1;
		int pSum[35]{ stones[0] };
		for (int i = 1; i < n; ++i)
			pSum[i] = pSum[i - 1] + stones[i];
		int dp[35][35]{};
		std::memset(dp, 0x3F, sizeof dp);
		for (int i = 0; i < n; ++i)
			dp[i][i] = 0;
		for (int len = 2; len <= n; ++len) {
			for (int L = 0; L < n && L + len <= n; ++L) {
				int R = L + len - 1; // inclusive
				for (int M = L; M < R; M += k - 1)
					dp[L][R] = std::min(dp[L][M] + dp[M + 1][R], dp[L][R]);
				if (0 == (R - L) % (k - 1))
					dp[L][R] += pSum[R] - (L ? pSum[L - 1] : 0);
			}
		}
		return dp[0][n - 1];
	}
};
