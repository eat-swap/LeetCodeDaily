#include <vector>
#include <bitset>

/**
 * 54. Spiral Matrix
 *
 * Given an m x n matrix, return all elements of the matrix in spiral order.
 */

class LC230509 {
private:
	static inline constexpr int dX[] = {0, 1, 0, -1};
	static inline constexpr int dY[] = {1, 0, -1, 0};

public:
	static std::vector<int> spiralOrder(const std::vector<std::vector<int>>&) noexcept;
};

template<typename T>
constexpr bool is_valid(T x, T y, T m, T n) {
	return (x >= 0) && (x < m) && (y >= 0) && (y < n);
}

std::vector<int> LC230509::spiralOrder(const std::vector<std::vector<int>>& G) noexcept {
	const int m = G.size(), n = G.front().size(), k = m * n;
	std::vector<int> ret(k);
	std::bitset<128> vis;
	for (int pos = 0, x = 0, y = 0, d = 0;;) {
		ret[pos] = G[x][y];
		if (++pos >= k)
			break;
		vis[x * n + y] = true;
		if (!is_valid(x + dX[d], y + dY[d], m, n) || vis[(x + dX[d]) * n + (y + dY[d])])
			d = (d + 1) & 3;
		x += dX[d];
		y += dY[d];
	}
	return ret;
}

using Solution = LC230509;
