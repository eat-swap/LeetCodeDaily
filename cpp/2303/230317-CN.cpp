#include <vector>
#include <algorithm>
#include <iostream>

/**
 * 2389. Longest Subsequence With Limited Sum
 *
 * You are given an integer array nums of length n, and an integer array queries of length m.
 * Return an array answer of length m where answer[i] is the maximum size of a subsequence that you can take from nums such that the sum of its elements is less than or equal to queries[i].
 * A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
 */

class Solution {
public:
	static std::vector<int> answerQueries(std::vector<int>& n, const std::vector<int>& q) {
		std::sort(n.begin(), n.end());
		for (int i = 1; i < n.size(); ++i)
			n[i] += n[i - 1];
		std::vector<int> ret(q.size());
		for (int i = 0; i < q.size(); ++i)
			ret[i] = std::upper_bound(n.begin(), n.end(), q[i]) - n.begin();
		return ret;
	}
};

int main() {
	std::vector<int> n {4,5,2,1};
	for (int i : Solution::answerQueries(n, {3,10,21}))
		std::cout << i << '\n';
	return 0;
}
