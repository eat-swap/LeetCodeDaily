#include <vector>
#include <unordered_map>

/**
 * 169. Majority Element
 * Given an array nums of size n, return the majority element.
 * The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
 */

class Solution {
public:
	static inline int majorityElement(const std::vector<int>& nums) {
		int n = nums.size() >> 1;
		std::unordered_map<int, int> m;
		for (int i : nums)
			if (++m[i] > n)
				return i;
		return 0;
	}
};

int main() {
	return 0;
}
