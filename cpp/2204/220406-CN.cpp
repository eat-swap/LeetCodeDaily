#include <vector>
#include <queue>
#include <cstring>

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
