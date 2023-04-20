#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <utility>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	explicit TreeNode(int x, TreeNode* left = nullptr, TreeNode* right = nullptr) : val(x), left(left), right(right) {}
};

/**
 * 1372. Longest ZigZag Path in a Binary Tree
 *
 * You are given the root of a binary tree.
 *
 * A ZigZag path for a binary tree is defined as follow:
 *
 * Choose any node in the binary tree and a direction (right or left).
 * If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
 * Change the direction from right to left or from left to right.
 * Repeat the second and third steps until you can't move in the tree.
 * Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).
 *
 * Return the longest ZigZag path contained in that tree.
 */

class Solution {
private:
	std::pair<int, int> f(TreeNode* r) noexcept;

	std::unordered_map<TreeNode*, std::pair<int, int>> m;

public:
	int longestZigZag(TreeNode* root) noexcept;
};

int Solution::longestZigZag(TreeNode* root) noexcept {
	f(root);
	return std::transform_reduce(m.begin(), m.end(), 0, [](int x, int y) { return std::max(x, y); }, [](auto&& x) {
		return std::max(x.second.first, x.second.second);
	});
}

std::pair<int, int> Solution::f(TreeNode* r) noexcept {
	if (m.count(r))
		return m[r];
	return m[r] = {
		r->left ? f(r->left).second + 1 : 0,
		r->right ? f(r->right).first + 1 : 0
	};
}

int main() {
	return 0;
}
