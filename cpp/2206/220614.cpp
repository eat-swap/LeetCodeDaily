#include <string>
#include <cstring>
#include <iostream>
#include <functional>

/**
 * 583. Delete Operation for Two Strings
 * Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.
 * In one step, you can delete exactly one character in either string.
 */

class Solution {
public:
	static int minDistance(const std::string& word1, const std::string& word2) {
		const int n1 = word1.length(), n2 = word2.length();
		int dp[501][501];
		std::memset(dp, -1, sizeof dp);
		std::function<int(int, int)> d = [&](int i, int j) {
			if (i < 0 || j < 0)
				return 0;
			if (dp[i][j] > 0)
				return dp[i][j];
			if (word1[i] == word2[j])
				return dp[i][j] = 1 + d(i - 1, j - 1);
			return dp[i][j] = std::max(d(i - 1, j), d(i, j - 1));
		};
		return n1 + n2 - (d(n1 - 1, n2 - 1) << 1);
	}
};

int main() {
	std::cout << Solution::minDistance("mart", "karma");
	return 0;
}
