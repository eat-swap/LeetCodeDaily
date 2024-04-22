#include <vector>
#include <queue>

class LC240419 {
public:
    int numIslands(std::vector<std::vector<char>>& grid);
};

const int dX[4] = {0, 1, 0, -1};
const int dY[4] = {1, 0, -1, 0};

int LC240419::numIslands(std::vector<std::vector<char>>& grid) {
	const int m = grid.size(), n = grid.front().size();
	int ret = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (grid[i][j] == '0')
				continue;
			std::queue<int> q;
			q.push(i);
			q.push(j);
			++ret;
			grid[i][j] = '0';
			while (!q.empty()) {
				int x = q.front();
				q.pop();
				int y = q.front();
				q.pop();
				for (int d = 0; d < 4; ++d) {
					int nx = x + dX[d];
					int ny = y + dY[d];
					if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] != '0') {
						q.push(nx);
						q.push(ny);
						grid[nx][ny] = '0';
					}
				}
			}
		}
	}
	return ret;
}
