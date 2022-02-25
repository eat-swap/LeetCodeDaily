#include <vector>
#include <iostream>

/**
 * 1706. Where Will the Ball Fall
 * You have a 2-D grid of size m x n representing a box, and you have n balls. The box is open on the top and bottom sides.
 *
 * Each cell in the box has a diagonal board spanning two corners of the cell that can redirect a ball to the right or to the left.
 *
 * A board that redirects the ball to the right spans the top-left corner to the bottom-right corner and is represented in the grid as 1.
 * A board that redirects the ball to the left spans the top-right corner to the bottom-left corner and is represented in the grid as -1.
 * We drop one ball at the top of each column of the box. Each ball can get stuck in the box or fall out of the bottom. A ball gets stuck if it hits a "V" shaped pattern between two boards or if a board redirects the ball into either wall of the box.
 *
 * Return an array answer of size n where answer[i] is the column that the ball falls out of at the bottom after dropping the ball from the ith column at the top, or -1 if the ball gets stuck in the box.
 */

class Solution {
public:
	static std::vector<int> findBall(const std::vector<std::vector<int>>& grid) {
		const int n = grid.front().size();
		std::vector<int> ret(n);
		for (int i = 0; i < n; ++i) {
			ret[i] = i;
		}

		for (auto it = grid.begin(); it != grid.end(); ++it) {
			const std::vector<int>& now = *it;
			for (int i = 0; i < n; ++i) {
				if (ret[i] == -1)
					continue;
				if (ret[i] < n - 1 && now[ret[i]] == 1 && now[ret[i] + 1] == 1) { // goes R
					++ret[i];
				} else if (ret[i] && now[ret[i]] == -1 && now[ret[i] - 1] == -1) { // goes L
					--ret[i];
				} else { // nowhere to go!
					ret[i] = -1;
				}
			}
		}

		return ret;
	}
};

int main() {
	// auto ret = Solution::findBall({{1,1,1,-1,-1},{1,1,1,-1,-1},{-1,-1,-1,1,1},{1,1,1,1,-1},{-1,-1,-1,-1,-1}});
	// auto ret = Solution::findBall({{-1}});
	auto ret = Solution::findBall({{1,1,1,1,1,1},{-1,-1,-1,-1,-1,-1},{1,1,1,1,1,1},{-1,-1,-1,-1,-1,-1}});
	for (auto i : ret) {
		std::cout << i << ' ';
	}
}
