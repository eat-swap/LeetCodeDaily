#include <vector>
#include <queue>
#include <utility>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	explicit TreeNode(int x, TreeNode* left = nullptr, TreeNode* right = nullptr) : val(x), left(left), right(right) {}
};


class Solution {
public:
	std::vector<std::vector<int>> levelOrder(TreeNode* root) {
		if (!root)
			return {};
		std::vector<std::vector<int>> ret {{}};
		std::queue<std::pair<const TreeNode*, int>> q;
		q.push({root, 0});
		int cl = 0;
		while (!q.empty()) {
			const auto [v, l] = q.front();
			q.pop();
			if (l > cl) {
				++cl;
				ret.emplace_back();
			}
			ret.back().push_back(v->val);
			if (v->left)
				q.push({v->left, 1 + l});
			if (v->right)
				q.push({v->right, 1 + l});
		}
		return ret;
	}
};