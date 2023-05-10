#include <unordered_set>

/**
 * 1015. Smallest Integer Divisible by K
 *
 * Given a positive integer k, you need to find the length of the smallest positive integer n such that n is divisible by k, and n only contains the digit 1.
 * Return the length of n. If there is no such n, return -1.
 * Note: n may not fit in a 64-bit signed integer.
 */

class LC230510CN {
public:
	static int smallestRepunitDivByK(int k) noexcept;
};

int LC230510CN::smallestRepunitDivByK(int k) noexcept {
	using ULL = unsigned long long;
	int sum = 0;
	std::unordered_set<ULL> vis;
	ULL key;
	for (int j = 1, c = 1;; (j = (j * 10) % k), ++c) {
		sum = (sum + j) % k;
		if (sum == 0)
			return c;
		key = (ULL(sum) << 32) + j;
		if (vis.contains(key))
			return -1;
		vis.insert(key);
	}
}
