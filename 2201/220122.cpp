#include <cstdio>
#include <cstdint>

// Clang does not accept this constexpr Solver, but MSVC does.
template<int N>
struct Solver {
	int bobs[3000];
	int endPosition;
	constexpr Solver() : bobs() {
		int dp[N + 5][2]{{-1, 1}};
		auto f = [&dp](int n, int who, auto&& fr) {
			if (dp[n][who])
				return dp[n][who];
			for (int i = 1; i * i <= n; ++i) {
				if (fr(n - i * i, who ^ 1, fr) == (who ? -1 : 1))
					return dp[n][who] = (who ? -1 : 1);
			}
			return dp[n][who] = (who ? 1 : -1);
		};
		int pos = 0;
		for (int i = 0; i < N + 3; ++i) {
			if (f(i, 0, f) == -1){
				bobs[pos++] = i;
			}
		}
		endPosition = pos;
	}
};

/**
 * 1510. Stone Game IV
 * Alice and Bob take turns playing a game, with Alice starting first.
 * Initially, there are n stones in a pile. On each player's turn, that player makes a move consisting of removing any non-zero square number of stones in the pile.
 * Also, if a player cannot make a move, he/she loses the game.
 * Given a positive integer n, return true if and only if Alice wins the game otherwise return false, assuming both players play optimally.
 */

class Solution {
private:
	static constexpr Solver<100005> answer;
public:
	static bool winnerSquareGame(int n) {
		for (int i = 0; i < answer.endPosition; ++i) {
			if (answer.bobs[i] == n) {
				return false;
			}
		}
		return true;
	}
};

class SolutionOld {
private:
	// 0 -> Unknown, 1 -> Alice, -1 -> Bob
	// dp[n][0] -> Alice to take, [1] -> Bob to take;
	int8_t dp[100005][2]{{-1, 1}};
	int8_t d(int n, int8_t who) {
		if (dp[n][who])
			return dp[n][who];
		for (int i = 1; i * i <= n; ++i) {
			if (d(n - i * i, who ^ 1) == (who ? -1 : 1))
				return dp[n][who] = (who ? -1 : 1);
		}
		return dp[n][who] = (who ? 1 : -1);
	}
public:
	bool winnerSquareGame(int n) {
		return d(n, 0) == 1;
	}
};

int main() {
	SolutionOld solver;
	std::printf("%s\n", Solution::winnerSquareGame(4) ? "true" : "false");
	return 0;
}