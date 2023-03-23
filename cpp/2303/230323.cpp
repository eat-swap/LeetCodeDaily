#include <vector>
#include <numeric>
#include <unordered_set>

class UnionFindSet {
private:
	std::vector<int> f;

public:
	explicit UnionFindSet(int n) : f(n + 1) {
		std::iota(f.begin(), f.end(), 0);
	}

	int find(int x) {
		return (x == f[x]) ? x : (f[x] = find(f[x]));
	}

	// Merge y to x
	int uni(int x, int y) {
		return f[find(y)] = find(x);
	}
};

/**
 * 1319. Number of Operations to Make Network Connected
 *
 * There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.
 *
 * You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.
 *
 * Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.
 */

class Solution {
public:
	static int makeConnected(int n, const std::vector<std::vector<int>>& connections) {
		if (connections.size() < n - 1)
			return -1;
		UnionFindSet ufs(n);
		for (const auto& i : connections)
			ufs.uni(i[0], i[1]);
		std::unordered_set<int> s;
		for (int i = 0; i < n; ++i)
			s.insert(ufs.find(i));
		return s.size() - 1;
	}
};
