#include <vector>
#include <string>
#include <cstdint>
#include <queue>
#include <iostream>

/**
 * 1728. Cat and Mouse Game II
 *
 * Sorry, but I cannot solve this problem.
 * The solution is incorrect,
 */

class Solution {
private:
	// G: 0 -> Empty, 1 -> Wall
	uint8_t G[8][8]{};

	// Status: 0 -> Not explored, 1 -> Win by Cat, 2 -> Win by Mouse;
	// 8192 (13 bits) -> Prev. move (0 cat, 1 mouse) | Cat X, Cat Y, Mouse X, Mouse Y.
	uint8_t status[8192]{};

	uint8_t m{}, n{}, fX{}, fY{}, cX{}, cY{}, mX{}, mY{};

	static inline const int dX[] = {0, 1, 0, -1};

	static inline const int dY[] = {1, 0, -1, 0};

public:
	bool canMouseWin(const std::vector<std::string>& grid, int catJump, int mouseJump) {
		m = grid.size();
		n = grid.front().size();

		// Write initial info
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				switch (grid[i][j]) {
					case '#':
						G[i][j] = 1;
						break;
					case 'F':
						fX = i;
						fY = j;
						break;
					case 'C':
						cX = i;
						cY = j;
						break;
					case 'M':
						mX = i;
						mY = j;
						break;
					default:;
				}
			}
		}

		// Set initial status
		std::queue<uint16_t> q;

		// 1) Mouse/Cat Reached food
		for (int i = 0, foodPos = (fX << 3) + fY; i < 64; ++i) {
			status[(i << 6) | foodPos | 4096] = status[(i << 6) | foodPos] = 2; // Mouse
			status[(foodPos << 6) | i | 4096] = status[(foodPos << 6) | i] = 1; // Cat

			q.push((1 << 12) | (i << 6) | foodPos);
			q.push((1 << 12) | (foodPos << 6) | i);
			q.push((i << 6) | foodPos);
			q.push((foodPos << 6) | i);
		}

		// 2) Same position
		for (int i = 0; i < 64; ++i) {
			status[(i << 6) | i | 4096] = status[(i << 6) | i] = 1;

			q.push((1 << 12) | (i << 6) | i);
			q.push((i << 6) | i);
		}

		while (!q.empty()) {
			uint16_t cur = q.front(); q.pop();

			const bool isMouseMove = cur & (1 << 12);
			const uint8_t catX = (cur >> 9) & 7,
					catY = (cur >> 6) & 7,
					mouseX = (cur >> 3) & 7,
					mouseY = cur & 7,
					s = status[cur];

			if (isMouseMove && s == 2) {
				// Previous moved by mouse, then reached here!
				// From each position where mouse can reach here, the mouse wins.
				for (int i = 0; i < 4; ++i) {
					for (int j = 0; j <= mouseJump; ++j) {
						auto nX = mouseX + j * dX[i], nY = mouseY + j * dY[i];
						if (G[nX][nY] || nX >= m || nX < 0 || nY >= n || nY < 0)
							break; // Cannot move forward
						if (nX == catX && nY == catY)
							continue; // Is cat
						// if not visited
						if (!status[((cur & ~63) | ((nX << 3) + nY)) & ~(1 << 12)]) {
							status[((cur & ~63) | ((nX << 3) + nY)) & ~(1 << 12)] = 2;
							q.push(((cur & ~63) | ((nX << 3) + nY)) & ~(1 << 12));
						}
					}
				}
			} else if (!isMouseMove && s == 1) {
				for (int i = 0; i < 4; ++i) {
					for (int j = 0; j <= catJump; ++j) {
						auto nX = catX + j * dX[i], nY = catY + j * dY[i];
						if (G[nX][nY] || nX >= m || nX < 0 || nY >= n || nY < 0)
							break; // Cannot move forward
						// if not visited
						if (!status[((cur & 63) | ((nX << 9) + (nY << 6))) | (1 << 12)]) {
							status[((cur & 63) | ((nX << 9) + (nY << 6))) | (1 << 12)] = 1;
							q.push(((cur & 63) | ((nX << 9) + (nY << 6))) | (1 << 12));
						}
					}
				}
			}
		}

		return status[(cX << 9) | (cY << 6) | (mX << 3) | mY];
	}
};

int main() {
	Solution s;
	std::cout << (s.canMouseWin({"####F","#C...","M...."}, 1, 2) ? "true" : "false");
}
