#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
	~TreeNode() { delete this->left; delete this->right; }
};

/**
 * 1022. Sum of Root To Leaf Binary Numbers
 * You are given the root of a binary tree where each node has a value 0 or 1. Each root-to-leaf path represents a binary number starting with the most significant bit.
 * For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
 * For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return the sum of these numbers.
 * The test cases are generated so that the answer fits in a 32-bits integer.
 */

class Solution {
public:
	static int sumRootToLeaf(const TreeNode* root, int n = 0) {
		if (!root->left && !root->right)
			return n + root->val;
		int ret = 0;
		if (root->left)
			ret += sumRootToLeaf(root->left, (n + root->val) << 1);
		if (root->right)
			ret += sumRootToLeaf(root->right, (n + root->val) << 1);
		return ret;
	}
};

int main() {
	TreeNode head(1, new TreeNode(0, new TreeNode(0), new TreeNode(1)), new TreeNode(1, new TreeNode(0), new TreeNode(1)));
	std::cout << Solution::sumRootToLeaf(&head);
	return 0;
}
