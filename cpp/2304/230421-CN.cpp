/**
 * 2413. Smallest Even Multiple
 *
 * Given a positive integer n, return the smallest positive integer that is a multiple of both 2 and n.
 */

class Solution {
public:
	static constexpr int smallestEvenMultiple(int n) {
		return n << (n & 1);
	}
};