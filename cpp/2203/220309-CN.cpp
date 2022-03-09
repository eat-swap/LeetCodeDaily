#include <vector>
#include <cstring>
#include <iostream>

class Solution {
public:
	static int bestRotation(const std::vector<int>& nums) {
		int n = nums.size(), rotates[n];
		std::memset(rotates, 0, sizeof rotates);

		for (int i = 0; i < n; ++i)
			if (nums[i] < n)
				++rotates[(i - nums[i] + 1 + n) % n];

		int ret = 0, retMax = 0;
		for (int i = 0; i < n; ++i)
			if (nums[i] <= i)
				++retMax;

		int now = retMax;
		for (int i = 1; i <= n; ++i) {
			// i -> i + 1
			now -= rotates[i % n];
			if (nums[i - 1] < n)
				++now;
			if (now > retMax) {
				retMax = now;
				ret = i;
			}
		}
		return ret % n;
	}
};

int main() {
	std::cout << Solution::bestRotation({2,3,1,4,0}) << "\n";
	std::cout << Solution::bestRotation({1,3,0,2,4});
	return 0;
}
