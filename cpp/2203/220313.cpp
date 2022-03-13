#include <string>
#include <stack>

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
