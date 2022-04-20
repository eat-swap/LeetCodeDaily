#include <stack>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	explicit TreeNode(int x = 0, TreeNode* l = nullptr, TreeNode* r = nullptr) : val(x), left(l), right(r) {}
};

/**
 * 173. Binary Search Tree Iterator
 * Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):
 * BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
 * boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
 * int next() Moves the pointer to the right, then returns the number at the pointer.
 * Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.
 * You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.
 */

class BSTIterator {
private:
	std::stack<const TreeNode*> s;

public:
	explicit BSTIterator(const TreeNode* root) {
		for (; root; root = root->left)
			s.push(root);
	}

	int next() {
		if (s.empty())
			return -1;
		const TreeNode* ret = s.top();
		s.pop();
		if (ret->right)
			for (const TreeNode* ptr = ret->right; ptr; ptr = ptr->left)
				s.push(ptr);
		return ret->val;
	}

	bool hasNext() {
		return !s.empty();
	}
};

int main() {
	int x;
	bool b;
	BSTIterator bSTIterator = BSTIterator(new TreeNode(7, new TreeNode(3), new TreeNode(15, new TreeNode(9), new TreeNode(20))));
	x = bSTIterator.next();    // return 3
	x = bSTIterator.next();    // return 7
	b = bSTIterator.hasNext(); // return True
	x = bSTIterator.next();    // return 9
	b = bSTIterator.hasNext(); // return True
	x = bSTIterator.next();    // return 15
	b = bSTIterator.hasNext(); // return True
	x = bSTIterator.next();    // return 20
	b = bSTIterator.hasNext(); // return False
}
