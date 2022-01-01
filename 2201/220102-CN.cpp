#include <iostream>

class Solution {
public:
	// O(log(n))
	static int lastRemaining(int n) {
		int cnt = 0, ret = 1;
		for (int i = n; i >>= 1; ++cnt);
		for (int i = 0; i < cnt; ++i, n >>= 1)
			ret += !(1 & i) || (1 & n) ? (1 << i) : 0;
		return ret;
	}
};

int main() {
	std::printf("%d\n", Solution::lastRemaining(1));
	return 0;
}
