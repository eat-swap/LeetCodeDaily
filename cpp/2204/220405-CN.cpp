#include <iostream>

class Solution {
private:
	static inline const int IS_PRIME[32] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1};
public:
	static int countPrimeSetBits(int left, int right) {
		int ret = 0;
		for (int i = left; i <= right; ++i) {
			int x = 0;
			for (int n = i; n; n >>= 1)
				x += n & 1;
			ret += IS_PRIME[x];
		}
		return ret;
	}
};

int main() {
	std::printf("%d\n", Solution::countPrimeSetBits(6, 10));
	return 0;
}
