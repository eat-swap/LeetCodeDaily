#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>

/**
 * 399. Evaluate Division
 * You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.
 * You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.
 * Return the answers to all queries. If a single answer cannot be determined, return -1.0.
 */

class Solution {
public:
	static std::vector<double> calcEquation(const std::vector<std::vector<std::string>>& equations, const std::vector<double>& values, const std::vector<std::vector<std::string>>& queries) {
		int nodeCnt = 0;
		std::unordered_map<std::string, int> strId;

		// Give strings IDs
		const int n = equations.size();
		for (int i = 0; i < n; ++i) {
			// Place them into map, if not present
			if (!strId.count(equations[i][0]))
				strId[equations[i][0]] = nodeCnt++;
			if (!strId.count(equations[i][1]))
				strId[equations[i][1]] = nodeCnt++;
		}

		std::vector<std::unordered_map<int, double>> G(nodeCnt);
		// Process equations
		for (int i = 0; i < n; ++i) {
			const int fId = strId[equations[i][0]], tId = strId[equations[i][1]];
			const double val = values[i];
			G[tId][fId] = 1.0 / (G[fId][tId] = val);
		}

		auto getVal = [&](int fromId, int toId) {
			std::queue<std::pair<int, double>> q;

			q.push({fromId, 1.0});
			std::vector<bool> vis(nodeCnt);
			vis[fromId] = true;
			while (!q.empty()) {
				const auto [node, val] = q.front();
				q.pop();

				for (const auto& [t, v] : G[node]) {
					auto nextVal = val * v;
					if (t == toId)
						return nextVal;
					if (vis[t])
						continue;
					vis[t] = true;

					// Cache edge for future use
					G[fromId][t] = nextVal;
					G[t][fromId] = 1.0 / nextVal;

					// Push into BFS queue
					q.push({t, nextVal});
				}
			}

			// Not found everywhere
			return -1.0;
		};

		std::vector<double> ret;
		// Process queries
		// current ID, current val
		for (const auto& query : queries) {
			const auto& from = query[0];
			const auto& to = query[1];

			if (!strId.count(from) || !strId.count(to))
				ret.push_back(-1.0);
			else if (from == to)
				ret.push_back(1.0);
			else
				ret.push_back(getVal(strId[from], strId[to]));
		}
		return ret;
	}
};

int main() {
	auto ans = Solution::calcEquation({{"a","b"},{"b","c"},{"bc","cd"}}, {1.5,2.5,5.0}, {{"a","c"},{"c","b"},{"bc","cd"},{"cd","bc"}});
	for (auto x : ans)
		std::cout << x << std::endl;
	return 0;
}
