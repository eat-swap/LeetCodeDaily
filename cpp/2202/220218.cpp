#include <string>
#include <vector>
#include <iostream>

/**
 * 402. Remove K Digits
 * Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.
 */

class Solution {
public:
	static std::string removeKdigits(const std::string& num, int k) {
		std::vector<char> stack;
		stack.reserve(num.length() - k);
		for (char ch : num) {
			while (k && !stack.empty() && stack.back() > ch) {
				stack.pop_back();
				--k;
			}
			stack.push_back(ch);
		}
		std::string ret(stack.begin(), k > 0 ? std::prev(stack.end(), k) : stack.end());
		return ret.empty() || ret.find_first_not_of('0') == -1 ? "0" : ret.substr(ret.find_first_not_of('0'));
	}
};

int main() {
	std::cout << Solution::removeKdigits("1432219", 3);
	return 0;
}
