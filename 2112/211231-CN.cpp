#include <iostream>
#include <cmath>

class Solution {
public:
	static bool checkPerfectNumber(int num) {
		switch (num) {
			case 6:
			case 28:
			case 496:
			case 8128:
			case 33550336:
				return true;
			default:
				return false;
		}
	}
};

int main() {
	for (int i = 1; i < 100000000; ++i) {
		int s = 1;
		int lim = int(std::sqrt(i + 0.50));
		for (int j = 2; j <= lim; ++j)
			if (i % j == 0)
				s += j + i / j;
		if (s == i)
			std::printf("%d\n", i);
	}
	return 0;
}

/**
 * Use this golang program to do multi-threaded searching:
 * Refer to 211231-CN-BruteForce.go
 */