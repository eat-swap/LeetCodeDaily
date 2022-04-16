#include <cstdio>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

/**
 * 479. Largest Palindrome Product
 * Given an integer n, return the largest palindromic integer that can be represented as the product of two n-digits integers. Since the answer can be very large, return it modulo 1337.
 */

class Solution {
private:
	static inline constexpr unsigned long long get9(int n) {
		unsigned long long ans = 0;
		while (n--)
			ans = ans * 10 + 9;
		return ans;
	}

	static inline constexpr int getAns(int n) {
		auto halfMax = get9(n), halfMin = 1 + get9(n - 1);
		for (auto i = halfMax; i >= halfMin; --i) {
			unsigned long long iFull = 0;
			for (auto j = i; j; j /= 10) {
				iFull = 10 * iFull + j % 10;
			}
			iFull += i * (1 + halfMax);
			for (auto j = MIN(halfMax, iFull / halfMin); iFull / j <= halfMax && j >= halfMin; --j) {
				if (iFull % j == 0) {
					// std::printf("%llu %llu\n", iFull, j);
					return iFull % 1337;
				}
			}
		}
		return 0;
	}
public:
	static constexpr int largestPalindrome(int n) {
		// const static int ans[] = {-1, 9, 987, 123, 597, 677, 1218, 877, 475};
		// return ans[n];
		return n == 1 ? 9 : getAns(n);
	}
};

int main() {
	for (int i = 2; i <= 8; ++i) {
	//	std::printf("%d\n", getAns(i));
	}
	return 0;
}
