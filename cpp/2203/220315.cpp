#include <string>
#include <stack>
#include <iostream>

/**
 * 1249. Minimum Remove to Make Valid Parentheses
 * Given a string s of '(' , ')' and lowercase English characters.
 * Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.
 * Formally, a parentheses string is valid if and only if:
 * - It is the empty string, contains only lowercase characters, or
 * - It can be written as AB (A concatenated with B), where A and B are valid strings, or
 * - It can be written as (A), where A is a valid string.
 */

class Solution {
public:
	static std::string minRemoveToMakeValid(const std::string& s) {
		int n = s.length(), stackSize = 0;
		std::stack<int> rem;
		for (int i = 0; i < n; ++i) {
			switch (s[i]) {
				case '(':
					++stackSize;
					rem.push(i);
					break;
				case ')':
					if (stackSize <= 0) {
						rem.push(i);
					} else {
						--stackSize;
						rem.pop();
					}
			}
		}
		int remSize = rem.size();
		int* rems = new int[remSize];
		for (int* ptr = rems + remSize - 1; !rem.empty(); ptr = ptr > rems ? ptr - 1 : ptr) {
			*ptr = rem.top();
			rem.pop();
		}

		std::string ret;
		for (int p1 = 0, p2 = 0; p1 < n; ++p1) {
			if (p1 == rems[p2])
				++p2;
			else
				ret.push_back(s[p1]);
		}

		return ret;
	}
};

int main() {
	std::cout << Solution::minRemoveToMakeValid("a)b(c)d");
	return 0;
}
