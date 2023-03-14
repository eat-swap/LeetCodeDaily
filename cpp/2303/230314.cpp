#include <functional>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	explicit TreeNode(int x, TreeNode* left = nullptr, TreeNode* right = nullptr) : val(x), left(left), right(right) {}
};

/**
 * 129. Sum Root to Leaf Numbers
 *
 * You are given the root of a binary tree containing digits from 0 to 9 only.
 * Each root-to-leaf path in the tree represents a number.
 * For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
 * Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.
 * A leaf node is a node with no children.
 */

class Solution {
public:
	static int sumNumbers(const TreeNode* root) {
		if (!root)
			return 0;
		int stack[16]{root->val}, ptr = 0, ans = 0;
		std::function<void(const TreeNode*)> dfs = [&](const TreeNode* r) {
			if (!r->left && !r->right) {
				ans += stack[ptr];
				return;
			}
			++ptr;
			if (r->left) {
				stack[ptr] = 10 * stack[ptr - 1] + r->left->val;
				dfs(r->left);
			}
			if (r->right) {
				stack[ptr] = 10 * stack[ptr - 1] + r->right->val;
				dfs(r->right);
			}
			--ptr;
		};
		dfs(root);
		return ans;
	}
};
