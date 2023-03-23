#include <vector>
#include <functional>
#include <iostream>
#include <unordered_map>
#include <concepts>

template<typename T>
requires std::totally_ordered<T>
class MinMaxSegTree {
private:
	using V = std::vector<T>;
	using OF = const T& (*)(const T&, const T&);
	using BTF = std::function<T(int, int, int, const V&, V&, OF)>;

	int n;
	V s, b;

	static constexpr inline int calc(int n) {
		for (int i = 1; ; i <<= 1)
			if (i >= n)
				return i << 1;
	}

	T query(int L, int R, int qL, int qR, int pos, const V& tree, OF op) const {
		if (L == qL && R == qR)
			return tree[pos];
		const int qM = (qL + qR) >> 1;
		if (R <= qM)
			return query(L, R, qL, qM, pos << 1, tree, op);
		if (qM <= L)
			return query(L, R, qM, qR, 1 | (pos << 1), tree, op);
		return op(query(L, qM, qL, qM, pos << 1, tree, op), query(qM, R, qM, qR, 1 | (pos << 1), tree, op));
	}

public:
	explicit MinMaxSegTree(const std::vector<T>& d) : n(d.size()), s(calc(n)), b(calc(n)) {
		BTF dfs = [&](int L, int R, int pos, const V& src, V& dst, OF op) {
			if (L == R - 1)
				return dst[pos] = src[L];
			const int M = (L + R) >> 1;
			return dst[pos] = op(dfs(L, M, pos << 1, src, dst, op), dfs(M, R, 1 | (pos << 1), src, dst, op));
		};
		dfs(0, n, 1, d, s, std::min);
		dfs(0, n, 1, d, b, std::max);
	}

	T min(int L, int R) const {
		return query(L, R, 0, n, 1, s, std::min);
	}

	T max(int L, int R) const {
		return query(L, R, 0, n, 1, b, std::max);
	}
};

/**
 * 1630. Arithmetic Subarrays
 *
 * A sequence of numbers is called arithmetic if it consists of at least two elements, and the difference between every two consecutive elements is the same. More formally, a sequence s is arithmetic if and only if s[i+1] - s[i] == s[1] - s[0] for all valid i.
 *
 * For example, these are arithmetic sequences:
 *
 * 1, 3, 5, 7, 9
 * 7, 7, 7, 7
 * 3, -1, -5, -9
 * The following sequence is not arithmetic:
 *
 * 1, 1, 2, 5, 7
 * You are given an array of n integers, nums, and two arrays of m integers each, l and r, representing the m range queries, where the ith query is the range [l[i], r[i]]. All the arrays are 0-indexed.
 *
 * Return a list of boolean elements answer, where answer[i] is true if the subarray nums[l[i]], nums[l[i]+1], ... , nums[r[i]] can be rearranged to form an arithmetic sequence, and false otherwise.
 */

class Solution {
public:
	static std::vector<bool> checkArithmeticSubarrays(
		const std::vector<int>& nums,
		const std::vector<int>& l,
		const std::vector<int>& r
	) {
		auto tree = new MinMaxSegTree(nums);
		const int n = l.size(), k = nums.size();
		std::unordered_multimap<int, int> m;
		for (int i = 0; i < k; ++i)
			m.insert({nums[i], i});
		std::vector<bool> ret(n);
		for (int i = 0; i < n; ++i) {
			const int L = l[i], R = r[i] + 1, min = tree->min(L, R), max = tree->max(L, R);
			if ((max - min) % (R - L - 1))
				continue;
			int step = (max - min) / (R - L - 1);
			bool OK = true;
			for (int j = step + min; j < max; j += step) {
				const auto [MERs, MERe] = m.equal_range(j);
				if (!(OK = std::any_of(MERs, MERe, [L, R](auto&& x) { return x.second < R && x.second >= L; })))
					break;
			}
			ret[i] = OK;
		}
		delete tree;
		return ret;
	}
};

int main() {
	auto r = Solution::checkArithmeticSubarrays({-3,-6,-8,-4,-2,-8,-6,0,0,0,0},{1},{4});
	for (auto&& i : r) {
		std::cout << (i ? "true\n" : "false\n");
	}
}
