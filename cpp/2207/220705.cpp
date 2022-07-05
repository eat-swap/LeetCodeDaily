#include <unordered_set>
#include <vector>

/**
 * 128. Longest Consecutive Sequence
 * Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
 * You must write an algorithm that runs in O(n) time.
 */

class Solution {
public:
	int longestConsecutive(const std::vector<int>& nums) {
		std::unordered_set<int> s(nums.begin(), nums.end());
		int ans = 0;
		for (int i : s) {
			if (s.count(i - 1))
				continue;
			int cur = i, ca = 1;
			for (; s.count(1 + cur); ++cur)
				++ca;
			ans = std::max(ans, ca);
		}
		return ans;
	}
};
