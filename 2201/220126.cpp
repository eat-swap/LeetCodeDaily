#include <vector>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	explicit TreeNode(int x = 0, TreeNode* left = nullptr, TreeNode* right = nullptr) : val(x), left(left), right(right) {}
};

class Solution {
private:
	static void dfs(const TreeNode* const root, std::vector<int>& ret) {
		if (root->left)
			dfs(root->left, ret);
		ret.push_back(root->val);
		if (root->right)
			dfs(root->right, ret);
	}
public:
	static std::vector<int> getAllElements(const TreeNode* const root1, const TreeNode* const root2) {
		std::vector<int> d1, d2, ret;
		if (root1)
			dfs(root1, d1);
		if (root2)
			dfs(root2, d2);
		std::merge(d1.begin(), d1.end(), d2.begin(), d2.end(), std::back_inserter(ret));
		return ret;
	}
};