#include <iostream>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	explicit TreeNode(int x, TreeNode* left = nullptr, TreeNode* right = nullptr) : val(x), left(left), right(right) {}
};

/**
 * 669. Trim a Binary Search Tree
 * Given the root of a binary search tree and the lowest and highest boundaries as low and high, trim the tree so that all its elements lies in [low, high]. Trimming the tree should not change the relative structure of the elements that will remain in the tree (i.e., any node's descendant should remain a descendant). It can be proven that there is a unique answer.
 * Return the root of the trimmed binary search tree. Note that the root may change depending on the given bounds.
 */

class Solution {
public:
	static TreeNode* trimBST(TreeNode* root, int low, int high) {
		if (!root)
			return nullptr;
		if (root->val < low)
			return trimBST(root->right, low, high);
		if (high < root->val)
			return trimBST(root->left, low, high);
		root->left = trimBST(root->left, low, high);
		root->right = trimBST(root->right, low, high);
		return root;
	}
};
