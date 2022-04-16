#include <functional>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	explicit TreeNode(int x, TreeNode* left = nullptr, TreeNode* right = nullptr) : val(x), left(left), right(right) {}
};

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
