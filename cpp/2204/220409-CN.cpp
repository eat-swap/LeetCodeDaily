#include <chrono>
#include <numeric>
#include <iostream>

/**
 * 780. Reaching Points
 * Given four integers sx, sy, tx, and ty, return true if it is possible to convert the point (sx, sy) to the point (tx, ty) through some operations, or false otherwise.
 * The allowed operation on some point (x, y) is to convert it to either (x, x + y) or (x + y, y).
 */

class Solution {
public:
	static constexpr bool reachingPoints(int sx, int sy, int tx, int ty) {
		for (; tx != ty && tx > sx && ty > sy; *(tx > ty ? &tx : &ty) = std::abs(tx - ty))
			if (tx == sx && ty == sy)
				return true;
		return (tx == sx && ty > sy && !((ty - sy) % sx)) || (ty == sy && tx > sx && !((tx - sx) % sy)) || (tx == sx && ty == sy);
	}
};

int main() {
	const auto start = std::chrono::steady_clock::now();
	std::cout << Solution::reachingPoints(1, 6, 11, 10) << std::endl;
	const auto end = std::chrono::steady_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;
}
