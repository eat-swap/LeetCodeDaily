#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

class CustomFunction {
public:
	int f(int x, int y);
};

/**
 * 1237. Find Positive Integer Solution for a Given Equation
 * Given a callable function f(x, y) with a hidden formula and a value z, reverse engineer the formula and return all positive integer pairs x and y where f(x,y) == z. You may return the pairs in any order.
 *
 * While the exact formula is hidden, the function is monotonically increasing, i.e.:
 *
 * f(x, y) < f(x + 1, y)
 * f(x, y) < f(x, y + 1)
 * The function interface is defined like this:
 *
 * interface CustomFunction {
 * public:
 *   // Returns some positive integer f(x, y) for two positive integers x and y based on a formula.
 *   int f(int x, int y);
 * };
 * We will judge your solution as follows:
 *
 * The judge has a list of 9 hidden implementations of CustomFunction, along with a way to generate an answer key of all valid pairs for a specific z.
 * The judge will receive two inputs: a function_id (to determine which implementation to test your code with), and the target z.
 * The judge will call your findSolution and compare your results with the answer key.
 * If your results match the answer key, your solution will be Accepted.
 */

class Solution {
public:
	static std::vector<std::vector<int>> findSolution(CustomFunction& cf, int z) {
		std::vector<int> p(1000);
		std::iota(p.begin(), p.end(), 1);
		auto L = std::lower_bound(p.begin(), p.end(), z, [&](int x, int y) {
			return cf.f(x, 1000) < y;
		}), R = std::upper_bound(p.begin(), p.end(), z, [&](int x, int y) {
			return cf.f(y, 1) > x;
		});
		std::vector<std::vector<int>> ret;
		std::for_each(L, R, [&](int x) {
			auto L2 = std::lower_bound(p.begin(), p.end(), z, [&](int m, int n) {
				return cf.f(x, m) < n;
			}), R2 = std::upper_bound(p.begin(), p.end(), z, [&](int m, int n) {
				return cf.f(x, n) > m;
			});
			std::for_each(L2, R2, [&](int y) {
				ret.push_back({x, y});
			});
		});
		return ret;
	}
};

int CustomFunction::f(int x, int y) {
	return x * y;
}

int main() {
	CustomFunction f;
	auto ret = Solution::findSolution(f, 5);
	for (auto p : ret)
		std::cout << p[0] << ", " << p[1] << std::endl;
	return 0;
}
