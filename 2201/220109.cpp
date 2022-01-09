#include <string>
#include <iostream>

/**
 * 1041. Robot Bounded In Circle
 * On an infinite plane, a robot initially stands at (0, 0) and faces north. The robot can receive one of three instructions:
 * "G": go straight 1 unit;
 * "L": turn 90 degrees to the left;
 * "R": turn 90 degrees to the right.
 * The robot performs the instructions given in order, and repeats them forever.
 * Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.
 */

class Solution {
private:
	// N, E, S, W
	inline static int dX[4] = {0, 1, 0, -1};
	inline static int dY[4] = {1, 0, -1, 0};
public:
	static bool isRobotBounded(std::string instructions) {
		// instructions = instructions * 8;
		instructions.append(instructions);
		instructions.append(instructions);
		instructions.append(instructions);

		int l = instructions.length();
		int X = 0, Y = 0, D = 0;
		const char* const str = instructions.c_str();
		for (int i = 0; i < l; ++i) {
			switch (str[i]) {
				case 'G':
					X += dX[D];
					Y += dY[D];
					break;
				case 'L':
					D = (D + 3) % 4;
					break;
				case 'R':
					D = (D + 1) % 4;
					break;
				default:
					; // Should never reach here.
			}
			if (!X && !Y && !D && !std::strncmp(str, str + i + 1, i + 1)) {
				return true;
			}
		}
		return false;
	}
};

int main() {
	bool ans = Solution::isRobotBounded("GL");
	std::cout << ans;
	return 0;
}