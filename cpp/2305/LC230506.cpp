#include <algorithm>
#include <vector>

/**
 * 1498. Number of Subsequences That Satisfy the Given Sum Condition
 *
 * You are given an array of integers nums and an integer target.
 * Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo 109 + 7.
 */

class LC230506 {
public:
	static int numSubseq(std::vector<int>&, int) noexcept;
};

constexpr int pwr2(int x) noexcept {
	unsigned long long cur = 2, ret = 1;
	for (; x; (x >>= 1), (cur = (cur * cur) % 1'000'000'007))
		if (x & 1)
			ret = (ret * cur) % 1'000'000'007;
	return ret % 1'000'000'007;
}

int LC230506::numSubseq(std::vector<int>& n, int target) noexcept {
	std::sort(n.begin(), n.end());
	int ret = 0;
	for (int l = 0, r = n.size() - 1; l < n.size(); ++l) {
		for (; r > 0 && n[l] + n[r] > target; --r);
		ret = (ret + ((!r || r <= l) ? ((n[l] << 1) <= target) : pwr2(r - l))) % 1'000'000'007;
		if ((n[l] << 1) > target)
			return ret;
	}
	return ret;
}
