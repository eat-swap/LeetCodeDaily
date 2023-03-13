struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	explicit TreeNode(int x = 0, TreeNode* left = nullptr, TreeNode* right = nullptr) : val(x), left(left), right(right) {}
};

/**
 * 101. Symmetric Tree
 *
 * Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
 */

class Solution {
private:
	static bool helper(TreeNode* L, TreeNode* R) {
		if (!L && !R)
			return true;
		if (!L || !R)
			return false;
		return (L->val == R->val) && helper(L->right, R->left) && helper(L->left, R->right);
	}

public:
	static bool isSymmetric(TreeNode* r) {
		return !r || helper(r->left, r->right);
	}
};
