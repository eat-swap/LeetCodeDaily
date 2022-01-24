#include <iostream>
#include <vector>

/**
 * 875. Koko Eating Bananas
 * Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
 * Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
 * Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
 * Return the minimum integer k such that she can eat all the bananas within h hours.
 */

class Solution {
public:
	static int minEatingSpeed(const std::vector<int>& piles, int h) {
		int L = 1, R = 0x7FFFFFFE;
		// range: [L, R)
		while (R - L > 1) {
			int M = (L - 1 + R) >> 1, cnt = 0;
			// test M
			for (const int& i : piles)
				cnt += (i / M) + ((i % M) ? 1 : 0);
			*(cnt <= h ? &R : &L) = M + 1;
		}
		return L;
	}
};

int main() {
	// {34392671,891616382,813261297}, 712127987
	std::cout << Solution::minEatingSpeed({30,11,23,4,20}, 6);
	return 0;
}
