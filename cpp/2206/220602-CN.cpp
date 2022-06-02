struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	explicit TreeNode(int x, TreeNode* left = nullptr, TreeNode* right = nullptr) : val(x), left(left), right(right) {}
};

/**
 * 450. Delete Node in a BST
 * Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.
 * Basically, the deletion can be divided into two stages:
 * 1. Search for a node to remove.
 * 2. If the node is found, delete the node.
 */

class Solution {
private:
	static TreeNode* mergeNode(TreeNode* L, TreeNode* R) {
		if (!L || !R)
			return (!L && !R) ? nullptr : (L ? L : R);
		if (!L->right) {
			L->right = R;
			return L;
		} else if (!R->left) {
			R->left = L;
			return R;
		}
		// Full
		TreeNode* ptrP = R, * ptr = R->left;
		while (ptr->left) {
			ptrP = ptr;
			ptr = ptr->left;
		}
		ptrP->left = ptr->right;
		ptr->left = L;
		ptr->right = R;
		return ptr;
	}

public:
	static TreeNode* deleteNode(TreeNode* root, int key) {
		if (!root)
			return nullptr;
		if (root->val == key)
			return mergeNode(root->left, root->right);
		if (key < root->val)
			root->left = deleteNode(root->left, key);
		else // root->val < key
			root->right = deleteNode(root->right, key);
		return root;
	}
};

int main() {
	Solution::deleteNode(
		new TreeNode(5, new TreeNode(3, new TreeNode(2), new TreeNode(4)), new TreeNode(6, nullptr, new TreeNode(7))),
		3
	);
	return 0;
}
