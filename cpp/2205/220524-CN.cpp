#include <functional>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	explicit TreeNode(int x = 0, TreeNode* l = nullptr, TreeNode* r = nullptr) : val(x), left(l), right(r) {}
};

/**
 * 965. Univalued Binary Tree
 * A binary tree is uni-valued if every node in the tree has the same value.
 * Given the root of a binary tree, return true if the given tree is uni-valued, or false otherwise.
 */

class Solution {
public:
	static bool isUnivalTree(TreeNode* root) {
		if (!root)
			return true;
		std::function<bool(const TreeNode*)> dfs = [&](const TreeNode* ptr) {
			return !ptr || (ptr->val == root->val && dfs(ptr->left) && dfs(ptr->right));
		};
		return dfs(root->left) && dfs(root->right);
	}
};
