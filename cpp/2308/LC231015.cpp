#include "defs.h"
#include <vector>

constexpr static int MOD = 1'000'000'007;

int LC231015::numWays(int steps, int arrLen) {
	if (arrLen == 1)
		return 1;
	int n = std::min(arrLen, 505);
	int ans[2][512] {{1}, {}};
	for (int cs = 1; cs <= steps; ++cs) {
		ans[cs & 1][0] = (ans[cs & 1 ^ 1][0] + ans[cs & 1 ^ 1][1]) % MOD;
		for (int i = 1; i < n - 1; ++i)
			ans[cs & 1][i] = (
				(ans[cs & 1 ^ 1][i - 1] + ans[(cs & 1) ^ 1][i]) % MOD +
				ans[cs & 1 ^ 1][i + 1]
			) % MOD;
		ans[cs & 1][n - 1] = (ans[cs & 1 ^ 1][n - 2] + ans[cs & 1 ^ 1][n - 1]) % MOD;
	}
	return ans[steps & 1][0];
}

using Solution = LC231015;
