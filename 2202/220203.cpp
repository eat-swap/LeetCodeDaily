#include <vector>
#include <cstdio>
#include <unordered_map>

/**
 * 454. 4Sum II
 * Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:
 * 0 <= i, j, k, l < n
 * nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
 */

class Solution {
public:
	static int fourSumCount(const std::vector<int>& nums1, const std::vector<int>& nums2, const std::vector<int>& nums3, const std::vector<int>& nums4) {
		int ret = 0;
		std::unordered_map<int, int> m1, m2;
		for (int i : nums1)
			for (int j : nums2)
				++m1[i + j];
		for (int i : nums3)
			for (int j : nums4)
				++m2[i + j];
		for (const auto& p : m1)
			ret += p.second * m2[-p.first];
		return ret;
	}
};

int main() {
	std::printf("%d\n", Solution::fourSumCount({0}, {0}, {0}, {0}));
	return 0;
}
