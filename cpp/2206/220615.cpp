#include <utility>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <tuple>
#include <functional>

/**
 * 1048. Longest String Chain
 * You are given an array of words where each word consists of lowercase English letters.
 * wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.
 * For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
 * A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.
 * Return the length of the longest possible word chain with words chosen from the given list of words.
 */

class Solution {
private:
	static bool LT(const std::string& x, const std::string& y) {
		if (y.length() - x.length() != 1)
			return false;
		bool ok = false;
		for (int i = 0, j = 0; i < x.length(); ++i, ++j) {
			if (x[i] == y[j])
				continue;
			if (ok)
				return false;
			ok = true;
			--i;
		}
		return true;
	}

public:
	static int longestStrChain(const std::vector<std::string>& words) {
		const int n = words.size();
		bool state[1001][1001]{};
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (LT(words[i], words[j]))
					state[i][j] = true;
		// {id, level}
		int dp[1001]{};
		std::function<int(int)> d = [&](int start) {
			if (dp[start])
				return dp[start];
			int ret = 1;
			for (int j = 0; j < n; ++j)
				if (state[start][j])
					ret = std::max(ret, 1 + d(j));
			return dp[start] = ret;
		};
		int ans = 1;
		for (int i = 0; i < n; ++i)
			ans = std::max(ans, d(i));
		return ans;
	}
};

int main() {
	// std::cout << (StrCount("ba") < StrCount("bda")) << "\n";
	std::cout << Solution::longestStrChain({"qyssedya","pabouk","mjwdrbqwp","vylodpmwp","nfyqeowa","pu","paboukc","qssedya","lopmw","nfyqowa","vlodpmw","mwdrqwp","opmw","qsda","neo","qyssedhyac","pmw","lodpmw","mjwdrqwp","eo","nfqwa","pabuk","nfyqwa","qssdya","qsdya","qyssedhya","pabu","nqwa","pabqoukc","pbu","mw","vlodpmwp","x","xr"}) << "\n";
	// return 0;
	std::cout << Solution::longestStrChain({"a","b","ba","bca","bda","bdca"}) << "\n";
	std::cout << Solution::longestStrChain({"xbc","pcxbcf","xb","cxbc","pcxbc"}) << "\n";
	std::cout << Solution::longestStrChain({"abcd","dbqca"}) << "\n";
	return 0;
}
