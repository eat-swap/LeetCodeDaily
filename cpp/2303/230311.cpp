#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	explicit TreeNode(int x = 0, TreeNode* left = nullptr, TreeNode* right = nullptr) : val(x), left(left), right(right) {}
};

struct ListNode {
	int val;
	ListNode* next;

	explicit ListNode(int x = 0, ListNode* next = nullptr) : val(x), next(next) {}
};

ListNode* construct(int x) {
	return new ListNode(x);
}

template<typename... Ts>
ListNode* construct(int x, Ts... xs) {
	return new ListNode(x, construct(xs...));
}

/**
 * 109. Convert Sorted List to Binary Search Tree
 *
 * Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height-balanced binary search tree.
 */

class Solution {
private:
	static TreeNode* helper(const std::vector<int>& v, int s, int e) {
		switch (e - s) {
			case 1:
				return new TreeNode(v[s]);
			case 2:
				return new TreeNode(v[s + 1], new TreeNode(v[s]), nullptr);
		}
		int mid = (s + e) >> 1;
		return new TreeNode(
			v[mid],
			helper(v, s, mid),
			helper(v, mid + 1, e)
		);
	}

public:
	static TreeNode* sortedListToBST(ListNode* head) {
		if (!head)
			return nullptr;
		std::vector<int> v;
		for (const ListNode* ptr = head; ptr; ptr = ptr->next)
			v.push_back(ptr->val);
		return helper(v, 0, v.size());
	}
};

int h(const TreeNode* r) {
	return r ? std::max(h(r->left), h(r->right)) + 1 : 0;
}

bool isBalanced(const TreeNode* r) {
	if (!r)
		return true;
	if (!isBalanced(r->left)) {
		std::printf("Not balanced: val = %d, L not balanced.\n", r->val);
		return false;
	} else if (!isBalanced(r->right)) {
		std::printf("Not balanced: val = %d, R not balanced.\n", r->val);
		return false;
	}
	int hl = h(r->left), hr = h(r->right);
	if (std::abs(hl - hr) > 1) {
		std::printf("Not balanced, val = %d, hl = %d, hr = %d\n", r->val, hl, hr);
		return false;
	}
	return true;
}

std::string to_string(const TreeNode* r) {
	if (!r)
		return "[]";
	return std::string("[") + std::to_string(r->val) + to_string(r->left) + to_string(r->right) + "]";
}

int main() {
	ListNode* h = construct(-10, -3, 0, 5, 9, 10, 12, 14, 666, 3344);
	TreeNode* r = Solution::sortedListToBST(h);
	std::printf("%s\n", to_string(r).c_str());
	std::printf("Is balanced: %s\n", isBalanced(r) ? "true" : "false");
	return 0;
}
