#include <string>
#include <cstdio>

/**
 * 面试题 01.05. One Away LCCI
 * There are three types of edits that can be performed on strings: insert a character, remove a character, or replace a character. Given two strings, write a function to check if they are one edit (or zero edits) away.
 */

class Solution {
public:
	static bool oneEditAway(const std::string& first, const std::string& second) {
		int ps = 0, pt = 0, mod = 0, ls = first.length(), lt = second.length();
		if (std::abs(ls - lt) > 1)
			return false;

		const char* s = first.c_str(), * t = second.c_str();
		for (; ps < ls && pt < lt; ++ps, ++pt) {
			if (s[ps] == t[pt])
				continue;
			if (mod++)
				return false;
			if (pt + 1 < lt && s[ps] == t[pt + 1])
				++pt;
			else if (ps + 1 < ls && s[ps + 1] == t[pt])
				++ps;
			// else ++ps, ++pt;
		}
		return ((ps == ls) && (pt == lt)) || (!mod && std::abs(ls - lt) <= 1);
	}
};

int main() {
	std::printf("%s\n", Solution::oneEditAway("", "a") ? "true" : "false");
	return 0;
}
