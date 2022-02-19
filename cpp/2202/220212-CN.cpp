#include <vector>
#include <queue>
#include <random>
#include <ctime>
#include <chrono>
#include <iostream>

/**
 * 1020. Number of Enclaves
 * You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
 * A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
 * Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.
 */

class Solution {
private:
	inline static const int dX[] = {0, 1, 0, -1};
	inline static const int dY[] = {1, 0, -1, 0};
	inline static constexpr bool isValid(int x, int y, int m, int n) {
		return (x >= 0) && (y >= 0) && (x < m) && (y < n);
	}
	inline static constexpr bool isEdge(int x, int y, int m, int n) {
		return (!x) || (!y) || (x == m - 1) || (y == n - 1);
	}
public:
	static int numEnclaves(std::vector<std::vector<int>>& grid) {
		int m = grid.size(), n = grid.back().size();
		int s = m * n * 2 + 100;
		int* const q = new int[s];
		bool* const vis = new bool[m * n]{};
		int f = 0, r = 0;

		for (int i = 0; i < m; ++i) {
			const auto& t = grid[i];
			if (t[0]) {
				q[r++] = i;
				q[r++] = 0;
				vis[i * n] = true;
			}
			if (t[n - 1]) {
				q[r++] = i;
				q[r++] = n - 1;
				vis[i * n + (n - 1)] = true;
			}
		}

		const auto& tf = grid[0];
		for (int i = 0; i < n; ++i) {
			if (tf[i]) {
				q[r++] = 0;
				q[r++] = i;
				vis[i] = true;
			}
		}

		const auto& tb = grid[m - 1];
		for (int i = 0; i < n; ++i) {
			if (tb[i]) {
				q[r++] = m - 1;
				q[r++] = i;
				vis[(m - 1) * n + i] = true;
			}
		}

		while (f < r) {
			int x = q[f++];
			int y = q[f++];
			grid[x][y] = 0;
			for (int i = 0; i < 4; ++i) {
				int nx = x + dX[i], ny = y + dY[i];
				if (isValid(nx, ny, m, n) && !vis[nx * n + ny] && grid[nx][ny]) {
					q[r++] = nx;
					q[r++] = ny;
					vis[nx * n + ny] = true;
				}
			}
		}

		int ret = 0;
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				ret += grid[i][j];

		delete[] q;
		delete[] vis;
		return ret;
	}
};

int main() {
	const int SIZE = 500;
	std::mt19937 r(std::time(nullptr));
	std::vector<std::vector<int>> args;
	args.reserve(SIZE);
	for (int i = 0; i < SIZE; ++i) {
		args.emplace_back();
		auto& t = args.back();
		t.reserve(SIZE);
		for (int j = 0; j < SIZE; ++j)
			t.push_back(1);
	}
	const auto start = std::chrono::high_resolution_clock::now();
	int ans = Solution::numEnclaves(args);
	const auto end = std::chrono::high_resolution_clock::now();
	std::cout << ans << std::endl;
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms.\n";
	return 0;
}
