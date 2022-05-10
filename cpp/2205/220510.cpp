#include <vector>
#include <functional>
#include <iostream>

/**
 * 216. Combination Sum III
 * Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
 *
 * Only numbers 1 through 9 are used.
 * Each number is used at most once.
 * Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.
 */

class Solution {
public:
	static std::vector<std::vector<int>> combinationSum3(int k, int n) {
		int current = 0;
		std::vector<int> work;
		std::vector<std::vector<int>> ret;
		work.reserve(k);

		std::function<void(int, int)> dfs = [&](int rem, int begin) {
			if (rem <= 1) {
				if (n - current > work.back() && n - current < 10) {
					ret.push_back(work);
					ret.back().push_back(n - current);
				}
				return;
			}

			for (int i = begin; i <= 9; current -= i++ /* On Exit */) {
				// On Entry
				current += i;

				// rem is at least 2.
				if (current + (rem - 1) * (i + 1) + (rem - 1) * (rem - 2) / 2 > n) {
					current -= i;
					break;
				}

				work.push_back(i);
				dfs(rem - 1, i + 1);
				work.pop_back();
			}
		};

		dfs(k, 1);

		return ret;
	}
};

int main() {
	auto r = Solution::combinationSum3(5, 30);
	for (const auto& i : r) {
		for (const auto& j : i) {
			std::cout << j << ' ';
		}
		std::cout << std::endl;
	}
	return 0;
}
