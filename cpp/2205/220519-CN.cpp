#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
	static int minMoves2(std::vector<int>& nums) {
		std::stable_sort(nums.begin(), nums.end());
		long long sum = std::accumulate(nums.begin(), nums.end(), 0), psum = 0;
		long long ret = 0x7FFFFFFF;
		const int n = nums.size();
		for (int i = 0; i < n; ++i) {
			ret = std::min(ret, (sum - psum + (long long)(i * 2 - n) * nums[i]));
			sum -= nums[i];
			psum += nums[i];
		}
		return ret;
	}
};

int main() {
	std::vector<int> args {203125577,-349566234,230332704,48321315,66379082,386516853,50986744,-250908656,-425653504,-212123143};
	Solution::minMoves2(args);

	return 0;
}
