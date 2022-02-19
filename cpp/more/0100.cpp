/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x = 0, TreeNode* left = nullptr, TreeNode* right = nullptr) : val(x), left(left), right(right) {}
};

/**
 * 100. Same Tree
 * Given the roots of two binary trees p and q, write a function to check if they are the same or not.
 * Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
 */

class Solution {
public:
	static bool isSameTree(const TreeNode* const p, const TreeNode* const q) {
		return (p == q) || (p && q && p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
	}
};

int main() {
	// No code for testing
	return 0;
}