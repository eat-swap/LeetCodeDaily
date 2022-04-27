#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <functional>

/**
 * 1202. Smallest String With Swaps
 * You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.
 * You can swap the characters at any pair of indices in the given pairs any number of times.
 * Return the lexicographically smallest string that s can be changed to after using the swaps.
 */

class Solution {
public:
	static std::string smallestStringWithSwaps(const std::string& s, const std::vector<std::vector<int>>& pairs) {
		const int n = s.length();

		// Disjoint Set
		int* mother = new int[n];
		for (int i = 0; i < n; ++i)
			mother[i] = i;

		std::function<int(int)> Find = [&](int x) { return mother[x] == x ? x : mother[x] = Find(mother[x]); };
		auto Union = [&](int x, int y) { mother[Find(x)] = Find(y); };

		for (const auto& p : pairs)
			Union(p[0], p[1]);

		std::unordered_map<int, std::vector<int>> m;
		for (int i = 0; i < n; ++i)
			m[Find(i)].push_back(i);

		std::string ans = s;
		for (const auto& [i, v] : m) {
			if (v.size() <= 1)
				continue;

			int cnt[26]{};
			for (int idx : v)
				++cnt[s[idx] - 'a'];

			for (int ptr = 0, j = 0; ptr < 26; ++ptr)
				while (cnt[ptr]--)
					ans[v[j++]] = 'a' + ptr;
		}

		return ans;
	}
};

int main() {
	auto ans = Solution::smallestStringWithSwaps("dcab", {{0,3},{1,2}});
	std::cout << ans << "\n";
	return 0;
}
