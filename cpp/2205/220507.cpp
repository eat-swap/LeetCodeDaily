#include <vector>
#include <map>
#include <stack>
#include <cstdio>
#include <chrono>

/**
 * 456. 132 Pattern
 * Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].
 * Return true if there is a 132 pattern in nums, otherwise, return false.
 */

class Solution {
public:
	static bool find132pattern(const std::vector<int>& nums) {
		const int n = nums.size();
		int ptr = 0;
		int* s = new int[n];
		int e3 = -0x7FFFFFFF - 1, t, st;
		// for (auto it = nums.crbegin(); it != nums.crend(); ++it) {
		for (int i = n - 1; i >= 0; --i) {
			t = nums[i];
			if (t < e3)
				return true;
			while (ptr && (st = s[ptr - 1]) < t) {
				e3 = st;
				--ptr;
			}
			s[ptr++] = t;
		}
		return false;
	}
};

class SolutionOld {
public:
	static bool find132pattern(const std::vector<int>& nums) {
		const int n = nums.size();
		if (n < 3)
			return false;
		std::map<int, int> m;
		for (int i = 1; i < n; ++i)
			++m[nums[i]];
		int min = nums[0], pivot = 1;
		while (pivot < n - 1) {
			auto it = std::lower_bound(m.cbegin(), m.cend(), std::pair<const int, int>(min, 0x7FFFFFFF));
			if (it != m.end() && it->first < nums[pivot])
				return true;

			// Advance pivot
			int prevPivot = pivot, prevMin = min;
			while (pivot < n - 1 && ((nums[pivot] <= nums[prevPivot] && prevMin == min) || nums[pivot] <= nums[pivot + 1])) {
				if (--m[nums[pivot]] <= 0) {
					m.erase(nums[pivot]);
				}
				min = std::min(min, nums[pivot]);
				++pivot;
			}
			if (pivot == prevPivot) {
				min = std::min(min, nums[pivot]);
				++pivot;
			}
		}
		return false;
	}
};

class Stopwatch {
private:
	std::chrono::high_resolution_clock::time_point start;
public:
	Stopwatch() {
		this->start = std::chrono::high_resolution_clock::now();
	}

	~Stopwatch() {
		std::printf("Time elapsed: %.6lf ms\n", std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - start).count() / 1000000.0);
	}
};

int main() {
	const int N = 200000;
	std::vector<int> args(N);
	for (int i = 0; i < N; ++i)
		args[i] = (i & 1) ? -i : i;

	bool ans;
	{
		Stopwatch s;
		ans = Solution::find132pattern(args);
	}

	std::printf(ans ? "true" : "false");
	return 0;
}
