#include <vector>
#include <iostream>

/**
 * 1007. Minimum Domino Rotations For Equal Row
 * In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino. (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)
 * We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.
 * Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.
 * If it cannot be done, return -1.
 */

class Solution {
public:
	static int minDominoRotations(const std::vector<int>& tops, const std::vector<int>& bottoms) {
		int n = tops.size();
		int cnt[7]{}, cntTop[7]{}, cntBottom[7]{};
		for (int i = 0; i < n; ++i) {
			++cnt[tops[i]];
			++cntTop[tops[i]];
			++cntBottom[bottoms[i]];
			if (tops[i] != bottoms[i])
				++cnt[bottoms[i]];
		}

		int ret = 0x7FFFFFFF;
		for (int i = 1; i <= 6; ++i)
			if (cnt[i] >= n)
				ret = std::min(ret, int(n - std::max(cntTop[i], cntBottom[i])));

		return ret == 0x7FFFFFFF ? -1 : ret;
	}
};

int main() {
	std::cout << Solution::minDominoRotations({2,1,2,4,2,2}, {5,2,6,2,3,2}) << "\n";
	std::cout << Solution::minDominoRotations({3,5,1,2,3}, {3,6,3,3,4}) << "\n";
	return 0;
}
