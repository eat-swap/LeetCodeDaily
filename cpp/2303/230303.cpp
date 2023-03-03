#include <string>
#include <vector>
#include <iostream>

/**
 * 28. Find the Index of the First Occurrence in a String
 *
 * Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 */

class Solution {
public:
	static int strStr(const std::string& s, const std::string& t) {
		const int m = s.length(), n = t.length();
		std::vector<int> p(n);
		for (int i = 1; i < n; ++i) {
			int j = p[i - 1];
			for (; j > 0 && t[i] != t[j]; j = p[j - 1]);
			p[i] = j + (t[i] == t[j]);
		}
		for (int i = 0, j = 0; i < m; ++i) {
			for (; j > 0 && s[i] != t[j]; j = p[j - 1]);
			if (s[i] == t[j] && ++j >= n)
				return i - j + 1;
		}
		return -1;
	}
};

int main() {
	std::cout << Solution::strStr("busasasasasapsadpp", "sasasasapsad");
	return 0;
}
