#include <vector>
#include <numeric>
#include <unordered_map>
#include <iostream>

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
 * 2316. Count Unreachable Pairs of Nodes in an Undirected Graph
 *
 * You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.
 * Return the number of pairs of different nodes that are unreachable from each other.
 */

class Solution {
public:
	static long long countPairs(int n, const std::vector<std::vector<int>>& edges) {
		UnionFindSet ufs(n);
		for (auto&& i : edges)
			ufs.uni(i[0], i[1]);
		std::unordered_map<int, int> m;
		for (int i = 0; i < n; ++i)
			++m[ufs.find(i)];
		long long ret = 0;
		for (auto&& [_, cnt] : m)
			ret += (long long)(n - cnt) * (long long)(cnt);
		return ret >> 1;
	}
};

int main() {
	std::cout << Solution::countPairs(7, {
		{0,2},{0,5},{2,4},{1,6},{5,4}
	});
}
