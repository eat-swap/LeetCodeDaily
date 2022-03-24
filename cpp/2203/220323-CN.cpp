#include <vector>

/**
 * 440. K-th Smallest in Lexicographical Order
 * Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].
 */

class Solution {
public:
	int findKthNumber(int n, int k) {
		auto getCount = [&](int prefix, unsigned long long n) {
			auto count = 0ULL;
			for (unsigned long long cur = prefix, next = prefix + 1; cur <= n; cur *= 10, next *= 10)
				count += std::min(next, n + 1) - cur;
			return count;
		};
		auto p = 1;
		auto prefix = 1;
		while (p < k) {
			auto count = getCount(prefix, n);
			if (p + count > k) {
				prefix *= 10;
				p++;
			} else if (p + count <= k) {
				prefix++;
				p += count;
			}
		}
		return prefix;
	}
};