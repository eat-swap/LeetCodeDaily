#include <iostream>

class Solution {
public:
	static int bitwiseComplement(int n) {
		return n ? ((1 << ((31 ^ __builtin_clz(n)) + 1)) - 1) ^ n : 1;
	}
};

int main() {
	std::printf("%d\n", Solution::bitwiseComplement(0));
}