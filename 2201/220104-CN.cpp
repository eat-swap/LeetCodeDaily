#include <vector>
#include <cstring>
#include <cstdio>

#define LOCAL

/**
 * 913. Cat and Mouse
 * A game on an undirected graph is played by two players, Mouse and Cat, who alternate turns.
 *
 * The graph is given as follows: graph[a] is a list of all nodes b such that ab is an edge of the graph.
 *
 * The mouse starts at node 1 and goes first, the cat starts at node 2 and goes second, and there is a hole at node 0.
 *
 * During each player's turn, they must travel along one edge of the graph that meets where they are.  For example, if the Mouse is at node 1, it must travel to any node in graph[1].
 *
 * Additionally, it is not allowed for the Cat to travel to the Hole (node 0.)
 *
 * Then, the game can end in three ways:
 *
 * If ever the Cat occupies the same node as the Mouse, the Cat wins.
 * If ever the Mouse reaches the Hole, the Mouse wins.
 * If ever a position is repeated (i.e., the players are in the same position as a previous turn, and it is the same player's turn to move), the game is a draw.
 * Given a graph, and assuming both players play optimally, return
 *
 * 1 if the mouse wins the game,
 * 2 if the cat wins the game, or
 * 0 if the game is a draw.
 */

class Solution {
private:
	// dp[][][0]: previous moved is mouse, [1] cat.
	inline static int d[50][50][2];
public:
	static int catMouseGame(const std::vector<std::vector<int>>& graph) {
		std::memset(d, -1, sizeof d);
		const auto n = graph.size();
		for (int i = 1; i < 50; ++i) {
			// initial states
			d[i][i][0] = d[i][i][1] = 2;
			d[i][0][0] = d[i][0][1] = d[0][i][0] = d[0][i][1] = 1;
		}
		while (true) {
			int cnt = 0;

			// i <- position of cat
			for (int i = 0; i < n; ++i) {
				// j <- position of mouse
				for (int j = 0; j < n; ++j) {
					if (d[i][j][0] == -1) {
						/**
						 * Cat to move:
						 * Cat is very clever, if cat is possible to not be fail,
						 * he will not. And, if it can immediately make the mouse
						 * fail, it will.
						 */
						int& currentState = d[i][j][0];
						bool stateChanged = false;
						int failState = 0, totalState = 0;
						for (int k : graph[i]) {
							if (!k) continue;
							const int& previousState = d[k][j][1];
							++totalState;
							switch (previousState) {
								case 2: // Cat wins
								//	std::printf("(%d, %d, %d) <- Cat can immediately wins at (%d, %d, %d)\n", i, j, 0, k, j, 1);
									currentState = 2;
									stateChanged = true;
									break;
								case 1: // Mouse wins
									++failState;
								default: ; // ignored when uncertain
							}
						}
						// The cat can no longer wins
					//	std::printf("(%d, %d, %d) Cat <- failState %d / totalState %d\n", i, j, 0, failState, totalState);
						if (failState == totalState)
							stateChanged = (currentState = 1);
						cnt += stateChanged;
					}
					if (d[i][j][1] == -1) {
						/**
						 * Mouse to move:
						 * Mouse is very clever, if the mouse is possible to
						 * not be fail, it will not. And, if it can win
						 * immediately, it will!
						 */
						int& currentState = d[i][j][1];
						bool stateChanged = false;
						int failState = 0, totalState = 0;
						for (int k : graph[j]) {
							const int& previousState = d[i][k][0];
							++totalState;
							switch (previousState) {
								case 1: // Mouse wins
								//	std::printf("(%d, %d, %d) <- Mouse can immediately wins at (%d, %d, %d)\n", i, j, 1, i, k, 0);
									currentState = 1;
									stateChanged = true;
									break;
								case 2: // Cat wins
									++failState;
								default: ; // ignored when uncertain
							}
						}
						// The mouse can no longer wins
					//	std::printf("(%d, %d, %d) Mouse <- failState %d / totalState %d\n", i, j, 1, failState, totalState);
						if (failState == totalState)
							stateChanged = (currentState = 2);
						cnt += stateChanged;
					}
				}
			}
			if (!cnt) break;
		}
		switch (d[2][1][1]) {
			case 2:
				return 2;
			case 1:
				return 1;
			default:
				return 0;
		}
	}
};

int main() {
	// {{1, 3}, {0}, {3}, {0, 2}} -> 1
	// {{2, 5}, {3}, {0, 4, 5}, {1, 4, 5}, {2, 3}, {0, 2, 3}} -> 0
	// {{2, 3}, {3, 4}, {0, 4}, {0, 1}, {1, 2}} -> 1
	// {{3,4},{3,5},{3,6},{0,1,2},{0,5,6},{1,4},{2,4}} -> 0
	// {{4},{2,3,5},{1,5,3},{1,2},{0},{1,2}} -> 2
	// {{5,6},{3,4},{6},{1,4,5},{1,3,5},{0,3,4,6},{0,2,5}} -> 2

	std::printf("%d\n", Solution::catMouseGame({{1, 3}, {0}, {3}, {0, 2}}));

	std::printf("%d\n", Solution::catMouseGame({{2, 5},
												{3},
												{0, 4, 5},
												{1, 4, 5},
												{2, 3},
												{0, 2, 3}}));
	std::printf("%d\n", Solution::catMouseGame({{2, 3}, {3, 4}, {0, 4}, {0, 1}, {1, 2}}));
	std::printf("%d\n", Solution::catMouseGame({{3,4},{3,5},{3,6},{0,1,2},{0,5,6},{1,4},{2,4}}));

	std::printf("%d\n", Solution::catMouseGame({{4},{2,3,5},{1,5,3},{1,2},{0},{1,2}}));
	std::printf("%d\n", Solution::catMouseGame({{5,6},{3,4},{6},{1,4,5},{1,3,5},{0,3,4,6},{0,2,5}}));
	return 0;
}