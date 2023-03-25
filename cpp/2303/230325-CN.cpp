#include <vector>
#include <map>
#include <algorithm>

int findLengthOfShortestSUBSEQUENCE(const std::vector<int>& arr) {
	const int n = arr.size();
	std::map<int, int> m;
	std::vector<int> dp(n);
	m[arr[0]] = dp[0] = 1;
	int ans = 1;
	for (int i = 1; i < n; ++i) {
		auto it = m.upper_bound(arr[i]);
		if (it == m.begin())
			ans = std::max(ans, m[arr[i]] = dp[i] = 1);
		else
			ans = std::max(ans, m[arr[i]] = dp[i] = 1 + (--it)->second);
	}
	return n - ans;
}

/**
 * 1574. Shortest Subarray to be Removed to Make Array Sorted
 *
 * Given an integer array arr, remove a subarray (can be empty) from arr such that the remaining elements in arr are non-decreasing.
 * Return the length of the shortest subarray to remove.
 * A subarray is a contiguous subsequence of the array.
 */

class Solution {
public:
	static int findLengthOfShortestSubarray(const std::vector<int>& arr) {
		const int n = arr.size();
		const int* d = arr.data();
		int L = 0, R = n - 1;
		for (; L + 1 < n && d[L + 1] >= d[L]; ++L);
		for (; R && d[R - 1] <= d[R]; --R);
		if (L >= R)
			return 0;
		int ans = ++L;
		for (int i = n - 1; i >= R; --i)
			ans = std::max(ans, int(std::upper_bound(d, d + L, d[i]) - d + n - i));
		return n - ans;
	}
};

int main() {
	Solution::findLengthOfShortestSubarray({10,13,17,21,15,15,9,17,22,22,13});
	return 0;
}
