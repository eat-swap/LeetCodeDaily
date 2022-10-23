#include <vector>

/**
 * 645. Set Mismatch
 *
 * You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.
 * You are given an integer array nums representing the data status of this set after the error.
 * Find the number that occurs twice and the number that is missing and return them in the form of an array.
 */

class Solution {
public:
	static std::vector<int> findErrorNums(const std::vector<int>& n) {
		int x = 0, y = 0, m = n.size();
		std::vector<bool> s(m);
		for (int i = 0; i < m; ++i) {
			if (s[n[i] - 1])
				x = n[i];
			s[n[i] - 1] = true;
			y ^= (i + 1) ^ n[i];
		}
		return {x, x ^ y};
	}
};
