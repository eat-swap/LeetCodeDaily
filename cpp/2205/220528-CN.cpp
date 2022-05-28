#include <string>
#include <iostream>

/**
 * 1021. Remove Outermost Parentheses
 * A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.
 * For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
 * A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.
 * Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.
 * Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.
 */

class Solution {
public:
	static std::string removeOuterParentheses(const std::string& s) {
		int stack = 0, prev = 0;
		std::string ans;
		const int n = s.length();
		for (int i = 0; i < n; ++i) {
			if (0 == (s[i] == '(' ? ++stack : --stack)) {
				ans += s.substr(prev + 1, i - prev - 1);
				prev = i + 1;
			}
		}
		return ans;
	}
};

int main() {
	std::cout << Solution::removeOuterParentheses("()()");
	return 0;
}
