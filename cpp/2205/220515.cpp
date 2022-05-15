#include <queue>
#include <utility>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	explicit TreeNode(int x = 0, TreeNode* l = nullptr, TreeNode* r = nullptr) : val(x), left(l), right(r) {}
};

/**
 * 1302. Deepest Leaves Sum
 * Given the root of a binary tree, return the sum of values of its deepest leaves.
 */

class Solution {
public:
	static int deepestLeavesSum(TreeNode* r) {
		if (!r) return 0;
		std::queue<std::pair<const TreeNode*, int>> q;
		int ret = 0, l = 0;
		q.push({r, 0});
		while (!q.empty()) {
			const auto [n, d] = q.front();
			q.pop();
			ret = (d == l ? ret : 0) + n->val;
			l = d;
			if (n->left) q.push({n->left, 1 + d});
			if (n->right) q.push({n->right, 1 + d});
		}
		return ret;
	}
};
