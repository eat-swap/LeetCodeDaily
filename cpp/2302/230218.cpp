#include <algorithm>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	explicit TreeNode(int x, TreeNode* left = nullptr, TreeNode* right = nullptr) : val(x), left(left), right(right) {}
};

/**
 * 226. Invert Binary Tree
 * Given the root of a binary tree, invert the tree, and return its root.
 */

class Solution {
public:
	static TreeNode* invertTree(TreeNode* root) {
		return root ? (std::swap(root->left, root->right), invertTree(root->left), invertTree(root->right), root) : nullptr;
	}
};
