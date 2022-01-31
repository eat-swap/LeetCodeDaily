#include <iostream>

class Solution {
public:
	static constexpr int numberOfSteps(int num) {
		int ret = 0;
		for (; num & 0xFFFFFFFE; num >>= 1)
			ret += 1 + (num & 1);
		return ret + num;
	}
};

int main() {
	std::printf("%d\n", Solution::numberOfSteps(14));
	std::printf("%d\n", Solution::numberOfSteps(8));
	std::printf("%d\n", Solution::numberOfSteps(123));
}