#include <vector>
#include <queue>
#include <iostream>

/**
 * 2039. The Time When the Network Becomes Idle
 * There is a network of n servers, labeled from 0 to n - 1. You are given a 2D integer array edges, where edges[i] = [ui, vi] indicates there is a message channel between servers ui and vi, and they can pass any number of messages to each other directly in one second. You are also given a 0-indexed integer array patience of length n.
 * All servers are connected, i.e., a message can be passed from one server to any other server(s) directly or indirectly through the message channels.
 * The server labeled 0 is the master server. The rest are data servers. Each data server needs to send its message to the master server for processing and wait for a reply. Messages move between servers optimally, so every message takes the least amount of time to arrive at the master server. The master server will process all newly arrived messages instantly and send a reply to the originating server via the reversed path the message had gone through.
 * At the beginning of second 0, each data server sends its message to be processed. Starting from second 1, at the beginning of every second, each data server will check if it has received a reply to the message it sent (including any newly arrived replies) from the master server:
 * If it has not, it will resend the message periodically. The data server i will resend the message every patience[i] second(s), i.e., the data server i will resend the message if patience[i] second(s) have elapsed since the last time the message was sent from this server.
 * Otherwise, no more resending will occur from this server.
 * The network becomes idle when there are no messages passing between servers or arriving at servers.
 * Return the earliest second starting from which the network becomes idle.
 */

class Solution {
public:
	static int networkBecomesIdle(const std::vector<std::vector<int>>& edges, const std::vector<int>& patience) {
		std::vector<std::vector<int>> G(edges.size() + 1);
		for (const auto& i : edges) {
			G[i[0]].push_back(i[1]);
			G[i[1]].push_back(i[0]);
		}

		int n = patience.size();
		int* const len = new int[n]{};

		{
			bool* const vis = new bool[n]{true};
			std::queue<int> q;
			q.push(0);
			q.push(0);
			while (!q.empty()) {
				int x = q.front();
				q.pop();
				int l = q.front();
				q.pop();
				len[x] = l;
				for (int nx : G[x]) {
					if (!vis[nx]) {
						vis[nx] = true;
						q.push(nx);
						q.push(1 + l);
					}
				}
			}
			delete[] vis;
		}

		int ret = 0;
		for (int i = 1; i < n; ++i) {
			int recv = len[i] << 1;
			int lastSent = recv - (recv % patience[i] ? recv % patience[i] : patience[i]);
			ret = std::max(lastSent + recv, ret);
		}

		delete[] len;
		return 1 + ret;
	}
};

int main() {
	std::cout << Solution::networkBecomesIdle({{0, 1}, {1, 2}}, {0, 2, 1}) << "\n"
	          << Solution::networkBecomesIdle({{0, 1}, {0, 2}, {1, 2}}, {0, 10, 10}) << "\n";
	return 0;
}
