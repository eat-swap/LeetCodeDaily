#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <bitset>
#include <queue>

#include "defs.h"

int to_int(const char* s) {
	int n = 0;
	for (; *s; ++s)
		n = (n << 3) + (n << 1) + (*s ^ 48);
	return n;
}

int LC240422::openLock(const std::vector<std::string>& de, std::string target) {
	std::unordered_set<int> s;
	for (const auto& str : de)
		s.insert(to_int(str.c_str()));
	int t = to_int(target.c_str());
	if (s.count(0) && t != 0)
		return -1;
	std::bitset<10004> vis;
	std::queue<std::pair<int, int>> q;
	q.emplace(0, 0);
	vis[0] = true;
	while (!q.empty()) {
		const auto [c, st] = q.front();
		q.pop();
		if (c == t)
			return st;
		for (int ns : {1, 10, 100, 1000, -1, -10, -100, -1000}) {
			int nc = (c % std::abs(ns)) +
					c / (std::abs(ns) * 10) * (std::abs(ns) * 10) +
					(((c / std::abs(ns)) % 10 + (ns / std::abs(ns)) + 10) % 10) * std::abs(ns);
			std::printf("%04d -> %04d\n", c, nc);
			if (!vis[nc] && !s.count(nc)) {
				vis[nc] = true;
				q.emplace(nc, st + 1);
				if (nc == t)
					return st + 1;
			}
		}
	}
	return -1;
}
