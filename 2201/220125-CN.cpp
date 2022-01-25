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
