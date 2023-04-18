#include <algorithm>
#include <iterator>
#include <ranges>
#include <string>
#include <iostream>

/**
 * 1768. Merge Strings Alternately
 *
 * You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.
 * Return the merged string.
 */

class Solution {
	using S = std::string;
	using CSR = S const&;
public:
	static S mergeAlternately(CSR, CSR);
};

std::string Solution::mergeAlternately(CSR s, CSR t) {
	const int m = s.length(), n = t.length(), k = std::min(m, n);
	std::string ret;
	for (int i = 0; i < k; ++i)
		ret.push_back(s[i]), ret.push_back(t[i]);
	for (int i = k; i < m; ++i)
		ret.push_back(s[i]);
	for (int i = k; i < n; ++i)
		ret.push_back(t[i]);
	return ret;
}

int main() {
	std::cout << Solution::mergeAlternately("ab", "pqrs");
}
