#include <vector>
#include <random>
#include <ctime>
#include <algorithm>

/**
 * 497. Random Point in Non-overlapping Rectangles
 *
 * You are given an array of non-overlapping axis-aligned rectangles rects where rects[i] = [ai, bi, xi, yi] indicates that (ai, bi) is the bottom-left corner point of the ith rectangle and (xi, yi) is the top-right corner point of the ith rectangle. Design an algorithm to pick a random integer point inside the space covered by one of the given rectangles. A point on the perimeter of a rectangle is included in the space covered by the rectangle.
 * Any integer point inside the space covered by one of the given rectangles should be equally likely to be returned.
 * Note that an integer point is a point that has integer coordinates.
 * Implement the Solution class:
 * Solution(int[][] rects) Initializes the object with the given rectangles rects.
 * int[] pick() Returns a random integer point [u, v] inside the space covered by one of the given rectangles.
 */

class Solution {
private:
	std::vector<std::vector<int>> r;

	std::vector<int> pSum;

	int total;

	std::mt19937 rnd;

	int randIntN(int n) {
		return rnd() % n;
	}

public:
	explicit Solution(std::vector<std::vector<int>> rects) {
		r = std::move(rects);
		rnd = std::mt19937(std::time(nullptr));
		pSum = std::vector<int>(r.size());
		for (int i = 1; i < r.size(); ++i) {
			const auto& x = r[i - 1];
			pSum[i] = pSum[i - 1] + (x[2] - x[0] + 1) * (x[3] - x[1] + 1);
		}
		total = pSum.back() + (r.back()[2] - r.back()[0] + 1) * (r.back()[3] - r.back()[1] + 1);
	}

	std::vector<int> pick() {
		int pno = randIntN(total);
		int rno = std::upper_bound(pSum.begin(), pSum.end(), pno) - pSum.begin() - 1;
		const auto& t = r[rno];
		int x1 = t[0],
			y1 = t[1],
			x2 = t[2],
			y2 = t[3],
			rn = pno - pSum[rno];
		return {x1 + rn / (y2 - y1 + 1), y1 + rn % (y2 - y1 + 1)};
	}
};

int main() {
	std::vector<std::vector<int>> rect {{82918473,-57180867,82918476,-57180863},{83793579,18088559,83793580,18088560},{66574245,26243152,66574246,26243153},{72983930,11921716,72983934,11921720}};
	Solution s(rect);

	for (int i = 0; ; ++i) {
		auto x = s.pick();
		bool OK = false;
		for (const auto& r : rect) {
			if (x[0] >= r[0] && x[0] <= r[2] && x[1] >= r[1] && x[1] <= r[3]) {
				OK = true;
				break;
			}
		}
		if (!OK) {
			std::printf("0x%08X: Failed when returning {%d, %d}\n", i, x[0], x[1]);
		} else {
		//	std::printf("0x%08X: OK\n", i);
		}
	}

	return 0;
}
