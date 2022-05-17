struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int x = 0, TreeNode* l = nullptr, TreeNode* r = nullptr) : val(x), left(l), right(r) {}
};

/**
 * 1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree
 * Given two binary trees original and cloned and given a reference to a node target in the original tree.
 * The cloned tree is a copy of the original tree.
 * Return a reference to the same node in the cloned tree.
 * Note that you are not allowed to change any of the two trees or the target node and the answer must be a reference to a node in the cloned tree.
 */

class Solution {
private:
    template<typename T>
    static T* notNull(T* p1, T* p2) {
		return p1 ? p1 : p2;
	}

public:
    static TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
		if (!original || !cloned || !target)
			return nullptr;
		return original == target ? cloned : notNull(getTargetCopy(original->left, cloned->left, target), getTargetCopy(original->right, cloned->right, target));
	}
};