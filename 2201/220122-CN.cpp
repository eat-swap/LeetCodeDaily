#include <string>
#include <iostream>

class Solution {
public:
	static int removePalindromeSub(const std::string& s) {
		auto r = s;
		std::reverse(r.begin(), r.end());
		return 1 + (!(s == r) && std::count_if(s.begin(), s.end(), [&](char c) { return c == (s[0] ^ 3); }) ? 1 : 0);
	}
};

int main() {
	std::cout << Solution::removePalindromeSub("abaaba");
	return 0;
}
