#include <vector>
#include <string>
#include <regex>
#include <iostream>
#include <cctype>

/**
 * 1023. Camelcase Matching
 *
 * Given an array of strings queries and a string pattern, return a boolean array answer where answer[i] is true if queries[i] matches pattern, and false otherwise.
 * A query word queries[i] matches pattern if you can insert lowercase English letters pattern so that it equals the query. You may insert each character at any position and you may not insert any characters.
 *
 * Note: this solution (using regex) is VERY VERY slow
 */

class Solution {
	template<typename T>
	using V = std::vector<T>;
	using S = std::string;
	static constexpr inline bool is_lower(char c) { return c >= 'a' && c <= 'z'; }
    static V<bool> camelMatchAlt(const V<S>&, const S&);
public:
	static V<bool> camelMatch(const V<S>&, const S&);
};

std::vector<bool> Solution::camelMatch(const V<S>& queries, const S& pattern) {
	// return camelMatchAlt(queries, pattern);
	S regex_str = "[a-z]*";
	for (char ch : pattern) {
		regex_str += ch;
		regex_str += "[a-z]*";
	}
	std::regex matcher(regex_str, std::regex_constants::optimize);
	std::vector<bool> ret;
	for (auto&& q : queries)
		ret.push_back(std::regex_match(q, matcher));
	return ret;
}

std::vector<bool> Solution::camelMatchAlt(const V<S>& qs, const S& p) {
	std::vector<bool> ret;
	const int n = p.length();
	for (auto&& q : qs) {
		int pp = 0, pq = 0;
		const int m = q.length();
		for (; pq < m; ++pq)
			if (q[pq] == p[pp]) {
				if (++pp >= n) break;
			} else if (!std::islower(q[pq])) break;
		ret.push_back(pp >= n && std::all_of(q.begin() + ++pq, q.end(), [](char c) {
			return std::islower(c);
		}));
	}
	return ret;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> vec) {
	for (auto&& x : vec)
		os << x << std::endl;
	return os;
}

int main() {
	std::cout << Solution::camelMatch(
		{"FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"},
		"FB"
	);
	return 0;
}
