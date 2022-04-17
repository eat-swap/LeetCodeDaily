#include <iostream>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	explicit TreeNode(int x = 0, TreeNode* l = nullptr, TreeNode* r = nullptr) : val(x), left(l), right(r) {}
};

/**
 * 700. Search in a Binary Search Tree
 * You are given the root of a binary search tree (BST) and an integer val.
 * Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.
 */

class Solution {
public:
	TreeNode* searchBST(TreeNode* root, int val) {
		if (!root || val == root->val)
			return root;
		return searchBST(val < root->val ? root->left : root->right, val);
	}
};

int main() {
	return 0;
}