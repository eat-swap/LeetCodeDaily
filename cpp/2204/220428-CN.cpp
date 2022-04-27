#include <vector>

/**
 * 905. Sort Array By Parity
 * Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.
 * Return any array that satisfies this condition.
 */

class Solution {
public:
	std::vector<int> sortArrayByParity(std::vector<int>& nums) {
		std::vector<int> e, o;
		for (int i : nums)
			((i & 1) ? &o : &e)->push_back(i);
		e.insert(e.end(), o.begin(), o.end());
		return e;
	}
};
