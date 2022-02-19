#include <iostream>

class Solution {
public:
	static auto totalMoney(auto n) {
		return (28 + n % 7) * (n / 7) + (n / 7) * (n / 7 - 1) / 2 * 7 + (1 + n % 7) * (n % 7) / 2;
	}
};

int main() {
	std::cout << Solution::totalMoney(20);
	return 0;
}