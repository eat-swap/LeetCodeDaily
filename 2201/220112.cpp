#include <iostream>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
	~TreeNode() { delete this->left; delete this->right; }
};

class Solution {
public:
	static TreeNode* insertIntoBST(TreeNode* root, int val) {
		if (!root)
			return new TreeNode(val);
		if (val > root->val) {
			if (root->right) {
				insertIntoBST(root->right, val);
			} else {
				root->right = new TreeNode(val);
			}
		} else if (val < root->val) {
			if (root->left) {
				insertIntoBST(root->left, val);
			} else {
				root->left = new TreeNode(val);
			}
		} else {
			return nullptr;
		}
		return root;
	}
};