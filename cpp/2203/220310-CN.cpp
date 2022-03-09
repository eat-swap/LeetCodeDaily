#include <vector>
#include <functional>

// Definition for a Node.
class Node {
public:
    int val;
    std::vector<Node*> children;

    Node(int _val, std::vector<Node*> _children) : val(_val), children(std::move(_children)) {}
};

/**
 * 589. N-ary Tree Preorder Traversal
 * Given the root of an n-ary tree, return the preorder traversal of its nodes' values.
 * Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)
 */

class Solution {
public:
	static std::vector<int> preorder(Node* root) {
		std::vector<int> ret;
		std::function<void(const Node* const)> traverse = [&](const Node* const ptr) {
			if (!ptr) return;
			ret.push_back(ptr->val);
			for (const Node* const i : ptr->children)
				traverse(i);
		};
		traverse(root);
		return ret;
	}
};
