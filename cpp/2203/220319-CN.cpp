#include <string>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	explicit TreeNode(int x, TreeNode* left = nullptr, TreeNode* right = nullptr) : val(x), left(left), right(right) {}
};

/**
 * 606. Construct String from Binary Tree
 * Given the root of a binary tree, construct a string consisting of parenthesis and integers from a binary tree with the preorder traversal way, and return it.
 * Omit all the empty parenthesis pairs that do not affect the one-to-one mapping relationship between the string and the original binary tree.
 */

class Solution {
public:
	static std::string tree2str(TreeNode* root) {
		if (!root)
			return "";
		auto ret = std::to_string(root->val);
		if (root->left || root->right)
			ret += "(" + tree2str(root->left) + ")";
		if (root->right)
			ret += "(" + tree2str(root->right) + ")";
		return ret;
	}
};
