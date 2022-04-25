#include <vector>
#include <random>
#include <ctime>
#include <unordered_map>

/**
 * 398. Random Pick Index
 * Given an integer array nums with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.
 * Implement the Solution class:
 * Solution(int[] nums) Initializes the object with the array nums.
 * int pick(int target) Picks a random index i from nums where nums[i] == target. If there are multiple valid i's, then each index should have an equal probability of returning.
 */

class Solution {
private:
	std::unordered_map<int, std::vector<int>> m;

	std::mt19937 r;

public:
	explicit Solution(const std::vector<int>& nums) : r(std::time(nullptr)) {
		auto x = nums.size();
		while (x--) {
			m[nums[x]].push_back(x);
		}
	}

	int pick(int target) {
		return m[target][r() % m[target].size()];
	}
};
