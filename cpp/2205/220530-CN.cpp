struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	explicit TreeNode(int x, TreeNode* left = nullptr, TreeNode* right = nullptr) : val(x), left(left), right(right) {}
};

/**
 * 1022. Sum of Root To Leaf Binary Numbers
 * You are given the root of a binary tree where each node has a value 0 or 1. Each root-to-leaf path represents a binary number starting with the most significant bit.
 * For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
 * For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return the sum of these numbers.
 * The test cases are generated so that the answer fits in a 32-bits integer.
 *
 * Refer: 220111.cpp
 */

class Solution {
public:
	int sumRootToLeaf(TreeNode* root, int sum = 0) {
		if (!root)
			return 0;
		const int ans = (sum << 1) + root->val;
		if (!root->left && !root->right)
			return ans;
		return sumRootToLeaf(root->left, ans) + sumRootToLeaf(root->right, ans);
	}
};
