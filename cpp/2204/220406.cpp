#include <vector>
#include <iostream>

/**
 * 923. 3Sum With Multiplicity
 * Given an integer array arr, and an integer target, return the number of tuples i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.
 * As the answer can be very large, return it modulo 109 + 7.
 */

class Solution {
private:
	static inline const int MAX_VALUE = 100 + 2;

	static inline const int MOD = 1000000007;

	inline static unsigned long long CX2(unsigned long long n) {
		return (n & 1) ? ((n - 1 >> 1) * n) : ((n >> 1) * (n - 1));
	}

	inline static unsigned long long CX3(unsigned long long n) {
		return (n - 2) * CX2(n) / 3;
	}

public:
	static int threeSumMulti(const std::vector<int>& arr, const int target) {
		unsigned long long cnt[3 * MAX_VALUE]{};
		for (int i: arr)
			++cnt[i];
		unsigned long long ret = 0;

		// 3 Different values
		for (int i = 0; i < MAX_VALUE; ++i)
			for (int j = i + 1; j < (target - i - j); ++j)
				ret = (ret + (((cnt[target - i - j] * cnt[i]) % MOD) * cnt[j]) % MOD) % MOD;

		// 2 Same Values
		for (int i = 0; i < MAX_VALUE && target - i - i >= 0; ++i)
			if (cnt[i] >= 2 && i + i + i != target)
				ret = (ret + CX2(cnt[i]) * cnt[target - i - i] % MOD) % MOD;

		// 3 Same values
		return (ret + (3 * (target / 3) == target ? CX3(cnt[target / 3]) : 0)) % MOD;
	}
};

int main() {
	std::cout << Solution::threeSumMulti({0,0,0}, 0);
	return 0;
}
