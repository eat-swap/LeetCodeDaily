#include <vector>
#include <string>
#include <cstdio>

/**
 * 890. Find and Replace Pattern
 * Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.
 * A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.
 * Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.
 */

class Solution {
private:
	static unsigned long long hash(const std::string& str) {
		unsigned long long ret = 0;
		// char rm[27]{};
		int m[27]{}; // a -> 1.
		int roundRobin = 0, pos = 1;
		for (char ch : str) {
			if (!m[ch - 'a' + 1]) {
			//	rm[pos] = ch;
				m[ch - 'a' + 1] = pos++;
			}
			unsigned long long x = m[ch - 'a' + 1];
			ret ^= x << (roundRobin * 5);
			roundRobin = (roundRobin + 1) % 12;
		}
		return ret;
	}

public:
	static std::vector<std::string> findAndReplacePattern(const std::vector<std::string>& words, const std::string& pattern) {
		// std::printf("Pattern -> 0x%016llX\n", hash(pattern));
		const auto patternHash = hash(pattern);

		std::vector<std::string> ret;
		for (const auto& str : words) {
			// std::printf("%s -> 0x%016llX\n", str.c_str(), hash(str));
			if (patternHash == hash(str)) {
				ret.push_back(str);
			}
		}

		return ret;
	}
};

int main() {
	Solution::findAndReplacePattern({"abc","deq","mee","aqq","dkd","ccc"}, "abb");
	return 0;
}
