#include <vector>

/**
 * 289. Game of Life
 * According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
 *
 * The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):
 *
 * Any live cell with fewer than two live neighbors dies as if caused by under-population.
 * Any live cell with two or three live neighbors lives on to the next generation.
 * Any live cell with more than three live neighbors dies, as if by over-population.
 * Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
 * The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.
 */

class Solution {
public:
	static void gameOfLife(std::vector<std::vector<int>>& board) {
		int m = board.size(), n = board.front().size();
		auto GetIfValid = [&](int x, int y) {
			return (x >= 0 && y >= 0 && x < m && y < n) ? board[x][y] & 1 : 0;
		};
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				int c = -board[i][j];
				for (int di = -1; di <= 1; ++di)
					for (int dj = -1; dj <= 1; ++dj)
						c += GetIfValid(i + di, j + dj);
				switch (c) {
					case 2:
						if (!(board[i][j] & 1))
							break;
					case 3:
						board[i][j] |= 2;
					default:;
				}
			}
		}
		for (auto& i : board)
			for (auto& j : i)
				j >>= 1;
	}
};
