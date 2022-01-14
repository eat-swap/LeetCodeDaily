#include <string>
#include <iostream>
#include <cctype>

class Solution {
public:
	static int myAtoi(const std::string& s) {
		long long ret = 0;
		int sgn = 1, pos = 0;
		for (; std::isspace(s[pos]); ++pos);
		if (s[pos] == '-')
			sgn = -sgn;
		if (s[pos] == '-' || s[pos] == '+')
			++pos;
		for (; std::isdigit(s[pos]); ++pos) {
			ret = (ret << 3) + (ret << 1) + (s[pos] ^ 48);
			if (ret > INT32_MAX)
				break;
		}
		ret *= sgn;
		if (ret < INT32_MIN)
			return INT32_MIN;
		else if (ret > INT32_MAX)
			return INT32_MAX;
		return int(ret & 0xFFFFFFFFLL);
	}
};

int main() {
	std::cout << Solution::myAtoi("42");
	return 0;
}