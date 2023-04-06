#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

class SolutionConstruct {
private:
	static inline std::string toStr(int n) {
		int i = 31;
		for (; i >= 0 && !(n & (1 << i)); --i);
		std::string ret(i + 1, '0');
		for (int j = i; j >= 0; --j)
			if (n & (1 << j))
				ret[i - j] = '1';
		return ret.empty() ? "0" : ret;
	}

	static inline int toInt(const std::string& s) {
		auto ret = 0, i = 1;
		for (auto it = s.rbegin(); it != s.rend(); ++it) {
			ret |= (*it & 1) ? i : 0;
			i <<= 1;
		}
		return ret;
	}

	static constexpr inline int eval(int n) { return (n & 0x55555555) - (n & 0xAAAAAAAA); }

	static const inline std::string L5[] = {"0", "1", "110", "111", "100", "101"};

	static const inline std::string v[] = {"01", "00", "11", "10"};

public:
	static std::string baseNeg2(int n) {
		if (n <= 5)
			return L5[n];
		int cur, prev = 5, i = 4;
		for (; n > (cur = prev + (1 << i)); (prev = cur), (i += 2));
		auto ret = std::string(1, '0' | (n & 1));
		for (int x = (n - prev - 1) >> 1, j = 1; j < (i >> 1); (x >>= 2), ++j)
			ret = v[x & 3] + ret;
		return v[(n - prev > (cur - prev) / 2) + 2] + ret;
	}

	static void test(int n) {
		for (int i = 0; i < n; ++i) {
			int x = eval(i);
			if (x < 0)
				continue;
			if (i != toInt(baseNeg2(x)))
				std::printf("%d Bad!!\n", x);
		}
	}
};

/**
 * 1017. Convert to Base -2
 *
 * Given an integer n, return a binary string representing its representation in base -2.
 * Note that the returned string should not have leading zeros unless the string is "0".
 */

class Solution {
private:
	static const inline std::string L5[] = {"0", "1", "110", "111", "100", "101"};

	static const inline std::string v[] = {"01", "00", "11", "10"};

public:
	static std::string baseNeg2(int n) {
		if (n <= 5)
			return L5[n];
		int cur, prev = 5, i = 4;
		for (; n > (cur = prev + (1 << i)); (prev = cur), (i += 2));
		auto ret = std::string(1, '0' | (n & 1));
		for (int x = (n - prev - 1) >> 1, j = 1; j < (i >> 1); (x >>= 2), ++j)
			ret = v[x & 3] + ret;
		return v[(n - prev > (cur - prev) / 2) + 2] + ret;
	}
};

int main() {
	SolutionConstruct::test(0x1000000);
	// std::cout << Solution::baseNeg2(77);
	return 0;
}
