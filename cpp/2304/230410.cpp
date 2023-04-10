#include <stack>
#include <string>

/**
 * 20. Valid Parentheses
 *
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *
 * An input string is valid if:
 *
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * Every close bracket has a corresponding open bracket of the same type.
 */

class Solution {
public:
	static bool isValid(const std::string&);
};

bool Solution::isValid(const std::string& s) {
	std::stack<char> sc;
	for (char ch : s) {
		switch (ch) {
			case '[':
			case '(':
			case '{':
				sc.push(ch);
				break;
			case ']':
			case ')':
			case '}':
				if (sc.empty() || sc.top() != (ch ^ (ch < 64 ? 1 : 6)))
					return false;
				sc.pop();
				break;
			default:
				return false;
		}
	}
	return sc.empty();
}

int main() {
	Solution::isValid("()[]{}");
	return 0;
}