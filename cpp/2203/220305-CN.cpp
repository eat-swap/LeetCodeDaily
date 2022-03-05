#include <string>
#include <iostream>

class Solution {
public:
	// clang does not accept constexpr
	static inline int findLUSlength(const std::string& a, const std::string& b) {
		return a == b ? -1 : static_cast<int>(std::max(a.length(), b.length()));
	}
};

int main() {
	std::cout << Solution::findLUSlength("aaa", "bbb");
	return 0;
}
