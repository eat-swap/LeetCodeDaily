#include <vector>
#include <iostream>

class Solution {
private:
	static int partitionDisjoint_1(const std::vector<int>& nums) {
		const int n = nums.size();
		std::vector<int> max_until(n), min_since(n);
		max_until[0] = nums[0];
		min_since[n - 1] = nums[n - 1];
		for (int i = 1; i < n; ++i)
			max_until[i] = std::max(max_until[i - 1], nums[i]);
		for (int i = n - 1; i--; )
			min_since[i] = std::min(min_since[i + 1], nums[i]);
		for (int i = 1; i < n; ++i)
			if (max_until[i - 1] <= min_since[i])
				return i;
		return -1;
	}

	static int partitionDisjoint_2(const std::vector<int>& nums) {
		const int n = nums.size();
		std::vector<int> min_since(n);
		min_since[n - 1] = nums[n - 1];
		for (int i = n - 1; i--; )
			min_since[i] = std::min(min_since[i + 1], nums[i]);
		int max_until = nums[0];
		for (int i = 1; i < n; ++i) {
			if (max_until <= min_since[i])
				return i;
			max_until = std::max(max_until, nums[i]);
		}
		return -1;
	}

public:
	static int partitionDisjoint(const std::vector<int>& nums) {
		const int n = nums.size();
		std::vector<int> min_since(n);
		min_since[n - 1] = nums[n - 1];
		for (int i = n - 1; i--; )
			min_since[i] = std::min(min_since[i + 1], nums[i]);
		int max_until = 0;
		for (int i = 1; i < n; ++i)
			if ((max_until = std::max(max_until, nums[i - 1])) <= min_since[i])
				return i;
		return -1;
	}
};

int main() {
	std::cout << Solution::partitionDisjoint({1,1,1,0,6,12});

	// todo: METRIC

	return 0;
}
