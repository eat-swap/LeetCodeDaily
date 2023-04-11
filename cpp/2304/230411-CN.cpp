#include <string>

/**
 * 1041. Robot Bounded In Circle
 *
 * On an infinite plane, a robot initially stands at (0, 0) and faces north. Note that:
 *
 * The north direction is the positive direction of the y-axis.
 * The south direction is the negative direction of the y-axis.
 * The east direction is the positive direction of the x-axis.
 * The west direction is the negative direction of the x-axis.
 * The robot can receive one of three instructions:
 *
 * "G": go straight 1 unit.
 * "L": turn 90 degrees to the left (i.e., anti-clockwise direction).
 * "R": turn 90 degrees to the right (i.e., clockwise direction).
 * The robot performs the instructions given in order, and repeats them forever.
 *
 * Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.
 *
 * Refer: 220109.cpp
 */

class Solution {
private:
	// N, W, S, E
	static const inline short dX[] = {0, -1, 0, 1};
	static const inline short dY[] = {1, 0, -1, 0};
public:
	static bool isRobotBounded(const std::string&);
};

bool Solution::isRobotBounded(const std::string& instructions) {
	const int n = instructions.size();
	short X = 0, Y = 0, D = 0;
	for (int i = 0; i < (n << 2); ++i) {
		if (char ch = instructions[i % n]; ch == 'G') {
			X += dX[D];
			Y += dY[D];
		} else D = (D + 1 + (ch & 3)) & 3;
	}
	return !(X | Y | D);
}

int main() {
	Solution::isRobotBounded("LLGRL");
	return 0;
}
