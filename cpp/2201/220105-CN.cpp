#include <iostream>
#include <string>

/**
 * 1576. Replace All ?'s to Avoid Consecutive Repeating Characters
 * Given a string s containing only lowercase English letters and the '?' character, convert all the '?' characters into lowercase letters such that the final string does not contain any consecutive repeating characters. You cannot modify the non '?' characters.
 *
 * It is guaranteed that there are no consecutive repeating characters in the given string except for '?'.
 *
 * Return the final string after all the conversions (possibly zero) have been made. If there is more than one solution, return any of them. It can be shown that an answer is always possible with the given constraints.
 */

class Solution {
public:
	static std::string modifyString(std::string s) {
		const int len = s.length();
		int a, b;
		for (int i = 0; i < len; ++i) {
			if (s[i] == '?') {
				a = i ? s[i - 1] : 0;
				b = (i + 1) < len ? s[i + 1] : 0;
				s[i] = a == 'a' ? (b == 'b' ? 'c' : 'b') : (b == 'a' ? (a == 'b' ? 'c' : 'b') : 'a');
			}
		}
		return s;
	}
};

int main() {
	std::cout << Solution::modifyString("a?c");
	return 0;
}