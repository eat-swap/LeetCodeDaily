#include <vector>
#include <algorithm>
#include <iostream>

/**
 * 307. Range Sum Query - Mutable
 * Given an integer array nums, handle multiple queries of the following types:
 *
 * Update the value of an element in nums.
 * Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
 * Implement the NumArray class:
 *
 * NumArray(int[] nums) Initializes the object with the integer array nums.
 * void update(int index, int val) Updates the value of nums[index] to be val.
 * int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
 */

#ifdef GENERIC
#include <map>
#ifdef LOCAL
template<int maxCacheSize>
#endif
class NumArray {
private:
#ifndef LOCAL
	static inline const int maxCacheSize = 192;
#endif
	std::vector<int> n;

	std::vector<int> prefixSum;

	std::map<int, int> alterCache;
public:
	explicit NumArray(std::vector<int> nums) : n(std::move(nums)) {
		prefixSum.reserve(n.size());
		int s = 0;
		for (int x : n) {
			s += x;
			prefixSum.push_back(s);
		}
	}

	void update(int index, int val);

	int sumRange(int left, int right) const;
};

void NumArray::update(int index, int val) {
	alterCache[index] = val;
	if (alterCache.size() < maxCacheSize)
		return;
	int offset = 0, nSize = n.size();
	for (auto it = std::next(alterCache.cbegin()); it != alterCache.cend(); ++it) {
		auto itPrev = std::prev(it);
		offset += itPrev->second - n[itPrev->first];
		for (int i = itPrev->first; i < it->first; ++i)
			prefixSum[i] += offset;
	}
	offset += alterCache.crbegin()->second - n[alterCache.crbegin()->first];
	for (int i = alterCache.crbegin()->first; i < nSize; ++i)
		prefixSum[i] += offset;
	for (const auto& [i, v] : alterCache)
		n[i] = v;
	alterCache.clear();
}

int NumArray::sumRange(int left, int right) const {
	int result = prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);
	for (const auto& [i, v] : alterCache)
		if (i >= left && i <= right)
			result += v - n[i];
	return result;
}
#endif // GENERIC

// Segment Tree
#ifndef GENERIC
class NumArray {
private:
	static inline const int maxSizeBit = 15;
	static inline const int maxSize = 1 << maxSizeBit;

	int segTree[maxSize << 1];

	int n;
public:
	explicit NumArray(const std::vector<int>& nums) {
		n = nums.size();
		for (int i = 0; i < n; ++i)
			segTree[i + maxSize] = nums[i];
		// Build
		for (int i = maxSize >> 1; i; i >>= 1)
			for (int j = i; j < (i << 1); ++j)
				segTree[j] = segTree[j << 1] + segTree[1 + (j << 1)];
	}

	void update(int index, int val) {
		int offset = val - segTree[index + maxSize];
		for (int i = index + maxSize; i; i >>= 1)
			segTree[i] += offset;
	}

	int sumRange(int left, int right) const {
		std::function<int(int, int, int)> query = [&](int o, int L, int R) {
			int M = L + ((R - L) >> 1), ret = 0;
			if (left <= L && R <= right)
				return segTree[o];
			if (left <= M)
				ret += query(o << 1, L, M);
			if (M < right)
				ret += query(1 + (o << 1), M + 1, R);
			return ret;
		};
		return query(1, 0, maxSize - 1);
	}
};
#endif // GENERIC

int main() {
	return 0;
}
