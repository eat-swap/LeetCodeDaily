#include <vector>
#include <queue>

/**
 * 785. Is Graph Bipartite?
 * There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:
 * There are no self-edges (graph[u] does not contain u).
 * There are no parallel edges (graph[u] does not contain duplicate values).
 * If v is in graph[u], then u is in graph[v] (the graph is undirected).
 * The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
 * A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.
 * Return true if and only if it is bipartite.
 */

class Solution {
public:
	static bool isBipartite(const std::vector<std::vector<int>>& G) {
		const int n = G.size();
		std::vector<uint8_t> colour(n);
		std::vector<bool> vis(n);
		std::queue<int> q;

		for (int i = 0; i < n; ++i) {
			if (vis[i])
				continue;
			q.push(i);
			colour[i] = 1;
			vis[i] = true;
			while (!q.empty()) {
				auto idx = q.front();
				q.pop();
				auto nextColour = colour[idx] ^ 3;
				for (int idxNext : G[idx]) {
					if (vis[idxNext]) {
						if (colour[idxNext] != nextColour)
							return false;
						continue;
					}
					vis[idxNext] = true;
					colour[idxNext] = nextColour;
					q.push(idxNext);
				}
			}
		}
		return true;
	}
};
