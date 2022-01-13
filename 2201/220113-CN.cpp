#include <vector>
#include <iostream>

class Solution {
public:
	static int dominantIndex(const std::vector<int>& nums) {
		int a = 0, b = -1, n = nums.size();
		if (n == 1)
			return 0;
		for (int i = 1; i < n; ++i) {
			if (nums[i] > nums[a]) {
				b = a;
				a = i;
			} else if (b < 0 || nums[i] > nums[b]) {
				b = i;
			}
		}
		if (b < 0 || (nums[a]) < (nums[b] << 1))
			return -1;
		return a;
	}
};

int main() {
	std::cout << Solution::dominantIndex({1, 0});
}