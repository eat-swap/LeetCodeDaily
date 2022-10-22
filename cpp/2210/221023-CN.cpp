#include <string>

/**
 * 1768. Merge Strings Alternately
 *
 * You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.
 * Return the merged string.
 */

class Solution {
public:
	static std::string mergeAlternately(const std::string& s, const std::string& t) {
		const char* sp = s.c_str(), * tp = t.c_str();
		std::string ret;
		ret.reserve(s.length() + t.length());
		while (*sp && *tp) {
			ret.push_back(*(sp++));
			ret.push_back(*(tp++));
		}
		while (*sp)
			ret.push_back(*(sp++));
		while (*tp)
			ret.push_back(*(tp++));
		return ret;
	}
};