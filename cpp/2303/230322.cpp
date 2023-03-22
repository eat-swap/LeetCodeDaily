#include <vector>
#include <numeric>
#include <iostream>

/**
 * 2492. Minimum Score of a Path Between Two Cities
 *
 * You are given a positive integer n representing n cities numbered from 1 to n. You are also given a 2D array roads where roads[i] = [ai, bi, distancei] indicates that there is a bidirectional road between cities ai and bi with a distance equal to distancei. The cities graph is not necessarily connected.
 *
 * The score of a path between two cities is defined as the minimum distance of a road in this path.
 *
 * Return the minimum possible score of a path between cities 1 and n.
 *
 * Note:
 *
 * A path is a sequence of roads between two cities.
 * It is allowed for a path to contain the same road multiple times, and you can visit cities 1 and n multiple times along the path.
 * The test cases are generated such that there is at least one path between 1 and n.
 */

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

class Solution {
public:
	static int minScore(int n, const std::vector<std::vector<int>>& roads) {
		UnionFindSet ufs(n);
		for (const auto & road : roads)
			ufs.uni(road[0], road[1]);
		int ret = 0x7FFFFFFF;
		const int f1 = ufs.find(1);
		for (const auto& road: roads)
			if (ufs.find(road[0]) == f1)
				ret = std::min(ret, road[2]);
		return ret;
	}
};

int main() {
	std::cout << Solution::minScore(14, {{2,9,2308},{2,5,2150},{12,3,4944},{13,5,5462},{2,10,2187},{2,12,8132},{2,13,3666},{4,14,3019},{2,4,6759},{2,14,9869},{1,10,8147},{3,4,7971},{9,13,8026},{5,12,9982},{10,9,6459}});
	return 0;
}
