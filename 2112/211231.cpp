#include <iostream>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	~TreeNode() { delete this->left; delete this->right; }
};

class Solution {
private:
	static int dfs(const TreeNode* const node, int L, int R) {
		int LDist = (L - node->val) >= 0 ? (L - node->val) : (node->val - L);
		int RDist = (R - node->val) >= 0 ? (R - node->val) : (node->val - R);
		int mid, ret = LDist > RDist ? LDist : RDist;
		int nL = L < node->val ? L : node->val, nR = R > node->val ? R : node->val;
		if (node->left) {
			mid = dfs(node->left, nL, nR);
			ret = ret > mid ? ret : mid;
		}
		if (node->right) {
			mid = dfs(node->right, nL, nR);
			ret = ret > mid ? ret : mid;
		}
		return ret;
	}
public:
	static int maxAncestorDiff(const TreeNode* const root) {
		return dfs(root, root->val, root->val);
	}
};

int main() {
	// TreeNode root(1, nullptr, new TreeNode(2, nullptr, new TreeNode(0, new TreeNode(3), nullptr)));
	TreeNode root(8, new TreeNode(3, new TreeNode(1), new TreeNode(6, new TreeNode(4), new TreeNode(7))), new TreeNode(10, nullptr, new TreeNode(14, new TreeNode(13), nullptr)));
	std::printf("%d\n", Solution::maxAncestorDiff(&root));
	return 0;
}
