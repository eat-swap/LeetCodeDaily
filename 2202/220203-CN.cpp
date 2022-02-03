#include <cstdio>
#include <chrono>
#include <cstring>
#include <cstdint>
#include <algorithm>

/**
 * 1414. Find the Minimum Number of Fibonacci Numbers Whose Sum Is K
 * Given an integer k, return the minimum number of Fibonacci numbers whose sum is equal to k. The same Fibonacci number can be used multiple times.
 *
 * The Fibonacci numbers are defined as:
 *
 * F[1] = 1
 * F[2] = 1
 * F[n] = F[n-1] + F[n-2] for n > 2.
 * It is guaranteed that for the given constraints we can always find such Fibonacci numbers that sum up to k.
 */

class Solution {
private:
	inline static constexpr int fib[] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155, 165580141, 267914296, 433494437, 701408733, 1134903170, 1836311903};
	/*
	static int dp(int k) {
		int d[k + 1];
		std::memset(d, 0x7F, sizeof d);
		d[0] = 0;
		for (int i = 1; i <= k; ++i) {
			for (int j = 0; fib[j] <= i; ++j) {
				d[i] = std::min(d[i], 1 + d[i - fib[j]]);
			}
		}
		return d[k];
	}
	static int greedy(int k) {
		int ret = 0;
		for (; k; ++ret) {
			const auto* ptr = std::lower_bound(fib, fib + 45, k);
			k -= *(ptr - (k < *ptr));
		}
		return ret;
	}
	 */
public:
	static constexpr int findMinFibonacciNumbers(int k) {
		int ret = 0;
		for (; k; ++ret) {
			const auto* ptr = std::lower_bound(fib, fib + 45, k);
			k -= *(ptr - (k < *ptr));
		}
		return ret;
		/*
		for (int i = 1; i <= k; i += 100000) {
			int R = std::min(k, 99999 + i);
			int res1[R - i + 1], res2[R - i + 1];
			const auto greedyStart = std::chrono::high_resolution_clock::now();
			for (int j = i; j <= R; ++j) {
				res1[j - i] = greedy(j);
			}
			const auto greedyEnd = std::chrono::high_resolution_clock::now();
			for (int j = i; j <= R; ++j) {
				res2[j - i] = dp(j);
			}
			const auto dpEnd = std::chrono::high_resolution_clock::now();
			if (std::memcmp(res1, res2, sizeof res1)) {
				std::printf("(i, R) = (%d, %d), std::memcmp failed\n", i, R);
				std::exit(-1);
			} else {
				std::printf("(i, R) = (%d, %d), (greedy, dp) = (%llu ms, %llu ms)\n", i, R, std::chrono::duration_cast<std::chrono::milliseconds>(greedyEnd - greedyStart).count(), std::chrono::duration_cast<std::chrono::milliseconds>(dpEnd - greedyEnd).count());
			}
		}
		return 0;
		 */
	}
};

int main() {
	std::printf("%d\n", Solution::findMinFibonacciNumbers(10000));
	return 0;
}
