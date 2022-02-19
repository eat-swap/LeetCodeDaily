#include <vector>
#include <unordered_set>

/**
 * 1748. Sum of Unique Elements
 * You are given an integer array nums. The unique elements of an array are the elements that appear exactly once in the array.
 * Return the sum of all the unique elements of nums.
 */

class Solution {
public:
	static int sumOfUnique(const std::vector<int>& nums) {
		int ans = 0;
		std::unordered_multiset<int> s;
		for (int x : nums) {
			switch (s.count(x)) {
				case 0:
					ans += x;
					break;
				case 1:
					ans -= x;
			}
			s.insert(x);
		}
		return ans;
	}
};

int main() {
	// No testing code.
	return 0;
}
