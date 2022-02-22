#include <vector>
#include <iostream>

class Solution {
private:
	inline static const int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
	inline static const int MOD = 1000000007;
public:
	static int numberOfGoodSubsets(const std::vector<int>& nums) {
		int cnt[31]{};
		for (int i : nums)
			++cnt[i];
		// 2 x 3 = 6
		// 2 x 5 = 10
		// 2 x 7 = 14
		// 2 x 11 = 22
		// 2 x 13 = 26
		// 3 x 5 = 15
		// 3 x 7 = 21
		long long ret = 0;
		for (int i = 1; i < 1024; ++i) {
			// Original numbers
			long long now = 1;
			for (int j = 0; j < 10; ++j)
				if (i & (1 << j))
					now = (now * cnt[primes[j]]) % MOD;
			ret = (ret + now) % MOD;

			if (i & 1) {
				// 2-related numbers
				for (int j = 1; j <= 5; ++j) {
					if ((i & (1 << j)) && (now = cnt[primes[j] << 1])) {
						// Now, there is no 2, no primes[j], but (primes[j] << 1).
						for (int k = 1; k < 10; ++k)
							if (k != j && (i & (1 << k)))
								now = (now * cnt[primes[k]]) % MOD;
						ret = (ret + now) % MOD;
					}
				}
			}

			if (i & 2) {
				// 3-related numbers
				// Only 5 (indexed 2) and 7 (indexed 3) is valid.
				if ((i & 4) && (now = cnt[15])) {
					for (int k = 0; k < 10; ++k)
						if (k != 1 && k != 2 && (i & (1 << k)))
							now = (now * cnt[primes[k]]) % MOD;
					ret = (ret + now) % MOD;
				}
				if ((i & 8) && (now = cnt[21])) {
					for (int k = 0; k < 10; ++k)
						if (k != 1 && k != 3 && (i & (1 << k)))
							now = (now * cnt[primes[k]]) % MOD;
					ret = (ret + now) % MOD;
				}
			}

			if ((now = cnt[30]) && ((i & 7) == 7)) {
				// 2 * 3 * 5 == 30
				for (int j = 3; j < 10; ++j)
					if (i & (1 << j))
						now = (now * cnt[primes[j]]) % MOD;
				ret = (ret + now) % MOD;
			}

			// 2 - (11, 13) + 3 - (5, 7)
			if (((i & 3) == 3) && (i & 61)) {
				for (int j2 = 2; j2 <= 5; ++j2) {
					for (int j3 = 2; j3 <= 3; ++j3) {
						if (j2 != j3 && (i & (1 << j2)) && (i & (1 << j3))) {
							now = (cnt[primes[j2] << 1] * cnt[primes[j3] * 3]) % MOD;
							for (int k = 2; k < 10; ++k) {
								if (k != j2 && k != j3 && (i & (1 << k))) {
									now = (now * cnt[primes[k]]) % MOD;
								}
							}
							ret = (ret + now) % MOD;
						}
					}
				}
			}
		}
		while (cnt[1]--) {
			ret = (ret << 1) % MOD;
		}
		return ret % MOD;
	}
};

int main() {
	std::cout << Solution::numberOfGoodSubsets({5, 10, 1, 26, 24, 21, 24, 23, 11, 12, 27, 4, 17, 16, 2, 6, 1, 1, 6, 8, 13, 30, 24, 20, 2, 19});
	return 0;
}
