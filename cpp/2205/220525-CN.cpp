#include <string>
#include <numeric>

/**
 * 467. Unique Substrings in Wraparound String
 * We define the string s to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so s will look like this:
 * "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
 * Given a string p, return the number of unique non-empty substrings of p are present in s.
 */

class Solution {
public:
	static int findSubstringInWraproundString(const std::string& p) {
		int dp[26]{}, k = 0;
		for (int i = 0; i < p.length(); ++i)
			dp[p[i] - 'a'] = std::max(dp[p[i] - 'a'], k = 1 + ((i && (p[i] - p[i - 1] + 26) % 26 == 1) ? k : 0));
		return std::accumulate(dp, dp + 26, 0);
	}
};
