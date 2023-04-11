#include <string>

/**
 * 2390. Removing Stars From a String
 *
 * You are given a string s, which contains stars *.
 *
 * In one operation, you can:
 *
 * Choose a star in s.
 * Remove the closest non-star character to its left, as well as remove the star itself.
 * Return the string after all stars have been removed.
 *
 * Note:
 *
 * The input will be generated such that the operation is always possible.
 * It can be shown that the resulting string will always be unique.
 */

class Solution {
public:
	static std::string removeStars(const std::string&);
};

std::string Solution::removeStars(const std::string& s) {
	std::string ret;
	for (char ch : s)
		if (ch != '*')
			ret.push_back(ch);
		else
			ret.pop_back();
	return ret;
}
