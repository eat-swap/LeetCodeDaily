#include <iostream>
#include <vector>
#include <queue>

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
