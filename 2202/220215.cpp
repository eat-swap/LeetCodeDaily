#include <vector>
#include <iostream>
#include <unordered_set>

/**
 * 136. Single Number
 * Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
 * You must implement a solution with a linear runtime complexity and use only constant extra space.
 */

class Solution {
public:
	static int singleNumber(const std::vector<int>& nums) {
		std::unordered_set<int> s;
		for (int i : nums)
			if (s.count(i))
				s.erase(i);
			else
				s.insert(i);
		return *s.begin();
	}
};

int main() {
	std::cout << Solution::singleNumber({4,1,2,1,2});
	return 0;
}
