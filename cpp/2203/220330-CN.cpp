#include <vector>
#include <set>
#include <queue>
#include <iostream>

/**
 * 1606. Find Servers That Handled Most Number of Requests
 * You have k servers numbered from 0 to k-1 that are being used to handle multiple requests simultaneously. Each server has infinite computational capacity but cannot handle more than one request at a time. The requests are assigned to servers according to a specific algorithm:
 * The ith (0-indexed) request arrives.
 * If all servers are busy, the request is dropped (not handled at all).
 * If the (i % k)th server is available, assign the request to that server.
 * Otherwise, assign the request to the next available server (wrapping around the list of servers and starting from 0 if necessary). For example, if the ith server is busy, try to assign the request to the (i+1)th server, then the (i+2)th server, and so on.
 * You are given a strictly increasing array arrival of positive integers, where arrival[i] represents the arrival time of the ith request, and another array load, where load[i] represents the load of the ith request (the time it takes to complete). Your goal is to find the busiest server(s). A server is considered busiest if it handled the most number of requests successfully among all the servers.
 * Return a list containing the IDs (0-indexed) of the busiest server(s). You may return the IDs in any order.
 */

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
