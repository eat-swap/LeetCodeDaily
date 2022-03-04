#include <iostream>
// #include <queue>

/**
 * 799. Champagne Tower
 * We stack glasses in a pyramid, where the first row has 1 glass, the second row has 2 glasses, and so on until the 100th row.  Each glass holds one cup of champagne.
 * Then, some champagne is poured into the first glass at the top.  When the topmost glass is full, any excess liquid poured will fall equally to the glass immediately to the left and right of it.  When those glasses become full, any excess champagne will fall equally to the left and right of those glasses, and so on.  (A glass at the bottom row has its excess champagne fall on the floor.)
 * For example, after one cup of champagne is poured, the top most glass is full.  After two cups of champagne are poured, the two glasses on the second row are half full.  After three cups of champagne are poured, those two cups become full - there are 3 full glasses total now.  After four cups of champagne are poured, the third row has the middle glass half full, and the two outside glasses are a quarter full, as pictured below.
 */

class Solution {
public:
	static constexpr double champagneTower(int poured, int query_row, int query_glass) {
		if (!poured)
			return 0.0;
		double G[102][102] {{static_cast<double>(poured)}};
		for (int i = 0; i < query_row; ++i) {
			for (int j = 0; j <= i; ++j) {
				if (G[i][j] > 1) {
					G[i + 1][j] += (G[i][j] - 1) / 2.0;
					G[i + 1][j + 1] += (G[i][j] - 1) / 2.0;
				}
			}
		}
		return G[query_row][query_glass] > 1.0 ? 1.0 : G[query_row][query_glass];
	}
};

int main() {
	std::cout << Solution::champagneTower(100000009, 33, 17);
	/*
	const int n = 6;
	double G[n][n] {};

	for (int t = 0; ; ++t) {
		std::queue<std::pair<std::pair<int, int>, double>> q;
		q.push({{0, 0}, 1.0});
		while (!q.empty()) {
			auto info = q.front();
			q.pop();
			int x = info.first.first, y = info.first.second;
			double val = info.second;
			double rem = G[x][y] + val - 1.0;
			if (rem > 0.0) {
				if (x + 1 < n) {
					q.push({{x + 1, y}, rem / 2.0});
					if (y + 1 < n)
						q.push({{x + 1, y + 1}, rem / 2.0});
				}
			} else {
				G[x][y] = std::min(1.0, G[x][y] + val);
			}
		}
		std::printf("t = %d\n", t);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= i; ++j) {
				std::printf("%.3lf ", G[i][j]);
			}
			std::printf("\n");
		}
		std::printf("--------------------------\n");
		std::getchar();
	}
	*/
	return 0;
}
