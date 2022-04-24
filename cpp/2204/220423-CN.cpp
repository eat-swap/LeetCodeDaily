#include <algorithm>
#include <vector>

/**
 * 587. Erect the Fence
 * You are given an array trees where trees[i] = [xi, yi] represents the location of a tree in the garden.
 * You are asked to fence the entire garden using the minimum length of rope as it is expensive. The garden is well fenced only if all the trees are enclosed.
 * Return the coordinates of trees that are exactly located on the fence perimeter.
 *
 * Note: it is all about computing the convex hull.
 */

class Solution {
public:
	static std::vector<std::vector<int>> outerTrees(std::vector<std::vector<int>>& trees) {
		std::sort(trees.begin(), trees.end(), [](const std::vector<int>& x, const std::vector<int>& y) { return x[0] == y[0] ? x[1] < y[1] : x[0] < y[0]; });
		int n = trees.size();
		std::vector<std::vector<int>> top, bottom;

		auto CrossProduct = [](const std::pair<int, int>& x, const std::pair<int, int>& y) {
			// x, y are vectors
			return x.first * y.second - x.second * y.first;
		};

		std::for_each(trees.cbegin(), trees.cend(), [&](const std::vector<int>& p) {
			while (bottom.size() > 1 && [&](){
				int n = bottom.size();
				const auto& b1 = bottom[n - 1];
				const auto& b2 = bottom[n - 2];
				return CrossProduct({b1[0] - b2[0], b1[1] - b2[1]}, {p[0] - b1[0], p[1] - b1[1]}) < 0;
			}()) bottom.pop_back();
			bottom.push_back(p);
		});

		std::for_each(trees.crbegin(), trees.crend(), [&](const std::vector<int>& p) {
			while (top.size() > 1 && [&](){
				int n = top.size();
				const auto& b1 = top[n - 1];
				const auto& b2 = top[n - 2];
				return CrossProduct({b1[0] - b2[0], b1[1] - b2[1]}, {p[0] - b1[0], p[1] - b1[1]}) < 0;
			}()) top.pop_back();
			top.push_back(p);
		});

		std::vector<std::vector<int>> ret;
		bool x[65536]{};
		for (const auto& p : top) {
			if (x[(p[0] << 8) | p[1]])
				continue;
			x[(p[0] << 8) | p[1]] = true;
			ret.push_back(p);
		}
		for (const auto& p : bottom) {
			if (x[(p[0] << 8) | p[1]])
				continue;
			x[(p[0] << 8) | p[1]] = true;
			ret.push_back(p);
		}
		return ret;
	}
};
