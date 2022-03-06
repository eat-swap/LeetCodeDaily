#include <string>

/**
 * 504. Base 7
 * Given an integer num, return a string of its base 7 representation.
 */

class Solution {
public:
	static std::string convertToBase7(int num) {
		bool isNeg = num < 0;
		std::string ret;
		num = num < 0 ? -num : num;
		while (num) {
			ret.push_back('0' + num % 7);
			num /= 7;
		}
		if (isNeg)
			ret.push_back('-');
		std::reverse(ret.begin(), ret.end());
		return ret.empty() ? "0" : ret;
	}
};
