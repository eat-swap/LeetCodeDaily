#include <vector>
#include <unordered_set>
#include <cstdio>

/**
 * 1695. Maximum Erasure Value
 * You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.
 * Return the maximum score you can get by erasing exactly one subarray.
 * An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).
 */

class Solution {
public:
	static int maximumUniqueSubarray(const std::vector<int>& nums) {
		std::unordered_set<int> s;
		const int n = nums.size();
		int sum = 0, ret = 0;
		for (int i = 0, l = 0; i < n; ++i) {
			std::printf("In loop, i = %d, l = %d\nStart inserting: ", i, l);
			for (; i < n && !s.count(nums[i]); ++i) {
				sum += nums[i];
				s.insert(nums[i]);
				std::printf("%d ", nums[i]);
			}
			ret = std::max(ret, sum);

			if (i == n)
				break;

			std::printf("\nEnd inserting at position %d, nums[i] = %d, updating ret <- %d\nStart popping: ", i, nums[i], ret);

			// pop until reach nums[i]
			for (; nums[l] != nums[i]; ++l) {
				s.erase(nums[l]);
				sum -= nums[l];
				std::printf("%d ", nums[l]);
			}
			++l; // where nums[l] == nums[i]
			std::printf("\nEnd loop, where i = %d, l = %d\n\n", i, l);
		}

		return ret;
	}
};

int main() {
	std::printf("%d\n", Solution::maximumUniqueSubarray({
		187
	}));

	return 0;
}
