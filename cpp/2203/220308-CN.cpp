#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <functional>

/**
 * 2055. Plates Between Candles
 * There is a long table with a line of plates and candles arranged on top of it. You are given a 0-indexed string s consisting of characters '*' and '|' only, where a '*' represents a plate and a '|' represents a candle.
 * You are also given a 0-indexed 2D integer array queries where queries[i] = [lefti, righti] denotes the substring s[lefti...righti] (inclusive). For each query, you need to find the number of plates between candles that are in the substring. A plate is considered between candles if there is at least one candle to its left and at least one candle to its right in the substring.
 * For example, s = "||**||**|*", and a query [3, 8] denotes the substring "*||**|". The number of plates between candles in this substring is 2, as each of the two plates has at least one candle in the substring to its left and right.
 * Return an integer array answer where answer[i] is the answer to the ith query.
 */

class Solution {
private:
	inline static constexpr int HIGH(int x, int y) {
		const int r = 32 - __builtin_clz(x ^ y);
		return ((((x | y) >> r) + 1) << r) - 1;
	}

	inline static constexpr int MID(int x, int y) {
		return (x | y) & ~((1 << 31 - __builtin_clz(x ^ y)) - 1);
	}

	inline static constexpr int LOW(int x, int y) {
		const int r = 32 - __builtin_clz(x ^ y);
		return (x | y) >> r << r;
	}

	inline static constexpr int MSB(int x) {
		return 31 - __builtin_clz(x);
	}

public:
	static std::vector<int> platesBetweenCandles(const std::string& s, const std::vector<std::vector<int>>& queries) {
		int n = s.length();
		std::vector<std::unordered_map<int, int>> ans(32 - __builtin_clz(n));
		std::vector<int> ret, positions;
		ret.reserve(queries.size());

		for (int i = 0; i < n; ++i)
			if (s[i] == '|')
				positions.push_back(i);

		if (positions.empty())
			return std::vector<int>(queries.size());

		std::function<int(int, int)> dp;
		dp = [&](int L, int R) {
			if (L == R)
				return int(s[L] == '*');
			if (L == (R ^ 1))
				return ans[1][L >> 1] = (s[L] == '*') + (s[R] == '*');

			if (L == LOW(L, R) && R == HIGH(L, R)) {
				const int x = 1 + MSB(L ^ R), idx = L >> x;
				auto& m = ans[x];
				if (m.count(idx))
					return m[idx];
				else
					return m[idx] = dp(L, L | ((1 << (x - 1)) - 1)) + dp(L | (1 << (x - 1)), R);
			} else {
				int M = MID(L, R);
				return dp(L, M - 1) + dp(M, R);
			}
		};

		for (auto i : queries) {
			auto begin = std::lower_bound(positions.begin(), positions.end(), i[0]);
			auto end = std::lower_bound(positions.begin(), positions.end(), i[1]);
			if (begin == end) {
				ret.push_back(0);
				continue;
			}
			if (end == positions.end() || *end > i[1])
				--end;
			if (begin == positions.end() || *begin >= *end)
				ret.push_back(0);
			else
				ret.push_back(dp(*begin, *end));
		}
		return ret;
	}
};

int main() {
	auto ret = Solution::platesBetweenCandles("*|*|||", {{0, 0}, {1, 3}});
	for (int i : ret)
		std::cout << i << ' ';
	return 0;
}
