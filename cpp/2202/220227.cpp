#include <queue>
#include <tuple>
#include <bitset>

/**
 * Definition for a binary tree node.
 */

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	explicit TreeNode(int x = 0, TreeNode* left = nullptr, TreeNode* right = nullptr) : val(x), left(left), right(right) {}
};

/**
 * 662. Maximum Width of Binary Tree
 * Given the root of a binary tree, return the maximum width of the given tree.
 * The maximum width of a tree is the maximum width among all levels.
 * The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes are also counted into the length calculation.
 * It is guaranteed that the answer will in the range of 32-bit signed integer.
 *
 * Warning: This solution is INCORRECT to some extent.
 * Consider such a extreme situation:
 * The depth of the provided tree is EQUAL to the number of nodes, and all the nodes have only right child.
 * Therefore the integer used to represent position have to possess up to 3000 (== n) bits, where we have to
 * consider something like bitset and operate subtract operations on binary digits by hand.
 * Type `int` is not enough to pass all the test cases, but `unsigned long long` does.
 *
 * However, to be RIGOROUS and CORRECT, using `unsigned long long` is a BAD idea.
 */

class Solution {
public:
	static int widthOfBinaryTree(const TreeNode* root) {
		if (!root)
			return 0;

		// Node, position, level
		std::queue<std::tuple<const TreeNode*, unsigned long long, unsigned long long>> q;
		q.push({root, 0, 1});

		unsigned long long currentLevel = 0, minPos = 0, maxPos = 0, ret = 1;
		while (!q.empty()) {
			const auto info = q.front();
			q.pop();
			const TreeNode* node = std::get<0>(info);
			const unsigned long long pos = std::get<1>(info), level = std::get<2>(info);

			if (level > currentLevel) {
				ret = std::max(ret, maxPos - minPos + 1);
				maxPos = minPos = pos;
				currentLevel = level;
			}

			maxPos = std::max(maxPos, pos);
			minPos = std::min(minPos, pos);

			if (node->left)
				q.push({node->left, pos << 1, 1 + level});
			if (node->right)
				q.push({node->right, 1 | (pos << 1), 1 + level});
		}

		return std::max(ret, maxPos - minPos + 1);
	}
};

int main() {
	return 0;
}
