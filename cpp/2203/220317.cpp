#include <iostream>
#include <string>

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
