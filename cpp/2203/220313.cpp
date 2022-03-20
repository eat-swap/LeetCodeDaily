#include <string>
#include <stack>

/**
 * 20. Valid Parentheses
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * An input string is valid if:
 * 1. Open brackets must be closed by the same type of brackets.
 * 2. Open brackets must be closed in the correct order.
 */

class Solution {
public:
	static bool isValid(const std::string& s) {
		char pairs[256]{};
		'}'[pairs] = '{';
		']'[pairs] = '[';
		')'[pairs] = '(';

		std::stack<char> stack;
		for (char c : s) {
			switch (c) {
				case '(':
				case '[':
				case '{':
					stack.push(c);
					break;
				default:
					if (stack.empty() || pairs[c] != stack.top())
						return false;
					stack.pop();
			}
		}

		return stack.empty();
	}
};

int main() {
	int s[10];
	5[s] = 111;
}
