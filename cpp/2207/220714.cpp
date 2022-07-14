#include <vector>
#include <algorithm>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	explicit TreeNode(int x, TreeNode* left = nullptr, TreeNode* right = nullptr) : val(x), left(left), right(right) {}
};

/**
 * 105. Construct Binary Tree from Preorder and Inorder Traversal
 * Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
 */

class Solution {
private:
	TreeNode* buildTree(std::vector<int>::const_iterator preBegin, std::vector<int>::const_iterator preEnd, std::vector<int>::const_iterator inBegin, std::vector<int>::const_iterator inEnd) {
		if (preBegin == preEnd)
			return nullptr;
		if (std::next(preBegin) == preEnd)
			return new TreeNode(*preBegin);
		auto midIt = std::find(inBegin, inEnd, *preBegin);
		auto lenL = std::distance(inBegin, midIt);
		return new TreeNode(
			*preBegin,
			buildTree(preBegin + 1, preBegin + 1 + lenL, inBegin, midIt),
			buildTree(preBegin + 1 + lenL, preEnd, midIt + 1, inEnd)
		);
	}

public:
	TreeNode* buildTree(const std::vector<int>& preorder, const std::vector<int>& inorder) {
		return buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
	}
};