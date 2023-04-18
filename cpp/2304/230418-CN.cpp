struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	explicit TreeNode(int x, TreeNode* left = nullptr, TreeNode* right = nullptr) : val(x), left(left), right(right) {}
};

/**
 * 1026. Maximum Difference Between Node and Ancestor
 *
 * Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.
 * A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.
 */

class Solution {
private:
	static inline constexpr int MAX(int x, int y) { return x > y ? x : y; }
	static inline constexpr int MIN(int x, int y) { return x < y ? x : y; }
	static inline constexpr int ABS(int x) { return x < 0 ? -x : x; }

	static int dfs(TreeNode*, int, int);
public:
	static int maxAncestorDiff(TreeNode*);
};

int Solution::maxAncestorDiff(TreeNode* r) {
	return r ? dfs(r, r->val, r->val) : 0;
}

int Solution::dfs(TreeNode* n, int min, int max) {
	int ret = MAX(ABS(n->val - min), ABS(n->val - max));
	const int min_ = MIN(min, n->val), max_ = MAX(max, n->val);
	if (n->left)
		ret = MAX(ret, dfs(n->left, min_, max_));
	if (n->right)
		ret = MAX(ret, dfs(n->right, min_, max_));
	return ret;
}
