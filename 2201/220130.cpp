#include <iostream>
#include <vector>

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