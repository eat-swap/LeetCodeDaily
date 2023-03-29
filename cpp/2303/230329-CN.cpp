#include <iostream>

class SolutionCalc {
private:
	static constexpr inline int CI(int n, int x) {
		if (n <= 1)
			return 1;
		int ret = 0;
		for (int i = 1; i <= x; ++i)
			ret += CI(n - 1, i);
		return ret;
	}

public:
	static constexpr inline int countVowelStrings(int n) {
		return CI(n, 1) + CI(n, 2) + CI(n, 3) + CI(n, 4) + CI(n, 5);
	}
};

class Solution {
private:
	static constexpr inline int ANS[] = {
		5, 15, 35, 70, 126, 210, 330, 495, 715, 1001, 1365, 1820, 2380, 3060, 3876, 4845, 5985, 7315, 8855, 10626, 12650, 14950,
		17550, 20475, 23751, 27405, 31465, 35960, 40920, 46376, 52360, 58905, 66045, 73815, 82251, 91390, 101270, 111930, 123410, 135751,
		148995, 163185, 178365, 194580, 211876, 230300, 249900, 270725, 292825, 316251,
	};

public:
	static constexpr inline int countVowelStrings(int n) {
		return ANS[n - 1];
	}
};


int main() {
	for (int i = 1; i <= 50; ++i)
		std::cout << SolutionCalc::countVowelStrings(i) << ", ";
	return 0;
}
