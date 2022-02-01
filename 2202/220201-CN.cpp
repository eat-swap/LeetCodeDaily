#include <string>
#include <cctype>
#include <cstdio>

/**
 * 1763. Longest Nice Substring
 * A string s is nice if, for every letter of the alphabet that s contains, it appears both in uppercase and lowercase. For example, "abABB" is nice because 'A' and 'a' appear, and 'B' and 'b' appear. However, "abA" is not because 'b' appears, but 'B' does not.
 * Given a string s, return the longest substring of s that is nice. If there are multiple, return the substring of the earliest occurrence. If there are none, return an empty string.
 */

class Solution {
private:
	static bool isNice(const std::string& str, int L, int R) {
		bool bucket[2][26]{};
		for (int i = L; i < R; ++i)
			*(std::isupper(str[i]) ? &bucket[0][str[i] - 'A'] : &bucket[1][str[i] - 'a']) = true;
		for (int i = 0; i < 26; ++i)
			if ((bucket[0][i] || bucket[1][i]) && !(bucket[0][i] && bucket[1][i]))
				return false;
		return true;
	}
public:
    static std::string longestNiceSubstring(const std::string& s) {
		const int n = s.length();
		std::string ret;
		int retMax = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				if (j - i > retMax && isNice(s, i, j)) {
					retMax = j - i;
					ret = s.substr(i, j - i);
				}
			}
		}
		return ret;
    }
};

int main() {
	std::printf("%s\n", Solution::longestNiceSubstring("YazaAay").c_str());
	std::printf("%s\n", Solution::longestNiceSubstring("Bb").c_str());
	std::printf("%s\n", Solution::longestNiceSubstring("c").c_str());
	std::printf("%s\n", Solution::longestNiceSubstring("dDzeE").c_str());
	return 0;
}
