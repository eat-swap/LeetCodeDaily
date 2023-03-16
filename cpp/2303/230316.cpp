#include <vector>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	explicit TreeNode(int x, TreeNode* left = nullptr, TreeNode* right = nullptr) : val(x), left(left), right(right) {}
};

/**
 * 106. Construct Binary Tree from Inorder and Postorder Traversal
 *
 * Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.
 */

using VCI = std::vector<int>::const_iterator;

class Solution {
private:
	static TreeNode* bT(VCI is, VCI ie, VCI ps, VCI pe) {
		if (is == ie || ps == pe)
			return nullptr;
		int r = *(pe - 1);
		int pos = std::find(is, ie, r) - is;
		return new TreeNode(
			r,
			bT(is, is + pos, ps, ps + pos),
			bT(is + pos + 1, ie, ps + pos, pe - 1)
		);
	}

public:
	static TreeNode* buildTree(const std::vector<int>& inorder, const std::vector<int>& postorder) {
		return bT(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
	}
};

int main() {
	Solution::buildTree({-1}, {-1});
	return 0;
}
