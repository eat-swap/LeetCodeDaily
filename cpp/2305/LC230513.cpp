#include <algorithm>

/**
 * 2466. Count Ways To Build Good Strings
 *
 * Given the integers zero, one, low, and high, we can construct a string by starting with an empty string, and then at each step perform either of the following:
 *
 * Append the character '0' zero times.
 * Append the character '1' one times.
 * This can be performed any number of times.
 *
 * A good string is a string constructed by the above process having a length between low and high (inclusive).
 *
 * Return the number of different good strings that can be constructed satisfying these properties. Since the answer can be large, return it modulo 109 + 7.
 */

class LC230513 {
public:
	static int countGoodStrings(int, int, int, int) noexcept;
};

int LC230513::countGoodStrings(int low, int high, int zero, int one) noexcept {
	static constexpr int mod = 1'000'000'007;
	int* dp = new int[high + 5]{1};
	for (int i = zero; i < one; ++i)
		dp[i] = dp[i - zero];
	for (int i = one; i < zero; ++i)
		dp[i] = dp[i - one];
	for (int i = std::max(zero, one); i <= high; ++i)
		dp[i] = (dp[i - zero] + dp[i - one]) % mod;
	int ret = 0;
	for (int i = low; i <= high; ++i)
		ret = (ret + dp[i]) % mod;
	delete[] dp;
	return ret;
}

using Solution = LC230513;
