#include <algorithm>
#include <cstdint>
#include <functional>
#include <unordered_map>
#include <vector>
#include <set>

/**
 * 1035. Uncrossed Lines
 *
 * You are given two integer arrays nums1 and nums2. We write the integers of nums1 and nums2 (in the order they are given) on two separate horizontal lines.
 *
 * We may draw connecting lines: a straight line connecting two numbers nums1[i] and nums2[j] such that:
 *
 * nums1[i] == nums2[j], and
 * the line we draw does not intersect any other connecting (non-horizontal) line.
 * Note that a connecting line cannot intersect even at the endpoints (i.e., each number can only belong to one connecting line).
 *
 * Return the maximum number of connecting lines we can draw in this way.
 */

class LC230511 {
public:
	using CVIR = const std::vector<int>&;
	static int maxUncrossedLines(CVIR, CVIR) noexcept;
};

int LC230511::maxUncrossedLines(const std::vector<int>& nums1, const std::vector<int>& nums2) noexcept {
	const int p = nums1.size(), q = nums2.size();
	std::unordered_map<int, std::set<int>> m[2];
	for (int i = 0; i < p; ++i)
		m[0][nums1[i]].insert(i);
	for (int i = 0; i < q; ++i)
		m[1][nums2[i]].insert(i);

	std::int16_t dp[512][512];
	std::memset(dp, -1, sizeof dp);
	std::function<std::int16_t(int, int)> solve = [&](int pos_1, int pos_2) {
		auto& ans = dp[pos_1][pos_2];
		if (ans >= 0)
			return ans;
		if (pos_1 >= p || pos_2 >= q)
			return ans = 0;
		ans = std::max(solve(pos_1 + 1, pos_2), solve(pos_1, pos_2 + 1));

		// Select in nums1
		auto& n1p1_in_n2 = m[1][nums1[pos_1]];
		if (auto it = n1p1_in_n2.lower_bound(pos_2); it != n1p1_in_n2.end())
			ans = std::max(ans, std::int16_t(solve(pos_1 + 1, *it + 1) + 1));

		// Select in nums2
		auto& n2p2_in_n1 = m[0][nums2[pos_2]];
		if (auto it = n2p2_in_n1.lower_bound(pos_1); it != n2p2_in_n1.end())
			ans = std::max(ans, std::int16_t(solve(*it + 1, pos_2 + 1) + 1));

		return ans;
	};

	return solve(0, 0);
}

using Solution = LC230511;
