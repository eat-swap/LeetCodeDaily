#include <functional>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	explicit TreeNode(int x, TreeNode* left = nullptr, TreeNode* right = nullptr) : val(x), left(left), right(right) {}
};

/**
 * 538. Convert BST to Greater Tree
 * Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.
 * As a reminder, a binary search tree is a tree that satisfies these constraints:
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
 */

class Solution {
public:
	static TreeNode* convertBST(TreeNode* root) {
		if (!root)
			return nullptr;
		int x = 0;
		std::function<void(TreeNode*)> reversedInOrderTraverse = [&](TreeNode* r) {
			if (r->right)
				reversedInOrderTraverse(r->right);
			r->val = (x += r->val);
			if (r->left)
				reversedInOrderTraverse(r->left);
		};
		reversedInOrderTraverse(root);
		return root;
	}
};
