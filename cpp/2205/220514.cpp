#include <vector>
#include <tuple>
#include <queue>
#include <iostream>

/**
 * 743. Network Delay Time
 * You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.
 * We will send a signal from a given node k. Return the time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.
 *
 * Comment: This is Dijkstra's algorithm.
 */

class Solution {
public:
	static int networkDelayTime(const std::vector<std::vector<int>>& times, int n, int k) {
		const int edgeCnt = times.size();
		std::vector<std::tuple<int, int, int>> edges;
		std::vector<std::vector<int>> G(n);
		edges.reserve(edgeCnt);
		for (int i = 0; i < edgeCnt; ++i) {
			edges.emplace_back(times[i][0] - 1, times[i][1] - 1, times[i][2]);
			G[times[i][0] - 1].push_back(i);
		}

		std::vector<int> dist(n, 0x6FFFFFFF);
		std::vector<bool> vis(n);
		--k;

		// pair<dist, idx>
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
		q.push({0, k});
		dist[k] = 0;
		while (!q.empty()) {
			const auto [len, node] = q.top();
			q.pop();

			if (vis[node])
				continue;
			vis[node] = true;

			for (int eId : G[node]) {
				const auto [f, t, d] = edges[eId];
				if (dist[t] <= dist[node] + d)
					continue;
				dist[t] = dist[node] + d;
				q.push({dist[t], t});
			}
		}

		int ret = *std::max_element(dist.begin(), dist.end());
		return ret == 0x6FFFFFFF ? -1 : ret;
	}
};

int main() {
	std::cout << Solution::networkDelayTime({{2,1,1},{2,3,1},{3,4,1}}, 4, 2);
	return 0;
}
