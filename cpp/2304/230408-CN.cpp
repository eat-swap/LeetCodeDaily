#include <functional>
#include <iostream>
#include <ostream>
#include <vector>
#include <string>
#include <unordered_map>

/**
 * 1125. Smallest Sufficient Team
 *
 * In a project, you have a list of required skills req_skills, and a list of people. The ith person people[i] contains a list of skills that the person has.
 *
 * Consider a sufficient team: a set of people such that for every required skill in req_skills, there is at least one person in the team who has that skill. We can represent these teams by the index of each person.
 *
 * For example, team = [0, 1, 3] represents the people with skills people[0], people[1], and people[3].
 * Return any sufficient team of the smallest possible size, represented by the index of each person. You may return the answer in any order.
 *
 * It is guaranteed an answer exists.
 */

class Solution {
public:
	template<typename T>
	using V = std::vector<T>;
	using VI = V<int>;
	using VS = V<std::string>;
	using VVS = V<VS>;

	static VI smallestSufficientTeam(const VS&, const VVS&);
};

Solution::VI Solution::smallestSufficientTeam(const VS& req, const VVS& p) {
	int n = 0;
	std::unordered_map<std::string, int> m;
	for (auto&& x : req)
		m[x] = n++;
	VI ps;
	for (auto&& x : p) {
		int y = 0;
		for (auto&& z : x)
			y |= (1 << m[z]);
		ps.push_back(y);
	}
	VI dp(1 << 16), father(1 << 16);
	const int full = (1 << n) - 1, k = ps.size();
	std::function<int(int)> d = [&](int current) {
		if (dp[current])
			return dp[current];
		if (current == full)
			return 0;
		int& ans = dp[current];
		ans = 0x7FFFFFFF;
		for (int i = 0, next; i < k; ++i) {
			next = current | ps[i];
			if (current == next)
				continue;
			if (int dn = d(next); 1 + dn < ans) {
				ans = 1 + dn;
				father[current] = i;
			}
		}
		return ans;
	};
	d(0);
	VI ret;
	for (int i = 0; i < full; i = i | ps[father[i]])
		ret.push_back(father[i]);
	return ret;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> vec) {
	for (auto&& x : vec)
		os << x;
	return os;
}

int main() {
	std::cout << Solution::smallestSufficientTeam({"algorithms","math","java","reactjs","csharp","aws"}, {
		{"algorithms","math","java"},
		{"algorithms","math","reactjs"},
		{"java","csharp","aws"},
		{"reactjs","csharp"},
		{"csharp","math"},
		{"aws","java"}
	});
	return 0;
}
