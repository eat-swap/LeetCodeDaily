#include <cstdio>

template<int N>
struct AnswerGenerator {
	int answer[N + 1] {};
	constexpr AnswerGenerator() : answer() {
		answer[0] = answer[1] = 0;
		answer[2] = 1;
		for (int i = 3; i <= N; ++i) {
			answer[i] = (i & 1) ? ((i - 1) / 2 + answer[(i - 1) / 2 + 1]) : (i / 2 + answer[i / 2]);
		}
	}
};

class SolutionGen {
private:
	inline static constexpr AnswerGenerator<200> ans;
public:
	inline static constexpr int numberOfMatches(int n) {
		return ans.answer[n];
	}
};

/**
 * 1688. Count of Matches in Tournament
 * You are given an integer n, the number of teams in a tournament that has strange rules:
 * If the current number of teams is even, each team gets paired with another team. A total of n / 2 matches are played, and n / 2 teams advance to the next round.
 * If the current number of teams is odd, one team randomly advances in the tournament, and the rest gets paired. A total of (n - 1) / 2 matches are played, and (n - 1) / 2 + 1 teams advance to the next round.
 * Return the number of matches played in the tournament until a winner is decided.
 */

class Solution {
public:
	inline static constexpr int numberOfMatches(int n) {
		return n - 1;
	}
};

int main() {
	std::printf("%d -> %d\n", 7, SolutionGen::numberOfMatches(7));
	std::printf("%d -> %d\n", 14, SolutionGen::numberOfMatches(14));
}
