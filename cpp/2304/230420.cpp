#include <algorithm>
#include <queue>
#include <tuple>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	explicit TreeNode(int x, TreeNode* left = nullptr, TreeNode* right = nullptr) : val(x), left(left), right(right) {}
};

/**
 * 662. Maximum Width of Binary Tree
 *
 * Given the root of a binary tree, return the maximum width of the given tree.
 * The maximum width of a tree is the maximum width among all levels.
 * The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.
 * It is guaranteed that the answer will in the range of a 32-bit signed integer.
 */

class Solution {
public:
	static int widthOfBinaryTree(const TreeNode* root);
};

int Solution::widthOfBinaryTree(const TreeNode* root) {
	std::queue<std::tuple<const TreeNode*, int, unsigned long long>> q;
	q.emplace(root, 0, 1);
	int curLevel = -1;
	std::pair<unsigned long long, unsigned long long> ans = {0, 0};
	unsigned long long ret = 1;
	while (!q.empty()) {
		auto [node, level, id] = q.front();
		q.pop();
		if (curLevel != level) {
			curLevel = level;
			ret = std::max(ans.second - ans.first + 1, ret);
			ans = {id, id};
		}
		ans.first = std::min(id, ans.first);
		ans.second = std::max(id, ans.second);
		if (node->left)
			q.emplace(node->left, 1 + level, id << 1);
		if (node->right)
			q.emplace(node->right, 1 + level, 1 | (id << 1));
	}
	return std::max(ret, ans.second - ans.first + 1);
}

int main() {
	;
}
