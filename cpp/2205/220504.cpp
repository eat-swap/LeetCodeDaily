#include <vector>
#include <unordered_map>

/**
 * 1679. Max Number of K-Sum Pairs
 * You are given an integer array nums and an integer k.
 * In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.
 * Return the maximum number of operations you can perform on the array.
 */

class Solution {
public:
	static int maxOperations(const std::vector<int>& nums, int k) {
		std::unordered_map<int, int> m;
		for (int i : nums)
			++m[i];
		int ret = (k & 1) ? 0 : (m[k / 2] / 2);
		const int pivot = (k & 1) ? (k / 2 + 1) : (k / 2);
		for (const auto& [idx, cnt] : m)
			if (idx < pivot && m.count(k - idx))
				ret += std::min(m[idx], m[k - idx]);
		return ret;
	}
};

int main() {
	Solution::maxOperations({2,2,2,3,1,1,4,1}, 4);
}
