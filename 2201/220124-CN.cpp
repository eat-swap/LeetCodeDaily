#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <chrono>
#include <format>
#include <cstring>

/**
 * 2045. Second Minimum Time to Reach Destination
 * A city is represented as a bi-directional connected graph with n vertices where each vertex is labeled from 1 to n (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself. The time taken to traverse any edge is time minutes.
 * Each vertex has a traffic signal which changes its color from green to red and vice versa every change minutes. All signals change at the same time. You can enter a vertex at any time, but can leave a vertex only when the signal is green. You cannot wait at a vertex if the signal is green.
 * The second minimum value is defined as the smallest value strictly larger than the minimum value.
 * For example the second minimum value of [2, 3, 4] is 3, and the second minimum value of [2, 2, 4] is 4.
 * Given n, edges, time, and change, return the second minimum time it will take to go from vertex 1 to vertex n.
 *
 * Notes:
 * You can go through any vertex any number of times, including 1 and n.
 * You can assume that when the journey starts, all signals have just turned green.
 *
 * Input: n = 5, edges = [[1,2],[1,3],[1,4],[3,4],[4,5]], time = 3, change = 5
 * Output: 13
 * Explanation:
 * The figure on the left shows the given graph.
 * The blue path in the figure on the right is the minimum time path.
 * The time taken is:
 * - Start at 1, time elapsed=0
 * - 1 -> 4: 3 minutes, time elapsed=3
 * - 4 -> 5: 3 minutes, time elapsed=6
 * Hence the minimum time needed is 6 minutes.
 *
 * The red path shows the path to get the second minimum time.
 * - Start at 1, time elapsed=0
 * - 1 -> 3: 3 minutes, time elapsed=3
 * - 3 -> 4: 3 minutes, time elapsed=6
 * - Wait at 4 for 4 minutes, time elapsed=10
 * - 4 -> 5: 3 minutes, time elapsed=13
 * Hence the second minimum time is 13 minutes.
 */

class Solution {
private:
	inline static constexpr int genLength(int len, int time, int change) {
		int ret = 0;
		for (int i = 0; i < len; ++i) {
			if ((ret / change) & 1) {
				ret = (ret / change + 1) * change;
			}
			ret += time;
		}
		return ret;
	}
public:
	static int secondMinimum(int n, const std::vector<std::vector<int>>& edges, int time, int change) {
		std::vector<int> G[10002];
		for (const auto& i : edges) {
			G[i[0]].push_back(i[1]);
			G[i[1]].push_back(i[0]);
		}

		int minLength = 0x7FFFFFFD, hasP1 = 0, cnt = 0;
		int vis[10002] {}; // vis[x]: minimal length to node x.
		std::memset(vis, 0x7F, sizeof vis);
		std::queue<int> q;
		q.push(1); // Node #
		q.push(0); // current len
		while (!q.empty()) {
			++cnt;
			int node = q.front();
			q.pop();
			int currentLength = q.front();
			q.pop();
			if (currentLength >= minLength + 2)
				break;
			if (node == n) {
				minLength = std::min(currentLength, minLength);
				if (minLength < currentLength) {
					hasP1 = 1;
					break;
				}
			}
			for (const auto& i : G[node]) {
				if (currentLength <= vis[i]) {
					vis[i] = std::min(1 + currentLength, vis[i]);
					q.push(i);
					q.push(1 + currentLength);
				}
			}
		}
		// std::cout << "minLength = " << minLength << ", hasP1 = " << hasP1 << std::endl;
		return genLength(minLength + (hasP1 ? 1 : 2), time, change);
	}
};

int main() {
	// Solution::secondMinimum(2, {{1, 2}}, 3, 2)
	// Solution::secondMinimum(5, {{1, 2}, {1, 3}, {1, 4}, {3, 4}, {4, 5}}, 3, 5);
	// Solution::secondMinimum(6, {{1, 2}, {1, 3}, {2, 4}, {3, 5}, {5, 4}, {4, 6}}, 3, 100);
	std::vector<std::vector<int>> arg;
	for (int i = 1; i < 10000; ++i) {
		arg.push_back({i, i + 1});
	}
	arg.push_back({100, 102});
	arg.push_back({102, 110});
	auto start = std::chrono::high_resolution_clock::now();
	auto ans = Solution::secondMinimum(10000, arg, 1000, 1000);
	auto end = std::chrono::high_resolution_clock::now();
	std::cout << ans << std::endl;
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms\n";
	return 0;
}
