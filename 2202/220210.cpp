#include <vector>
#include <cstdio>
#include <unordered_map>

class Solution {
public:
	static int subarraySum(const std::vector<int>& nums, int k) {
		int sum = 0, ret = 0;
		std::unordered_map<int, int> m;
		m.reserve(nums.size());
		m[0] = 1;
		for (int i : nums) {
			ret += m[(sum += i) - k];
			++m[sum];
		}
		return ret;
	}
};

int main() {
	std::printf("%d\n", Solution::subarraySum({1,2,3}, 3));
	return 0;
}
