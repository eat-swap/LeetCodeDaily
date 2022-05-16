#include <vector>
#include <iostream>

/**
 * 1091. Shortest Path in Binary Matrix
 * Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.
 *
 * A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
 *
 * All the visited cells of the path are 0.
 * All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
 * The length of a clear path is the number of visited cells of this path.
 */

class Solution {
public:
	static int shortestPathBinaryMatrix(const std::vector<std::vector<int>>& grid) {
		const int n = grid.size();
		if (grid[0][0])
			return -1;

		std::vector<bool> vis(n * n);
		int queue[10003]; // Array emulated
		int front = 0, rear = 1; // queue

		while (rear > front) {
			int pos = queue[front++];
			// pos = x * n + y;
			int depth = pos >> 16;
			pos &= 0xFFFF;
			int y = pos % n, x = pos / n;

			if (x == n - 1 && y == n - 1) {
				return depth + 1;
			}

			for (int i = -1; i <= 1; ++i) {
				for (int j = -1; j <= 1; ++j) {
					if ((!i && !j) || (x + i < 0 || x + i >= n || y + j < 0 || y + j >= n) || vis[pos + j + i * n] || grid[x + i][y + j])
						continue;
					vis[pos + j + i * n] = true;
					queue[rear++] = (pos + j + i * n) | ((1 + depth) << 16);
				}
			}
		}
		return -1;
	}
};

int main() {
	std::cout << Solution::shortestPathBinaryMatrix({{0,0,0},{1,1,0},{1,1,0}});
}
