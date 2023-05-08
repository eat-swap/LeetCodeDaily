#include <bitset>
#include <queue>
#include <cstdint>
#include <tuple>
#include <vector>

/**
 * 1263. Minimum Moves to Move a Box to Their Target Location
 *
 * A storekeeper is a game in which the player pushes boxes around in a warehouse trying to get them to target locations.
 *
 * The game is represented by an m x n grid of characters grid where each element is a wall, floor, or box.
 *
 * Your task is to move the box 'B' to the target position 'T' under the following rules:
 *
 * The character 'S' represents the player. The player can move up, down, left, right in grid if it is a floor (empty cell).
 * The character '.' represents the floor which means a free cell to walk.
 * The character '#' represents the wall which means an obstacle (impossible to walk there).
 * There is only one box 'B' and one target cell 'T' in the grid.
 * The box can be moved to an adjacent free cell by standing next to the box and then moving in the direction of the box. This is a push.
 * The player cannot walk through the box.
 * Return the minimum number of pushes to move the box to the target. If there is no way to reach the target, return -1.
 */

class LC230508CN {
private:
	static inline constexpr std::int8_t dX[] = {0, 1, 0, -1};
	static inline constexpr std::int8_t dY[] = {1, 0, -1, 0};

public:
	static int minPushBox(const std::vector<std::vector<char>>&) noexcept;
};

template<typename T>
constexpr bool is_valid(T x, T y, T m, T n) {
	return (x >= 0) && (x < m) && (y >= 0) && (y < n);
}

int LC230508CN::minPushBox(const std::vector<std::vector<char>>& G) noexcept {
	using Status = std::tuple<int, std::int8_t, std::int8_t, std::int8_t, std::int8_t>;
	using Position = std::pair<std::int8_t, std::int8_t>;
	const std::int8_t m = G.size(), n = G.front().size();

	std::queue<Status> q;
	Position target, box_init, player;
	for (std::int8_t i = 0; i < m; ++i) {
		for (std::int8_t j = 0; j < n; ++j) {
			switch (G[i][j]) {
				case 'T':
					target = {i, j}; break;
				case 'B':
					box_init = {i, j}; break;
				case 'S':
					player = {i, j};
			}
		}
	}
	q.emplace(0, box_init.first, box_init.second, player.first, player.second);

	std::bitset<512> player_vis;
	std::bitset<262'144> box_vis;
	std::queue<Position> bfs_q;
	box_vis[box_init.first * m + box_init.second] = true;
	while (!q.empty()) {
		auto [step, cx, cy, px, py] = q.front();
		q.pop();

		player_vis.reset()[px * n + py] = true;
		bfs_q.emplace(px, py);
		while (!bfs_q.empty()) {
			auto [x, y] = bfs_q.front();
			bfs_q.pop();
			for (int i = 0; i < 4; ++i) {
				std::int8_t x_ = x + dX[i], y_ = y + dY[i];
				if ((x_ == cx && y_ == cy) || !is_valid(x_, y_, m, n) || G[x_][y_] == '#' || player_vis[x_ * n + y_])
					continue;
				player_vis[x_ * n + y_] = true;
				bfs_q.emplace(x_, y_);
			}
		}

		for (int i = 0; i < 4; ++i) {
			std::int8_t nx = cx + dX[i], ny = cy + dY[i], npx = cx - dX[i], npy = cy - dY[i];
			if (!is_valid(nx, ny, m, n) || !is_valid(npx, npy, m, n) || !player_vis[npx * n + npy] || G[nx][ny] == '#' || box_vis[nx * m * n * n + ny * m * n + npx * n + npy])
				continue;
			if (nx == target.first && ny == target.second)
				return step + 1;
			q.emplace(1 + step, nx, ny, cx, cy);
			box_vis[nx * m * n * n + ny * m * n + npx * n + npy] = true;
		}
	}
	return -1;
}

