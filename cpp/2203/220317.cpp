#include <iostream>
#include <string>

/**
 * 856. Score of Parentheses
 * Given a balanced parentheses string s, return the score of the string.
 * The score of a balanced parentheses string is based on the following rule:
 * - "()" has score 1.
 * - AB has score A + B, where A and B are balanced parentheses strings.
 * - (A) has score 2 * A, where A is a balanced parentheses string.
 */

class Solution {
public:
	static int scoreOfParentheses(const std::string& s) {
		int stack[30], top = -1, ret = 0;
		for (char ch : s) {
			if (ch == '(') {
				stack[++top] = 0;
			} else { // ch == ')'
				*(top ? &stack[top - 1] : &ret) += (stack[top] ? stack[top] << 1 : 1);
				--top;
			}
		}
		return ret;
	}
};

int main() {
	std::cout << Solution::scoreOfParentheses("((())())");
	return 0;
}
