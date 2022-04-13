#include <vector>
#include <iostream>

/**
 * 59. Spiral Matrix II
 * Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
 */

class Solution {
private:
	inline static const int dX[] = {0, 1, 0, -1};
	inline static const int dY[] = {1, 0, -1, 0};
public:
	static std::vector<std::vector<int>> generateMatrix(int n) {
		int* buf = new int[n * n]{};
		int direction = 0;

		auto GetNext = [&](int& x, int& y) {
			int nx = x + dX[direction], ny = y + dY[direction];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n || buf[nx * n + ny]) {
				direction = (1 + direction) % 4;
				nx = x + dX[direction], ny = y + dY[direction];
			}
			x = nx;
			y = ny;
		};

		int x = 0, y = 0;
		for (int i = 1; i <= n * n; ++i) {
			buf[x * n + y] = i;
			GetNext(x, y);
		}

		std::vector<std::vector<int>> ret;
		ret.reserve(n);
		for (int i = 0; i < n * n; i += n)
			ret.emplace_back(buf + i, buf + i + n);
		return ret;
	}
};

int main() {
	auto x = Solution::generateMatrix(4);
	for (const auto& i : x) {
		for (const auto& j : i) {
			std::cout << j << ' ';
		}
		std::cout << '\n';
	}
	return 0;
}
