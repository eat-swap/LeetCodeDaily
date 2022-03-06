#include <iostream>

class Solution {
private:
	inline static const int MOD = 1000000007;
public:
	// OEIS A000680		a(n) = (2n)!/2^n.
	static constexpr int countOrders(int n) {
		if (n == 1)
			return 1;
		if (n == 2)
			return 6;
		unsigned long long ret = 6;
		for (int i = 3; i <= n; ++i) {
			ret = (ret * i) % MOD;
			ret = (ret * ((i << 1) - 1)) % MOD;
		}
		return ret % MOD;
	}
};

int main() {
	std::cout << Solution::countOrders(5);
	return 0;
}
