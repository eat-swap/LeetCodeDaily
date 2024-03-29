#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <set>

/**
 * 1637. Widest Vertical Area Between Two Points Containing No Points
 *
 * Given n points on a 2D plane where points[i] = [xi, yi], Return the widest vertical area between two points such that no points are inside the area.
 * A vertical area is an area of fixed-width extending infinitely along the y-axis (i.e., infinite height). The widest vertical area is the one with the maximum width.
 * Note that points on the edge of a vertical area are not considered included in the area.
 */

class Solution {
public:
	static auto maxWidthOfVerticalArea(const std::vector<std::vector<int>>& p) {
		std::set<int> v;
		std::transform(p.begin(), p.end(), std::inserter(v, v.begin()), [](auto&& x) { return x[0]; });
		auto r = 0;
		for (auto i = std::next(v.begin()); i != v.end(); ++i)
			r = std::max(r, *i - *std::prev(i));
		return r;
	}
};