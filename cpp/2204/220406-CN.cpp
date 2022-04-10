#include <vector>
#include <queue>
#include <cstring>

/**
 * 310. Minimum Height Trees
 * A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.
 * Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).
 * Return a list of all MHTs' root labels. You can return the answer in any order.
 * The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
 */

class Solution {
public:
	static std::vector<int> findMinHeightTrees(int n, const std::vector<std::vector<int>>& edges) {
		if (n == 1)
			return {0};
		int degrees[n], ans[n];
		std::vector<int> G[n];
		std::memset(degrees, 0, sizeof degrees);
		std::memset(ans, 0, sizeof ans);
		for (const auto& e : edges) {
			G[e[0]].push_back(e[1]);
			G[e[1]].push_back(e[0]);
			++degrees[e[0]];
			++degrees[e[1]];
		}

		int x, y, distXY;
		int father[n];
		{
			int dist[n];
			bool vis[n];
			std::queue<int> q;

			auto doBFS = [&](int startNode) {
				q.push(startNode);
				q.push(0);
				std::memset(vis, 0, sizeof vis);
				std::memset(father, 0, sizeof father);
				vis[startNode] = true;
				while (!q.empty()) {
					int idx = q.front();
					q.pop();
					int len = q.front();
					q.pop();
					dist[idx] = len;
					for (int nextId : G[idx]) {
						if (vis[nextId])
							continue;
						vis[nextId] = true;
						father[nextId] = idx;
						q.push(nextId);
						q.push(len + 1);
					}
				}
			};

			// From 0, find the max distance
			doBFS(0);
			x = std::max_element(dist, dist + n) - dist;

			// From x, find the max distance
			doBFS(x);
			auto* maxDistPtr = std::max_element(dist, dist + n);
			y = maxDistPtr - dist;
			distXY = *maxDistPtr;
		}

		std::vector<int> ret;
		int ptr = y;
		for (int i = 0; i < distXY / 2; ++i)
			ptr = father[ptr];
		ret.push_back(ptr);
		if (distXY & 1)
			ret.push_back(father[ptr]);
		return ret;
	}
};

int main() {
	auto ret = Solution::findMinHeightTrees(2, {{0, 1}});
	return 0;
}
