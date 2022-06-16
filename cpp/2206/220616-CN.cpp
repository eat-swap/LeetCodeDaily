#include <vector>
#include <unordered_set>
#include <unordered_map>

/**
 * 532. K-diff Pairs in an Array
 * Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.
 * A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:
 * - 0 <= i, j < nums.length
 * - i != j
 * - nums[i] - nums[j] == k
 * Notice that |val| denotes the absolute value of val.
 *
 * Refer: 220209.cpp
 */

class Solution {
public:
	static int findPairs(const std::vector<int>& nums, int k) {
		int ans = 0;
		if (k) {
			std::unordered_set<int> s;
			for (int i : nums) {
				if (s.count(i))
					continue;
				if (s.count(i + k))
					++ans;
				if (s.count(i - k))
					++ans;
				s.insert(i);
			}
		} else {
			std::unordered_map<int, int> m;
			for (int i : nums)
				if (m[i]++ == 1)
					++ans;
		}
		return ans;
	}
};
