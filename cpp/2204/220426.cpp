#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>

class DisjointSet {
private:
	std::vector<int> parent;

public:
	explicit DisjointSet(int n) {
		parent.reserve(n);
		for (int i = 0; i < n; ++i)
			parent.push_back(i);
	}

	int Find(int x) {
		return (parent[x] == x) ? x : (parent[x] = Find(parent[x]));
	}

	void Union(int x, int y) {
		auto xR = Find(x), yR = Find(y);
		if (xR != yR)
			parent[xR] = yR;
	}

};

struct TupleCmp {
	bool operator()(const std::tuple<int, int, int>& x, const std::tuple<int, int, int>& y) const {
		return std::get<2>(x) > std::get<2>(y);
	}
};

/**
 * 1584. Min Cost to Connect All Points
 * You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].
 * The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.
 * Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.
 */

class Solution {
public:
	static int minCostConnectPoints(std::vector<std::vector<int>>& points) {
		int n = points.size();
		if (n <= 1)
			return 0;

		std::vector<std::tuple<int, int, int>> edgePairs;
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				edgePairs.emplace_back(i, j, std::abs(points[i][0] - points[j][0]) + std::abs(points[i][1] - points[j][1]));

		std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, TupleCmp> q(edgePairs.begin(), edgePairs.end());
		DisjointSet s(n);

		int ans = 0, cnt = 0;
		while (cnt < n - 1) {
			auto cur = q.top();
			q.pop();
			auto i = std::get<0>(cur);
			auto j = std::get<1>(cur);
			if (s.Find(i) != s.Find(j)) {
				s.Union(i, j);
				ans += std::get<2>(cur);
				++cnt;
			}
		}

		return ans;
	}
};
