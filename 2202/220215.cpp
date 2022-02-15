#include <vector>
#include <cassert>
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
		int x = 0;
		for (int i : nums)
			x = x xor i;
		return x;
	}
};

class SolutionOld {
private:
	inline static const int maxN = 30000 + 3;
public:
	static int singleNumber(const std::vector<int>& nums) {
		int cnt[maxN << 1]{};
		for (int i : nums)
			++cnt[i + maxN];
		for (int i = 0; i < (maxN << 1); ++i)
			if (cnt[i] == 1)
				return i - maxN;
		assert(false);
		return -1;
	}
};

class SolutionOldOld {
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
	std::cout << Solution::singleNumber({1});
	return 0;
}
