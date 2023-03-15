#include <queue>
#include <utility>
#include <iostream>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	explicit TreeNode(int x, TreeNode* left = nullptr, TreeNode* right = nullptr) : val(x), left(left), right(right) {}
};

/**
 * 958. Check Completeness of a Binary Tree
 *
 * Given the root of a binary tree, determine if it is a complete binary tree.
 * In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
 */

class Solution {
public:
	static bool isCompleteTree(const TreeNode* r) {
		std::queue<std::pair<int, const TreeNode*>> q;
		q.emplace(1, r);
		for (int c = 1; !q.empty(); ++c) {
			const auto [v, p] = q.front();
			q.pop();
			if (v != c)
				return false;
			if (p->left) {
				q.emplace(v << 1, p->left);
				if (p->right)
					q.emplace(v << 1 | 1, p->right);
			} else if (p->right) return false;
		}
		return true;
	}
};

int main() {
	auto* t = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3, nullptr, new TreeNode(6)));
	std::cout << Solution::isCompleteTree(t);
	return 0;
}
