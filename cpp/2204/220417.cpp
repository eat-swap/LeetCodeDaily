#include <functional>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	explicit TreeNode(int x = 0, TreeNode* l = nullptr, TreeNode* r = nullptr) : val(x), left(l), right(r) {}
};

class Solution {
public:
	static TreeNode* increasingBST(TreeNode* root, TreeNode* greater = nullptr) {
		if (!root)
			return nullptr;
		root->right = root->right ? increasingBST(root->right, greater) : greater;
		if (!root->left)
			return root;
		auto* rl = root->left;
		root->left = nullptr;
		return increasingBST(rl, root);
	}
};

int main() {
	auto* root = new TreeNode(
		5,
		new TreeNode(3, new TreeNode(2, new TreeNode(1)), new TreeNode(4)),
		new TreeNode(6, nullptr, new TreeNode(8, new TreeNode(7), new TreeNode(9)))
	);

	auto* newRoot = Solution::increasingBST(root);

	return 0;
}
