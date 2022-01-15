#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstring>

/**
 * 1345. Jump Game IV
 * Given an array of integers arr, you are initially positioned at the first index of the array.
 * In one step you can jump from index i to index:
 * i + 1 where: i + 1 < arr.length.
 * i - 1 where: i - 1 >= 0.
 * j where: arr[i] == arr[j] and i != j.
 * Return the minimum number of steps to reach the last index of the array.
 * Notice that you can not jump outside of the array at any time.
 */

class Solution {
private:
	inline static int dp[50005];
public:
	static auto minJumps(const std::vector<int>& arr) {
		int n = arr.size();
		std::unordered_map<int, std::vector<int>> m;
		for (int i = 0; i < n; ++i) {
			if (m.count(arr[i]))
				m[arr[i]].push_back(i);
			else
				m[arr[i]] = {i};
		}
		std::memset(dp, 0x3F, sizeof(int) * n);
		dp[0] = 0;

		if (m.size() > n / 3) {
			while (true) {
				int cnt = 0;
				for (int i = 1; i < n; ++i) {
					if (dp[i] > dp[i - 1] + 1) {
						++cnt;
						dp[i] = dp[i - 1] + 1;
					}
					if (i + 1 < n && dp[i] > dp[i + 1] + 1) {
						++cnt;
						dp[i] = dp[i + 1] + 1;
					}
					for (int j : m[arr[i]]) {
						if (dp[i] > dp[j] + 1) {
							++cnt;
							dp[i] = dp[j] + 1;
						}
					}
				}
				if (!cnt)
					break;
			}
		} else {
			while (true) {
				int cnt = 0;
				for (const auto& i : m) {
					int min = 0x3FFFFFFF;
					for (const auto& j : i.second) {
						if (j - 1 >= 0 && dp[j] > 1 + dp[j - 1]) {
							dp[j] = 1 + dp[j - 1];
							++cnt;
						}
						if (j + 1 < n && dp[j] > 1 + dp[j + 1]) {
							dp[j] = 1 + dp[j + 1];
							++cnt;
						}
						min = std::min(dp[j], min);
					}
					for (const auto& j : i.second) {
						if (min + 1 < dp[j]) {
							dp[j] = min + 1;
							++cnt;
						}
					}
				}
				if (!cnt)
					break;
			}
		}
		return dp[n - 1];
	}
};

int main() {
	// {100, -23, -23, 404, 100, 23, 23, 23, 3, 404}
	// {7, 6, 9, 6, 9, 6, 9, 7}
	std::vector<int> num;
	num.reserve(50000);
	for (int i = 0; i < 50000; ++i)
		num.push_back(7);
	std::cout << Solution::minJumps(num);
	return 0;
}