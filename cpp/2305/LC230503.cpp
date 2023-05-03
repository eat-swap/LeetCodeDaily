#include <algorithm>
#include <iterator>
#include <vector>
#include <unordered_set>

/**
 * 2215. Find the Difference of Two Arrays
 *
 * Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:
 * answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
 * answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
 * Note that the integers in the lists may be returned in any order.
 */

class LC230503 {
public:
	template<typename T>
	using V = std::vector<T>;
	using VVI = V<V<int>>;
	using CVIR = const V<int>&;

	static VVI findDifference(CVIR, CVIR) noexcept;
};

LC230503::VVI LC230503::findDifference(CVIR x, CVIR y) noexcept {
	using USI = std::unordered_set<int>;
	USI sx(x.begin(), x.end()), sy(y.begin(), y.end());
	auto proc = [&](const USI& p, const USI& q) {
		V<int> r;
		std::copy_if(p.begin(), p.end(), std::back_inserter(r), [&](int n) {
			return !q.count(n);
		});
		return r;
	};
	return {proc(sx, sy), proc(sy, sx)};
}
