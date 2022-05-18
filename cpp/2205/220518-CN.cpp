#include <cstdio>

/**
 * 668. Kth Smallest Number in Multiplication Table
 * Nearly everyone has used the Multiplication Table. The multiplication table of size m x n is an integer matrix mat where mat[i][j] == i * j (1-indexed).
 * Given three integers m, n, and k, return the kth smallest element in the m x n multiplication table.
 */

class Solution {
public:
	static constexpr int findKthNumber(int m, int n, int k) {
		auto compute = [&](int upper_bound) {
			int ans = 0;
			for (int i = 1; i <= m; ++i)
				ans += (upper_bound / i <= n) ? (upper_bound / i) : n;
			return ans;
		};
		int L = 1, R = m * n, M;

		// [L, R]
		while (L < R) {
			M = (L + R) >> 1;
			int x = compute(M);
			if (x > k) {
				R = M;
			} else if (x < k) {
				L = M + 1;
			} else {
				break;
			}
		}

		M = (L + R + 1) >> 1;
		for (int c = compute(M), p; (p = compute(M - 1)) >= k || p == c; --M);
		return M;
	}
};

int main() {
	std::printf("%d\n", Solution::findKthNumber(2, 3 ,6));
	return 0;
}
