#include <vector>
#include <iostream>
#include <chrono>

/**
 * 89. Gray Code
 * An n-bit gray code sequence is a sequence of 2^n integers where:
 * Every integer is in the inclusive range [0, 2^n - 1],
 * The first integer is 0,
 * An integer appears no more than once in the sequence,
 * The binary representation of every pair of adjacent integers differs by exactly one bit, and
 * The binary representation of the first and last integers differs by exactly one bit.
 * Given an integer n, return any valid n-bit gray code sequence.
 */

class Solution {
public:
	static std::vector<int> grayCode(const int n) {
		std::vector<int> ret{0};
		for (int i = 0; i < n; ++i) {
			ret.insert(ret.end(), ret.rbegin(), ret.rend());
			for (int j = 1 << i; j < (1 << (1 + i)); ++j)
				ret[j] |= (1 << i);
		}
		return ret;
	}
};

class SolutionOld {
public:
	static std::vector<int> grayCode(const int n) {
		int lim = 1 << n, cur = 0;
		std::vector<int> ret{0};
		ret.reserve(lim);
		int* const vis = new int[1 + (lim >> 5)]{0x1};
		for (int i = 1; i < lim; ++i) {
			for (int j = 0; j < n; ++j) {
				if (!(vis[(cur ^ (1 << j)) >> 5] & (1 << ((cur ^ (1 << j)) & 0x1F)))) {
					ret.push_back(cur ^= (1 << j));
					vis[cur >> 5] |= (1 << (cur & 0x1F));
					break;
				}
			}
		}
		delete[] vis;
		return ret;
	}
};

class Solution0ms {
public:
	static std::vector<int> grayCode(int n) {
		std::vector<int> ans = {0, 1};
		for (int i = 2; i <= n; i++) {
			int x = (1 << (i - 1));
			int idx = ans.size() - 1;
			while (idx >= 0) {
				int num = (ans[idx] + x);
				ans.push_back(num);
				idx--;
			}
		}
		return ans;
	}
};

int main() {
	const int n = 30;
	auto t1 = std::chrono::high_resolution_clock::now();
	SolutionOld::grayCode(n);
	auto t2 = std::chrono::high_resolution_clock::now();
	Solution::grayCode(n);
	auto t4 = std::chrono::high_resolution_clock::now();
	Solution0ms::grayCode(n);
	auto t5 = std::chrono::high_resolution_clock::now();
	std::cout << "SolutionOld: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << "ms" << std::endl;
	std::cout << "Solution: " << std::chrono::duration_cast<std::chrono::milliseconds>(t4 - t2).count() << "ms" << std::endl;
	std::cout << "Solution0ms: " << std::chrono::duration_cast<std::chrono::milliseconds>(t5 - t4).count() << "ms" << std::endl;
	return 0;
}
