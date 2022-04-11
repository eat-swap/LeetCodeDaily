#include <cstdio>

/**
 * 357. Count Numbers with Unique Digits
 * Given an integer n, return the count of all numbers with unique digits, x, where 0 <= x < 10^n.
 */

class Solution {
public:
	static int countNumbersWithUniqueDigits(int n) {
		static const int ans[] = {1, 10, 91, 739, 5275, 32491, 168571, 712891, 2345851};
		return ans[n];
	}
};

bool isUnique(int x) {
	int c[10]{};
	for (; x; x /= 10)
		if (c[x % 10]++)
			return false;
	return true;
}

int main() {
	int ans = 0;
	for (int i = 0, j = 1; i < 9; ++i, j *= 10) {
		for (int k = j / 10; k < j; ++k) {
			if (isUnique(k)) {
				++ans;
			}
		}
		std::printf("%d(%d) -> %d\n", i, j, ans);
	}
	return 0;
}
