#include <vector>
#include <queue>
#include <iostream>

// This is wrong.
// It has nothing to do with Dijkstra.
class SolutionWrong {
public:
	static int minimumEffortPath(const std::vector<std::vector<int>>& heights) {
		const std::size_t m = heights.size(), n = heights.front().size(), total = m * n;

		std::vector<int> d(total, 0x7FFFFFFF);
		std::vector<std::vector<int>> G(total);
		std::vector<bool> vis(total);
		for (int i = 0; i < m * n; ++i) {
			// Build graph
			if (i + n < total) {
				// Down
				G[i].push_back(i + n);
				G[i + n].push_back(i);
			}
			if ((i + 1) % n) {
				// Right
				G[i].push_back(i + 1);
				G[i + 1].push_back(i);
			}
		}

		// Pair <Dist, Node#>
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
		q.push({0, 0});
		d[0] = 0;

		// Dijkstra
		while (!q.empty()) {
			const auto [dist, idx] = q.top();
			q.pop();

			if (vis[idx])
				continue;
			vis[idx] = true;

			for (int idxNext : G[idx]) {
				int length = std::abs(heights[idx / n][idx % n] - heights[idxNext / n][idxNext % n]);
				if (d[idxNext] > d[idx] + length) {
					d[idxNext] = d[idx] + length;
					q.push({d[idxNext], idxNext});
				}
			}
		}

		return d[total - 1];
	}
};

/**
 * 1631. Path With Minimum Effort
 * You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.
 * A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
 * Return the minimum effort required to travel from the top-left cell to the bottom-right cell.
 *
 * I was wrong again, it IS Dijkstra, but with some modification.
 * d[idx] + length --> std::max(d[idx], length)
 */

class Solution {
public:
	static int minimumEffortPath(const std::vector<std::vector<int>>& heights) {
		const std::size_t m = heights.size(), n = heights.front().size(), total = m * n;

		std::vector<int> d(total, 0x7FFFFFFF);
		std::vector<std::vector<int>> G(total);
		std::vector<bool> vis(total);
		for (int i = 0; i < m * n; ++i) {
			// Build graph
			if (i + n < total) {
				// Down
				G[i].push_back(i + n);
				G[i + n].push_back(i);
			}
			if ((i + 1) % n) {
				// Right
				G[i].push_back(i + 1);
				G[i + 1].push_back(i);
			}
		}

		// Pair <Dist, Node#>
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
		q.push({0, 0});
		d[0] = 0;

		// Dijkstra
		while (!q.empty()) {
			const auto [dist, idx] = q.top();
			q.pop();

			if (vis[idx])
				continue;
			vis[idx] = true;

			for (int idxNext : G[idx]) {
				int length = std::abs(heights[idx / n][idx % n] - heights[idxNext / n][idxNext % n]);
				if (d[idxNext] > std::max(d[idx], length)) {
					d[idxNext] = std::max(d[idx], length);
					q.push({d[idxNext], idxNext});
				}
			}
		}

		return d[total - 1];
	}
};

int main() {
	std::vector<std::vector<int>> args {
		{1, 2, 2},
		{3, 8, 2},
		{5, 3, 5}
	};
	std::cout << Solution::minimumEffortPath(args) << std::endl;
}
