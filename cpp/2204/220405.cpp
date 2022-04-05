#include <vector>
#include <iostream>
#include <cstring>

/**
 * 11. Container With Most Water
 * You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
 * Find two lines that together with the x-axis form a container, such that the container contains the most water.
 * Return the maximum amount of water a container can store.
 * Notice that you may not slant the container.
 */

class Solution {
private:
	static inline const int MAX_HEIGHT = 10000 + 2;
public:
	static int maxArea(const std::vector<int>& height) {
		int minPos[MAX_HEIGHT], maxPos[MAX_HEIGHT], n = height.size();
		std::memset(minPos, 0x01, sizeof minPos); // 0x01010101
		std::memset(maxPos, 0xFF, sizeof maxPos); // -1
		for (int i = 0; i < n; ++i) {
			minPos[height[i]] = std::min(minPos[height[i]], i);
			maxPos[height[i]] = std::max(maxPos[height[i]], i);
		}
		int ans = 0, nowMax = -1, nowMin = 0x7FFFFFFF;
		for (int i = MAX_HEIGHT - 1; i; --i) {
			if (maxPos[i] >= 0) {
				nowMax = std::max(nowMax, maxPos[i]);
				nowMin = std::min(nowMin, minPos[i]);
				ans = std::max(ans, (nowMax - nowMin) * i);
			}
		}
		return ans;
	}
};

int main() {
	std::cout << Solution::maxArea({1, 2});
	return 0;
}
