#include <vector>
#include <cstring>
#include <cstdio>

// #define LOCAL

class Solution {
private:
	inline static int d[50][50];
	inline static bool vis[50][50];
	static int dp(int cat, int mouse, const std::vector<std::vector<int>>& graph, bool isCatMove
#ifdef LOCAL
				  , int depth = 0
#endif
		) {
		if (d[cat][mouse] != -1) {
#ifdef LOCAL
			for (int i = 0; i < depth; i++, std::printf("  "));
			std::printf("(%d, %d) is calculated before, returning %d.\n", cat, mouse, d[cat][mouse]);
			std::fflush(stdout);
#endif
			return d[cat][mouse];
		}
		if (vis[cat][mouse]) {
#ifdef LOCAL
			for (int i = 0; i < depth; i++, std::printf("  "));
			std::printf("(%d, %d) is trapped in a loop state, returning 0.\n", cat, mouse);
			std::fflush(stdout);
#endif
			return 0;
		}
		if (mouse == 0) {
#ifdef LOCAL
			for (int i = 0; i < depth; i++, std::printf("  "));
			std::printf("(%d, %d) is won by the mouse, returning 1.\n", cat, mouse);
			std::fflush(stdout);
#endif
			return 1;
		}
		if (cat == mouse) {
#ifdef LOCAL
			for (int i = 0; i < depth; i++, std::printf("  "));
			std::printf("(%d, %d) is won by the cat, returning 2.\n", cat, mouse);
			std::fflush(stdout);
#endif
			return 2;
		}
		vis[cat][mouse] = true;
		int ans, r, hasNext = 0;
		int results[3]{};
		if (isCatMove) { // Next is mouse to move
			for (const int& catNext : graph[cat]) {
				if (catNext == 0) continue;
#ifdef LOCAL
				for (int i = 0; i < depth; i++, std::printf("  "));
				std::printf("(%d, %d) [Cat] -> Iterating into (%d, %d)\n", cat, mouse, catNext, mouse);
				std::fflush(stdout);
#endif
				r = dp(catNext, mouse, graph, false
#ifdef LOCAL
							, 1 + depth
#endif
							);

				++results[r];
			}
			if (results[2]) {
				ans = 2;
			} else if (results[0]) {
				ans = 0;
			} else {
				ans = 1;
			}
		} else { // Next is cat
			for (const int& mouseNext : graph[mouse]) {
				if (mouseNext == cat) continue;
#ifdef LOCAL
				for (int i = 0; i < depth; i++, std::printf("  "));
				std::printf("(%d, %d) [Mouse] -> Iterating into (%d, %d)\n", cat, mouse, cat, mouseNext);
				std::fflush(stdout);
#endif
				r = dp(cat, mouseNext, graph, true
#ifdef LOCAL
							, 1 + depth
#endif
							);
				++results[r];
				hasNext += (r != 0);
			}
			if (!hasNext) {
				ans = 2;
			} else if (results[1]) {
				ans = 1;
			} else if (results[0]) {
				ans = 0;
			} else {
				ans = 2;
			}
		}
		vis[cat][mouse] = false;
#ifdef LOCAL
		for (int i = 0; i < depth; i++, std::printf("  "));
		std::printf("(%d, %d) [Next move %s] is returning %d.\n", cat, mouse, isCatMove ? "cat" : "mouse", ans);
		std::fflush(stdout);
#endif
		return d[cat][mouse] = ans;
	}
public:
	static int catMouseGame(const std::vector<std::vector<int>>& graph) {
		std::memset(d, -1, sizeof d);
		std::memset(vis, 0, sizeof vis);
		return dp(2, 1, graph, false);
	}
};

int main() {
	// {{1, 3}, {0}, {3}, {0, 2}} -> 1
	// {{2, 5}, {3}, {0, 4, 5}, {1, 4, 5}, {2, 3}, {0, 2, 3}} -> 0
	// {{2, 3}, {3, 4}, {0, 4}, {0, 1}, {1, 2}} -> 1
	// {{3,4},{3,5},{3,6},{0,1,2},{0,5,6},{1,4},{2,4}} -> 0
	// {{4},{2,3,5},{1,5,3},{1,2},{0},{1,2}} -> 2

	std::printf("%d\n", Solution::catMouseGame({{1, 3}, {0}, {3}, {0, 2}}));
	std::printf("%d\n", Solution::catMouseGame({{2, 5}, {3}, {0, 4, 5}, {1, 4, 5}, {2, 3}, {0, 2, 3}}));
	std::printf("%d\n", Solution::catMouseGame({{2, 3}, {3, 4}, {0, 4}, {0, 1}, {1, 2}}));
	std::printf("%d\n", Solution::catMouseGame({{3,4},{3,5},{3,6},{0,1,2},{0,5,6},{1,4},{2,4}}));

	std::printf("%d\n", Solution::catMouseGame({{4},{2,3,5},{1,5,3},{1,2},{0},{1,2}}));
	return 0;
}