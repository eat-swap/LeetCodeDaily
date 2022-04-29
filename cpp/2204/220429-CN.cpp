#include <cstdlib>
#include <vector>
#include <functional>

// Definition for a QuadTree node.
class Node {
public:
    bool val, isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

	explicit Node(bool val = false, bool isLeaf = false, Node* topLeft = nullptr, Node* topRight = nullptr, Node* bottomLeft = nullptr, Node* bottomRight = nullptr) : val(val), isLeaf(isLeaf), topLeft(topLeft), topRight(topRight), bottomLeft(bottomLeft), bottomRight(bottomRight) {}
};

/**
 * 427. Construct Quad Tree
 * Given a n * n matrix grid of 0's and 1's only. We want to represent the grid with a Quad-Tree.
 * Return the root of the Quad-Tree representing the grid.
 */

class Solution {
public:
	Node* construct(std::vector<std::vector<int>>& G) {
		const int n = G.size();

		int* prefixSum = new int[(n + 1) * (1 + n)]{};
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				prefixSum[i * n + j] = prefixSum[(i - 1) * n + j] + prefixSum[i * n + j - 1] - prefixSum[(i - 1) * n + j - 1] + G[i - 1][j - 1];

		auto sum = [&](int x0, int y0, int x1, int y1) {
			return prefixSum[x1 * n + y1] - prefixSum[x0 * n + y1] - prefixSum[x1 * n + y0] + prefixSum[x0 * n + y0];
		};

		std::function<Node*(int, int, int, int)> dfs = [&](int x0, int y0, int x1, int y1) {
			int s = sum(x0, y0, x1, y1);
			if (!s)
				return new Node(false, true);
			if (s == (y1 - y0) * (x1 - x0))
				return new Node(true, true);
			const int mx = (x0 + x1) >> 1, my = (y0 + y1) >> 1;
			return new Node(std::rand() & 1, false, dfs(x0, y0, mx, my), dfs(x0, my, mx, y1), dfs(mx, y0, x1, my), dfs(mx, my, x1, y1));
		};

		return dfs(0, 0, n, n);
	}
};
