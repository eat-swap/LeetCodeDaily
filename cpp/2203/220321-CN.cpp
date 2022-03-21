#include <functional>
#include <unordered_set>

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
 * 653. Two Sum IV - Input is a BST
 * Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.
 */

class Solution {
public:
	static bool findTarget(const TreeNode* root, int k) {
		if (!root) return false;
		std::unordered_multiset<int> s;
		std::function<void(const TreeNode*)> traverse = [&](const TreeNode* ptr) {
			s.insert(ptr->val);
			if (ptr->left) traverse(ptr->left);
			if (ptr->right) traverse(ptr->right);
		};
		traverse(root);
		for (int i : s)
			if (s.count(k - i) > (((i * 2) == k) ? 1 : 0))
				return true;
		return false;
	}
};
