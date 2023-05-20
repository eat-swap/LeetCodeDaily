#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

/**
 * 399. Evaluate Division
 * You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.
 * You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.
 * Return the answers to all queries. If a single answer cannot be determined, return -1.0.
 */

class LC230520 {
public:
	template<typename T>
	using V = std::vector<T>;
	using VD = V<double>;
	using CVVS = const V<V<std::string>>;

	static VD calcEquation(CVVS&, const VD&, CVVS&) noexcept;
};

std::vector<double> LC230520::calcEquation(CVVS& equations, const VD& values, CVVS& queries) noexcept {
	const int n = equations.size();
	std::unordered_map<std::string, int> id_map;
	std::unordered_map<int, std::unordered_map<int, double>> directed_map;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 2; ++j)
			if (!id_map.count(equations[i][j]))
				id_map[equations[i][j]] = cnt++;
		directed_map[id_map[equations[i][0]]][id_map[equations[i][1]]] = values[i];
		directed_map[id_map[equations[i][1]]][id_map[equations[i][0]]] = 1.0 / values[i];
	}
	VD ret;
	for (auto&& t : queries) {
		if (!(id_map.count(t[0]) && id_map.count(t[1]))) {
			ret.push_back(-1.0);
			continue;
		}
		int numerator = id_map[t[0]], denominator = id_map[t[1]];
		if (numerator == denominator) {
			ret.push_back(1.0);
			continue;
		}
		int vis = 1 << numerator;
		bool found = false;
		std::queue<std::pair<int, double>> q;
		q.emplace(numerator, 1.0);
		while (!q.empty()) {
			auto [c, cr] = q.front();
			for (auto [nc, ncr] : directed_map[c]) {
				if (vis & (1 << nc))
					continue;
				vis |= 1 << nc;
				if (nc == denominator) {
					found = true;
					ret.push_back(cr * ncr);
					break;
				}
				q.emplace(nc, cr * ncr);
			}
			if (found)
				break;
		}
		if (!found)
			ret.push_back(-1);
	}
	return ret;
}
