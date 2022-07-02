#include <vector>
#include <algorithm>

/**
 * 1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
 * You are given a rectangular cake of size h x w and two arrays of integers horizontalCuts and verticalCuts where:
 * - horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, and
 * - verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.
 * Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays horizontalCuts and verticalCuts. Since the answer can be a large number, return this modulo 109 + 7.
 */

class Solution {
public:
	static int maxArea(int h, int w, std::vector<int>& hc, std::vector<int>& vc) {
		const int hcn = hc.size(), vcn = vc.size();
		std::sort(hc.begin(), hc.end());
		std::sort(vc.begin(), vc.end());
		int hm = std::max(hc.front(), h - hc.back()), vm = std::max(vc.front(), w - vc.back());
		for (int i = 1; i < hcn; ++i)
			hm = std::max(hm, hc[i] - hc[i - 1]);
		for (int i = 1; i < vcn; ++i)
			vm = std::max(vm, vc[i] - vc[i - 1]);
		return (static_cast<long long>(hm) * static_cast<long long>(vm)) % 1000000007;
	}
};
