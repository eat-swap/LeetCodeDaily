#include <stack>
#include <vector>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	explicit TreeNode(int x = 0, TreeNode* l = nullptr, TreeNode* r = nullptr) : val(x), left(l), right(r) {}
};

/**
 * BSTIterator
 *
 * Copied from 220420.cpp
 * Refer: 173. Binary Search Tree BSTIterator
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

/**
 * PeekingBSTIterator
 *
 * Copied & modified from 220425.cpp [PeekingIterator]
 * Refer: 284. Peeking Iterator
 */

class PeekingBSTIterator : public BSTIterator {
private:
	int x = 0;
	bool isEmpty = false;

public:
	explicit PeekingBSTIterator(const TreeNode* nums) : BSTIterator(nums) {
		// Initialize any member here.
		// **DO NOT** save a copy of nums and manipulate it directly.
		// You should only use the BSTIterator interface methods.
		if (!BSTIterator::hasNext())
			isEmpty = true;
		else
			this->x = BSTIterator::next();
	}

	// Returns the next element in the iteration without advancing the BSTIterator.
	int peek() const {
		return x;
	}

	// hasNext() and next() should behave the same as in the BSTIterator interface.
	// Override them if needed.
	int next() {
		if (this->isEmpty)
			return -1;
		auto ret = this->x;

		if (BSTIterator::hasNext()) {
			this->x = BSTIterator::next();
		} else {
			this->isEmpty = true;
		}

		return ret;
	}

	bool hasNext() const {
		return !this->isEmpty;
	}
};

/**
 * 1305. All Elements in Two Binary Search Trees
 * Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.
 *
 * Alternative refer: 220126.cpp (100% STL implementation)
 */

class Solution {
public:
	static std::vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
		auto* it1 = new PeekingBSTIterator(root1);
		auto* it2 = new PeekingBSTIterator(root2);

		std::vector<int> ret;
		while (it1->hasNext() && it2->hasNext())
			ret.push_back((it1->peek() < it2->peek() ? it1 : it2)->next());
		while (it1->hasNext())
			ret.push_back(it1->next());
		while (it2->hasNext())
			ret.push_back(it2->next());

		return ret;
	}
};