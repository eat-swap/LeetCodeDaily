#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	explicit TreeNode(int x, TreeNode* left = nullptr, TreeNode* right = nullptr) : val(x), left(left), right(right) {}
};

/**
 * 103. Binary Tree Zigzag Level Order Traversal
 *
 * Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
 */

class Solution {
public:
	static std::vector<std::vector<int>> zigzagLevelOrder(const TreeNode* root) {
		if (!root)
			return {};
		std::vector<std::vector<int>> ret {{}};
		std::queue<std::pair<const TreeNode*, int>> q;
		q.emplace(root, 0);
		for (int n = 0; !q.empty(); ) {
			const auto [ptr, lv] = q.front();
			q.pop();
			if (lv > n) {
				ret.emplace_back();
				++n;
			}
			ret.back().push_back(ptr->val);
			if (ptr->left)
				q.emplace(ptr->left, 1 + lv);
			if (ptr->right)
				q.emplace(ptr->right, 1 + lv);
		}
		for (int i = 1; i < ret.size(); i += 2)
			std::reverse(ret[i].begin(), ret[i].end());
		return ret;
	}
};
