#include <functional>
#include <cstdio>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	explicit TreeNode(int x = 0, TreeNode* l = nullptr, TreeNode* r = nullptr) : val(x), left(l), right(r) {}
};

/**
 * 99. Recover Binary Search Tree
 * You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.
 */

class Solution {
public:
	static void recoverTree(TreeNode* root) {
		TreeNode* prev = nullptr, * x1 = nullptr, * x2 = nullptr;
		std::function<bool(TreeNode*)> traverse = [&](TreeNode* r) {
			if (!r)
				return false;
			if (r->left && traverse(r->left))
				return true;

			// Check if prevPrev < r
			if (prev && prev->val >= r->val) {
				x1 = r;
				if (!x2)
					x2 = prev;
				else
					return true;
			}
			prev = r;

			if (r->right)
				return traverse(r->right);
			return false;
		};
		traverse(root);
		std::swap(x1->val, x2->val);
	}
};

int main() {
	auto* root = new TreeNode(1, new TreeNode(3, nullptr, new TreeNode(2)));
	Solution::recoverTree(root);
	return 0;
}
