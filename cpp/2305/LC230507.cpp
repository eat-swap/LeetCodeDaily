#include <algorithm>
#include <vector>

/**
 * 1964. Find the Longest Valid Obstacle Course at Each Position
 *
 * You want to build some obstacle courses. You are given a 0-indexed integer array obstacles of length n, where obstacles[i] describes the height of the ith obstacle.
 *
 * For every index i between 0 and n - 1 (inclusive), find the length of the longest obstacle course in obstacles such that:
 *
 * You choose any number of obstacles between 0 and i inclusive.
 * You must include the ith obstacle in the course.
 * You must put the chosen obstacles in the same order as they appear in obstacles.
 * Every obstacle (except the first) is taller than or the same height as the obstacle immediately before it.
 * Return an array ans of length n, where ans[i] is the length of the longest obstacle course for index i as described above.
 */

class LC230507 {
public:
	static std::vector<int> longestObstacleCourseAtEachPosition(const std::vector<int>&) noexcept;
};

constexpr inline int tree_size(int N) noexcept {
	int MSB = 0;
	for (; N > 1; N >>= 1)
		++MSB;
	return 1 << (MSB + 2);
}

template<int N>
class MaxSegTree final {
private:
	int tree[tree_size(N) + 5]{};

	int update_interval(int, int, int, int, int) noexcept;

	[[nodiscard]] int query_interval(int, int, int, int, int) const noexcept;

public:
	void update(int, int) noexcept;

	[[nodiscard]] int query(int, int) const noexcept;
};

template<int N>
int MaxSegTree<N>::query_interval(int L, int R, int index, int r_L, int r_R) const noexcept {
	if (L == r_L && R == r_R)
		return tree[index];
	const int r_M = (r_L + r_R) >> 1;
	if (R <= r_M)
		return query_interval(L, R, index << 1, r_L, r_M);
	if (r_M < L)
		return query_interval(L, R, index << 1 | 1, r_M + 1, r_R);
	return std::max(query_interval(L, r_M, index << 1, r_L, r_M), query_interval(r_M + 1, R, index << 1 | 1, r_M + 1, r_R));
}

template<int N>
int MaxSegTree<N>::update_interval(int L, int R, int index, int val, int cur_index) noexcept {
	if (L == R && L == index)
		return tree[cur_index] = val;
	const int M = (L + R) >> 1;
	if (index <= M)
		return tree[cur_index] = std::max(tree[cur_index << 1 | 1], update_interval(L, M, index, val, cur_index << 1));
	return tree[cur_index] = std::max(tree[cur_index << 1], update_interval(M + 1, R, index, val, cur_index << 1 | 1));
}

template<int N>
int MaxSegTree<N>::query(int L, int R) const noexcept {
	return query_interval(L, R, 1, 0, N - 1);
}

template<int N>
void MaxSegTree<N>::update(int index, int val) noexcept {
	update_interval(0, N - 1, index, val, 1);
}

std::vector<int> LC230507::longestObstacleCourseAtEachPosition(const std::vector<int>& obstacles) noexcept {
	const int n = obstacles.size();
	std::vector<int> ret(n), tmp;
	for (int i = 0; i < n; ++i) {
		int idx = std::upper_bound(tmp.begin(), tmp.end(), obstacles[i]) - tmp.begin();
		if (tmp.size() == idx)
			tmp.push_back(obstacles[i]);
		else
			tmp[idx] = obstacles[i];
		ret[i] = idx + 1;
	}
	return ret;
}
