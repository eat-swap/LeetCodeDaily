#include <vector>

/**
 * 713. Subarray Product Less Than K
 * Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.
 */

class Solution {
public:
	static int numSubarrayProductLessThanK(const std::vector<int>& nums, int k) {
		long long t = nums[0];
		int ans = (nums[0] < k) ? 1 : 0;
		const int n = nums.size();
		// Range [i, j) --> product = t
		for (int i = 0, j = 1; j < n; ++j) {
			// t now: product of range [i, j)
			while (t * nums[j] >= k && i < j) {
				// Advance i
				// After this, i will be at most j.
				t /= nums[i++];
			}
			// t now: product of range [i, j]
			t *= nums[j];
			// [i, j] is now sufficient to be an answer, if nums[j] < k
			if (j - i >= 0 && nums[j] < k)
				// Non-contiguous array: += 1 << (j - i);
				ans += j - i + 1;
			// j <- 1 + j, at the start of next loop, t will again be product of range [i, j).
		}
		return ans;
	}
};

int main() {
	std::printf("%d\n", Solution::numSubarrayProductLessThanK({10,5,2,6},100));
}
