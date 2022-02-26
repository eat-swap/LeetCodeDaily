#include <queue>
#include <vector>
#include <cstring>
#include <iostream>
#include <functional>

/**
 * 847. Shortest Path Visiting All Nodes
 * You have an undirected, connected graph of n nodes labeled from 0 to n - 1. You are given an array graph where graph[i] is a list of all the nodes connected with node i by an edge.
 * Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.
 */

class Solution {
private:
	static void bfs(const std::vector<std::vector<int>>& G, int begin, int* ret) {
		int n = G.size();

		// Insert: (node#, length)
		std::queue<int> q;
		bool* const vis = new bool[n]{};
		q.push(begin);
		q.push(0);
		vis[begin] = true;

		while (!q.empty()) {
			int idx = q.front();
			q.pop();
			int len = q.front();
			q.pop();

			ret[idx] = len;

			for (int i : G[idx]) {
				if (!vis[i]) {
					q.push(i);
					q.push(1 + len);
					vis[i] = true;
				}
			}
		}

		delete[] vis;
	}

	static inline constexpr int bitSetAdd(int set, int id) {
		return set | (1 << id);
	}

	static inline constexpr int bitSetRemove(int set, int id) {
		return set & (~(1 << id));
	}

public:
	static int shortestPathLength(const std::vector<std::vector<int>>& graph) {
		int n = graph.size();
		int lens[n][n];
		for (int i = 0; i < n; ++i) {
			bfs(graph, i, lens[i]);
		}

		// dp: let dp[visitedSet][node] be the remaining length to
		// reach the all-node-visited state.
		// dp[(1 << n) - 1][x] always be 0;
		int dp[1 << n][n];
		std::memset(dp, -1, sizeof dp);
		std::memset(dp[(1 << n) - 1], 0, sizeof dp[(1 << n) - 1]);

		// visited includes node.
		std::function<int(int, int)> calc;
		calc = [&](int visited, int node) {
			if (dp[visited][node] != -1)
				return dp[visited][node];

			int& now = dp[visited][node];
			now = 0x7FFFFFFF;
			// Try goes to next node
			for (int i = 0; i < n; ++i) {
				if (!(visited & (1 << i))) {
					// This node not visited, goes to it
					// directly regardless of nodes not
					// visited along the way
					now = std::min(now, lens[node][i] + calc(bitSetAdd(visited, i), i));
				}
			}

			return now;
		};

		int ret = 0x7FFFFFFF;
		for (int i = 0; i < n; ++i) {
			ret = std::min(ret, calc(bitSetAdd(0, i), i));
		}

		return ret;
	}
};

int main() {
	std::cout << Solution::shortestPathLength({{1},{0,2,4},{1,3,4},{2},{1,2}});
	return 0;
}
