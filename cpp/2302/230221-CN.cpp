#include <vector>
#include <algorithm>
#include <cstdio>

/**
 * 1326. Minimum Number of Taps to Open to Water a Garden
 *
 * There is a one-dimensional garden on the x-axis. The garden starts at the point 0 and ends at the point n. (i.e The length of the garden is n).
 * There are n + 1 taps located at points [0, 1, ..., n] in the garden.
 * Given an integer n and an integer array ranges of length n + 1 where ranges[i] (0-indexed) means the i-th tap can water the area [i - ranges[i], i + ranges[i]] if it was open.
 * Return the minimum number of taps that should be open to water the whole garden, If the garden cannot be watered return -1.
 */

class Solution {
public:
	static int minTaps(int n, const std::vector<int>& ranges) {
		std::vector<int> adv(n + 1, -1);
		for (int i = 0; i <= n; ++i) {
			if (!ranges[i])
				continue;
			// L, R inclusive
			int L = std::max(0, i - ranges[i]), R = std::min(n, i + ranges[i]);
			for (int j = L; j <= R; ++j)
				adv[j] = std::max(adv[j], R);
		}
		int ans = 0;
		for (int i = 0; i < n; ++ans) {
			if (adv[i] < i || (i == adv[i] && i < n))
				return -1;
			i = adv[i];
		}
		return ans;
	}
};

int main() {
	std::printf("%d\n", Solution::minTaps(35, {1,0,4,0,4,1,4,3,1,1,1,2,1,4,0,3,0,3,0,3,0,5,3,0,0,1,2,1,2,4,3,0,1,0,5,2}));
	std::printf("%d\n", Solution::minTaps(7, {1,2,1,0,2,1,0,1}));
	std::printf("%d\n", Solution::minTaps(3, {0,0,0,0}));
	std::printf("%d\n", Solution::minTaps(5, {3,0,1,1,0,0}));
}
