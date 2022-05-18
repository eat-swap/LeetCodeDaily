#include <vector>
#include <functional>

class Solution {
public:
	static std::vector<std::vector<int>> criticalConnections(int n, const std::vector<std::vector<int>>& e) {
		auto* G = new std::vector<int>[n];
		for (const std::vector<int>& i : e) {
			G[i[0]].push_back(i[1]);
			G[i[1]].push_back(i[0]);
		}

		std::vector<int> preTS(n);
		int dfsTS = 0;
		std::vector<std::vector<int>> ret;
		std::function<int(int, int)> dfs = [&](int u, int prevE) {
			int low_u = preTS[u] = ++dfsTS;

			int chCnt = 0;
			for (int v : G[u]) {
				if (v == prevE)
					continue;
				if (preTS[v] && preTS[v] < preTS[u]) {
					low_u = std::min(low_u, preTS[v]);
				} else if (!preTS[v]) {
					++chCnt;
					int low_v = dfs(v, u);
					low_u = std::min(low_u, low_v);
					if (low_v > preTS[u]) {
						// u is an articulation vertex
						// (u, v) is a bridge
						ret.push_back({u, v});
					}
				}
			}
			return low_u;
		};
		dfs(0, -1);

		delete[] G;
		return ret;
	}
};

int main() {
	auto r = Solution::criticalConnections(5, {{1,0},{2,0},{3,2},{4,2},{4,3},{3,0},{4,0}});

	return 0;
}
