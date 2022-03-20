#include <vector>
#include <functional>
#include <iostream>

/**
 * 2049. Count Nodes With the Highest Score
 * There is a binary tree rooted at 0 consisting of n nodes. The nodes are labeled from 0 to n - 1. You are given a 0-indexed integer array parents representing the tree, where parents[i] is the parent of node i. Since node 0 is the root, parents[0] == -1.
 * Each node has a score. To find the score of a node, consider if the node and the edges connected to it were removed. The tree would become one or more non-empty subtrees. The size of a subtree is the number of the nodes in it. The score of the node is the product of the sizes of all those subtrees.
 * Return the number of nodes that have the highest score.
 */

class Solution {
public:
	static int countHighestScoreNodes(const std::vector<int>& parents) {
		auto n = parents.size();
		int* L = new int[n]{};
		int* R = new int[n]{};
		int* sizeOfSubtrees = new int[n]{};

		for (int i = 1; i < n; ++i)
			*(L[parents[i]] ? &R[parents[i]] : &L[parents[i]]) = i;

		std::function<int(int)> getSubtreeSize = [&](int node) {
			if (sizeOfSubtrees[node])
				return sizeOfSubtrees[node];
			int ret = 1;
			if (L[node])
				ret += getSubtreeSize(L[node]);
			if (R[node])
				ret += getSubtreeSize(R[node]);
			return sizeOfSubtrees[node] = ret;
		};

		unsigned long long retMax = 0;
		int ret = -1;
		for (int i = 0; i < n; ++i) {
			int sizeL = 0, sizeR = 0, sizeOther = n - 1;
			if (L[i])
				sizeOther -= (sizeL = getSubtreeSize(L[i]));
			if (R[i])
				sizeOther -= (sizeR = getSubtreeSize(R[i]));
			auto size = static_cast<unsigned long long>(sizeL ? sizeL : 1) * static_cast<unsigned long long>(sizeR ? sizeR : 1) * static_cast<unsigned long long>(sizeOther ? sizeOther : 1);
			if (retMax < size) {
				retMax = size;
				ret = 1;
			} else if (retMax == size) {
				++ret;
			}
		}

		delete[] L;
		delete[] R;
		delete[] sizeOfSubtrees;

		return ret;
	}
};

int main() {
	std::cout << Solution::countHighestScoreNodes({-1,2,0});
	return 0;
}
