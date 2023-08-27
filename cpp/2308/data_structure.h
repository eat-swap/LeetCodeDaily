#ifndef LEETCODE_CPP_DATA_STRUCTURE_H
#define LEETCODE_CPP_DATA_STRUCTURE_H

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

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	explicit TreeNode(int x, TreeNode* left = nullptr, TreeNode* right = nullptr) : val(x), left(left), right(right) {}
};

#endif //LEETCODE_CPP_DATA_STRUCTURE_H
