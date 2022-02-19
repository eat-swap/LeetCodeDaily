#include <vector>

/**
 * 189. Rotate Array
 * Given an array, rotate the array to the right by k steps, where k is non-negative.
 * Input: nums = [1,2,3,4,5,6,7], k = 3
 * Output: [5,6,7,1,2,3,4]
 * Explanation:
 * rotate 1 steps to the right: [7,1,2,3,4,5,6]
 * rotate 2 steps to the right: [6,7,1,2,3,4,5]
 * rotate 3 steps to the right: [5,6,7,1,2,3,4]
 */

class Solution {
public:
	static void rotate(std::vector<int>& nums, int k) {
		k %= nums.size();
		std::vector<int> ret(nums.end() - k, nums.end());
		ret.insert(ret.end(), nums.begin(), nums.end() - k);
		nums = ret;
	}
};

int main() {
	std::vector<int> arg {1,2,3};
	Solution::rotate(arg, 1);
	return 0;
}