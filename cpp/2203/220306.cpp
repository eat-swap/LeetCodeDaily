#include <iostream>

/**
 * 1359. Count All Valid Pickup and Delivery Options
 * Given n orders, each order consist in pickup and delivery services.
 * Count all valid pickup/delivery possible sequences such that delivery(i) is always after of pickup(i).
 * Since the answer may be too large, return it modulo 10^9 + 7.
 */

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
