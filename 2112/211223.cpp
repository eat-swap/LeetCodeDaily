#include <vector>
#include <cstdio>

class Solution {
private:
	inline static std::vector<int>* G = nullptr;
	inline static std::vector<int> ret{};
	inline static int n;
	inline static bool* vis = nullptr;
public:
	static std::vector<int> findOrder(int numCourses, const std::vector<std::vector<int>>& prerequisites) {
		ret.clear();
		G = new std::vector<int>[n = numCourses]{};
		vis = new bool[n]{};
		for (const auto& e : prerequisites) {
			G[e[0]].push_back(e[1]);
		}
		for (int i = 0; i < numCourses; ++i) {
			if (!dfs(i, nullptr)) {
				delete[] vis;
				delete[] G;
				return std::vector<int>{};
			}
		}
		delete[] vis;
		delete[] G;
		return ret;
	}

private:
	static bool dfs(const int node, bool* const loop) {
		if (loop && loop[node])
			return false;
		if (vis[node])
			return true;
		bool* const thisLoop = loop ? loop : new bool[n]{};
		thisLoop[node] = true;
		for (const auto& i : G[node]) {
			if (!dfs(i, thisLoop)) {
				if (!loop)
					delete[] thisLoop;
				return false;
			}
		}
		thisLoop[node] = false;
		if (!loop)
			delete[] thisLoop;
		if (!vis[node])
			ret.push_back(node);
		return vis[node] = true;
	}
};

int main() {
	std::vector<std::vector<int>> s {
			{1, 0},
			{0, 1}
	};
	const auto ret = Solution::findOrder(2, s);
	for (const auto& i : ret) {
		std::printf("%d ", i);
	}
	return 0;
}