#include <vector>
#include <set>
#include <queue>
#include <iostream>

class Solution {
public:
	static std::vector<int> busiestServers(int k, const std::vector<int>& arrival, const std::vector<int>& load) {
		int n = arrival.size();

		std::set<int> pool;

		// pair [nextFinish, id]
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;

		// Load time
		std::vector<int> cnt(k);

		// Initially, all server are available.
		for (int i = 0; i < k; ++i)
			pool.insert(i);

		// Simulate over time...
		for (int i = 0; i < n; ++i) {
			int t = arrival[i];

			// Pop any finished tasks, then put them into the pool.
			while (!q.empty() && q.top().first <= t) {
				pool.insert(q.top().second);
				q.pop();
			}

			// If no available, ignore this task.
			if (pool.empty())
				continue;

			// Find the server to use.
			auto it = pool.lower_bound(i % k);
			if (it == pool.end())
				it = pool.begin();

			// Record the usage
			++cnt[*it];
			q.push({t + load[i], *it});
			pool.erase(it);
		}

		int m = *std::max_element(cnt.begin(), cnt.end());
		std::vector<int> ret;
		for (int i = 0; i < k; ++i)
			if (m == cnt[i])
				ret.push_back(i);
		return ret;
	}
};

int main() {
	std::vector<int> ret = Solution::busiestServers(3, {1, 2, 3, 4, 5}, {5, 2, 3, 3, 3});
	for (int i : ret)
		std::cout << i << ' ';
	return 0;
}
