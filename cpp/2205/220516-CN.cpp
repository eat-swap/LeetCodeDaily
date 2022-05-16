#include <iostream>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	explicit TreeNode(int x, TreeNode* left = nullptr, TreeNode* right = nullptr) : val(x), left(left), right(right) {}
};

/**
 * 面试题 04.06. Successor LCCI
 * Write an algorithm to find the "next" node (i.e., in-order successor) of a given node in a binary search tree.
 * Return null if there's no "next" node for the given node.
 */

class Solution {
public:
	static TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
		if (!root || !p)
			return nullptr;
		// Target value: p->val;
		TreeNode* ret = nullptr;
		for (auto* ptr = root; ptr; ) {
			if (ptr->val == p->val) {
				for (ptr = ptr->right; ptr && ptr->left; ptr = ptr->left);
				return ptr ? ptr : ret;
			} else if (ptr->val < p->val) {
				ptr = ptr->right;
			} else {
				ret = ptr;
				ptr = ptr->left;
			}
		}
		return ret;
	}
};
