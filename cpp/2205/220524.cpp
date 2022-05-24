#include <stack>
#include <string>
#include <iostream>

/**
 * 32. Longest Valid Parentheses
 * Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 */

class Solution {
public:
	static int longestValidParentheses(const std::string& s) {
		std::stack<int16_t> stack;
		int16_t last_success = -1;
		const int16_t len = s.length();

		int ans = 0;
		for (int16_t i = 0; i < len; ++i)
			if ('(' == s[i])
				stack.push(i);
			else if (stack.empty())
				last_success = i;
			else
				ans = std::max(ans, i - ((stack.pop(), stack.empty()) ? last_success : stack.top()));
		return ans;
	}
};

int main() {
	std::cout << Solution::longestValidParentheses(")()(((()()()))))()()()");
	return 0;
}
