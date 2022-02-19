#include <vector>
#include <iostream>
#include <random>
#include <ctime>
#include <chrono>

/**
 * 84. Largest Rectangle in Histogram
 * Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
 */

class Solution {
private:
	// Interval [L, R)
	static int dAC(const std::vector<int>& heights, int L, int R) {
		if (R - L <= 1)
			return heights[L];
		const auto minPos = std::distance(heights.begin(), std::min_element(heights.begin() + L, heights.begin() + R));
		const auto minVal = heights[minPos];
		int ans = (R - L) * minVal;
		if (minPos - L >= 1) {
			int nextR = minPos;
			while (nextR - L > 1 && heights[nextR - 1] <= minVal)
				--nextR;
			ans = std::max(ans, dAC(heights, L, nextR));
		}
		if (R - minPos > 1) {
			int nextL = minPos + 1;
			while (R - nextL > 1 && heights[nextL] <= minVal)
				++nextL;
			ans = std::max(ans, dAC(heights, nextL, R));
		}
		return ans;
	}
public:
	static int largestRectangleArea(const std::vector<int>& heights) {
		return dAC(heights, 0, heights.size());
	}
};

int main() {
	std::vector<int> sample{3, 6, 5, 7, 4, 8, 1, 0};
	std::cout << Solution::largestRectangleArea(sample) << std::endl;
	const int LIM = 100000;
	std::mt19937 r(time(nullptr));
	std::vector<int> arg;
	arg.reserve(LIM);
	for (int i = 0; i < LIM; ++i) {
		arg.push_back(r() % 10000);
	}
	const auto start = std::chrono::high_resolution_clock::now();
	std::cout << Solution::largestRectangleArea(arg) << std::endl;
	const auto end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms.\n";
	return 0;
}
