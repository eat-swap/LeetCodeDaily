#include <vector>
#include <string>
#include <format>
#include <unordered_set>
#include <iostream>

/**
 * 386. Lexicographical Numbers
 * Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.
 * You must write an algorithm that runs in O(n) time and uses O(1) extra space.
 */

class Solution {
public:
	static std::vector<int> lexicalOrder(int n) {
		auto next = [n](int x) {
			if (10 * x <= n)
				return 10 * x;
			int nx = 1 + x;
			while (!(nx % 10))
				nx /= 10;
			while (nx > n)
				nx = nx / 10 + 1;
			while (!(nx % 10))
				nx /= 10;
			return nx;
		};

		std::vector<int> ret;
		ret.reserve(n);

		for (int i = 0, j = 1; i < n; ++i, j = next(j))
			ret.push_back(j);

		return ret;
	}
};

int main() {
	const int T = 14959;
	auto r = Solution::lexicalOrder(T);
	auto n = r.size();
	std::unordered_set<int> s;
	s.insert(1);
	for (int i = 1; i < n; ++i) {
		if (std::to_string(r[i - 1]) >= std::to_string(r[i]) || r[i] > T || s.contains(r[i])) {
			std::cout << std::format("Conflict: {} and {} at position {}\n", r[i - 1], r[i], i);
		}
		s.insert(r[i]);
	}
	for (int i = 1; i <= n; ++i)
		if (!s.contains(i))
			std::cout << std::format("Missing: {}\n", i);
	return 0;
}
