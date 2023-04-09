#include <string>
#include <vector>
#include <functional>
#include <iostream>

struct Info {
	int cnt[26]{};
	bool has_value = false;
	bool is_bad = false;
	bool in_loop = false;

	Info& operator&=(const Info& rhs) {
		for (int i = 0; i < 26; ++i)
			this->cnt[i] = std::max(this->cnt[i], rhs.cnt[i]);
		return *this;
	}

	int get() const {
		int ret = cnt[0];
		for (int i = 1; i < 26; ++i)
			ret = std::max(ret, cnt[i]);
		return ret;
	}

};

/**
 * 1857. Largest Color Value in a Directed Graph
 *
 * There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.
 * You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.
 * A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.
 * Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.
 */

class Solution {
public:
	static int largestPathValue(const std::string&, const std::vector<std::vector<int>>&);
};

int Solution::largestPathValue(const std::string& colors, const std::vector<std::vector<int>>& edges) {
	const int m = edges.size(), n = colors.length();
	std::vector<std::vector<int>> G(n);
	for (auto&& e : edges)
		G[e[0]].push_back(e[1]);
	std::vector<Info> dp(n);
	std::function<const Info&(int)> d = [&](int idx) -> const Info& {
		auto& ans = dp[idx];
		if (ans.has_value)
			return ans;
		if (ans.in_loop) {
			ans.is_bad = true;
			return ans;
		} else if (G[idx].empty()) {
			ans.cnt[colors[idx] - 'a'] = 1;
			ans.has_value = true;
			return ans;
		}
		ans.in_loop = true;
		for (int nx : G[idx]) {
			const auto& nxd = d(nx);
			if (nxd.is_bad) {
				ans.is_bad = true;
				return ans;
			}
			ans &= nxd;
		}
		++ans.cnt[colors[idx] - 'a'];
		ans.has_value = true;
		ans.in_loop = false;
		return ans;
	};
	int ans = -1;
	for (int i = 0; i < n; ++i) {
		const auto& c = d(i);
		if (c.is_bad)
			return -1;
		ans = std::max(ans, c.get());
	}
	return ans;
}

int main() {
	std::cout << Solution::largestPathValue("hhqhuqhqff", {
		{0,1},{0,2},{2,3},{3,4},{3,5},{5,6},{2,7},{6,7},{7,8},{3,8},{5,8},{8,9},{3,9},{6,9}
	});
	return 0;
}
