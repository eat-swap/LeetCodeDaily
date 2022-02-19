#include <vector>
#include <iostream>

/**
 * 1725. Number Of Rectangles That Can Form The Largest Square
 * You are given an array rectangles where rectangles[i] = [li, wi] represents the ith rectangle of length li and width wi.
 * You can cut the ith rectangle to form a square with a side length of k if both k <= li and k <= wi. For example, if you have a rectangle [4,6], you can cut it to get a square with a side length of at most 4.
 * Let maxLen be the side length of the largest square you can obtain from any of the given rectangles.
 * Return the number of rectangles that can make a square with a side length of maxLen.
 */

class Solution {
public:
	static int countGoodRectangles(const std::vector<std::vector<int>>& rectangles) {
		auto it = std::max_element(rectangles.begin(), rectangles.end(), [](const std::vector<int>& x, const std::vector<int>& y) { return std::min(x[0], x[1]) < std::min(y[0], y[1]); });
		return std::count_if(rectangles.begin(), rectangles.end(), [&it](const std::vector<int>& x) { return std::min(x[0], x[1]) >= std::min(it->front(), it->back()); });
	}
};

int main() {
	std::cout << Solution::countGoodRectangles({{5,8},{3,9},{5,12},{16,5}});
	return 0;
}
