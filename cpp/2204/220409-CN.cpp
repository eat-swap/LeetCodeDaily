#include <chrono>
#include <numeric>
#include <iostream>

class Solution {
public:
	static bool reachingPoints(int sx, int sy, int tx, int ty) {
		for (; tx != ty && tx > sx && ty > sy; *(tx > ty ? &tx : &ty) = std::abs(tx - ty))
			if (tx == sx && ty == sy)
				return true;
		return (tx == sx && ty > sy && !((ty - sy) % sx)) || (ty == sy && tx > sx && !((tx - sx) % sy));
	}
};

int main() {
	const auto start = std::chrono::steady_clock::now();
	std::cout << Solution::reachingPoints(1, 6, 11, 10) << std::endl;
	const auto end = std::chrono::steady_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;
}
