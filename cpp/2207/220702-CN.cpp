#include <queue>
#include <vector>

/**
 * 871. Minimum Number of Refueling Stops
 * A car travels from a starting position to a destination which is target miles east of the starting position.
 * There are gas stations along the way. The gas stations are represented as an array stations where stations[i] = [positioni, fueli] indicates that the ith gas station is positioni miles east of the starting position and has fueli liters of gas.
 * The car starts with an infinite tank of gas, which initially has startFuel liters of fuel in it. It uses one liter of gas per one mile that it drives. When the car reaches a gas station, it may stop and refuel, transferring all the gas from the station into the car.
 * Return the minimum number of refueling stops the car must make in order to reach its destination. If it cannot reach the destination, return -1.
 * Note that if the car reaches a gas station with 0 fuel left, the car can still refuel there. If the car reaches the destination with 0 fuel left, it is still considered to have arrived.
 */

class Solution {
public:
	static int minRefuelStops(int target, int startFuel, const std::vector<std::vector<int>>& stations) {
		int f = startFuel, pos = 0;
		std::priority_queue<int> q;
		for (const auto& x : stations) {
			f -= x[0] - pos;
			pos = x[0];
			while (f < 0 && !q.empty()) {
				f += q.top();
				q.pop();
			}
			if (f < 0 && q.empty())
				return -1;
			q.push(x[1]);
		}
		f -= target - pos;
		while (f < 0 && !q.empty()) {
			f += q.top();
			q.pop();
		}
		if (f < 0 && q.empty())
			return -1;
		return stations.size() - q.size();
	}
};

int main() {
	Solution::minRefuelStops(100, 10, {{10,60},{20,30},{30,30},{60,40}});
	return 0;
}