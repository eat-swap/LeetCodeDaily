#include <iostream>

/**
 * 1220. Count Vowels Permutation
 * Given an integer n, your task is to count how many strings of length n can be formed under the following rules:
 * Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
 * Each vowel 'a' may only be followed by an 'e'.
 * Each vowel 'e' may only be followed by an 'a' or an 'i'.
 * Each vowel 'i' may not be followed by another 'i'.
 * Each vowel 'o' may only be followed by an 'i' or a 'u'.
 * Each vowel 'u' may only be followed by an 'a'.
 * Since the answer may be too large, return it modulo 10^9 + 7.
 */

class Solution {
private:
	static const int mod = 1000000007;
	// dp[currentLength][endsWith]
	// int dp[20005][5]{{}, {1, 1, 1, 1, 1}};
	/**
	 * Rules of assembling characters:
	 * 'a' can be derived from those that ends with 'eiu'.
	 * 'e' <- 'ai'
	 * 'i' <- 'eo'
	 * 'o' <- 'i'
	 * 'u' <- 'io'
	 */
public:
	static int countVowelPermutation(int n) {
		int dp[5]{1, 1, 1, 1, 1}, tmp[5];
		for (int i = 2; i <= n; ++i) {
			// 'a' <- 'eiu'
			tmp[0] = ((dp[1] + dp[2]) % mod + dp[4]) % mod;

			// 'u' <- 'io'
			dp[4] = (dp[2] + dp[3]) % mod;

			// 'e' <- 'ai'
			tmp[1] = (dp[0] + dp[2]) % mod;

			// 'o' <- 'i'
			tmp[3] = dp[2];

			// 'i' <- 'eo'
			dp[2] = (dp[1] + dp[3]) % mod;

			dp[0] = tmp[0];
			dp[1] = tmp[1];
			dp[3] = tmp[3];
		}
		return (((dp[1] + dp[2]) % mod + (dp[3] + dp[4]) % mod) % mod + dp[0]) % mod;
	}
};

int main() {
	Solution solver;
	std::cout << solver.countVowelPermutation(20000);
	return 0;
}