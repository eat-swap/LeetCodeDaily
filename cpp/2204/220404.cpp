#include <algorithm>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	ListNode* next;
	explicit ListNode(int x, ListNode* n = nullptr) : val(x), next(n) {}
	~ListNode() { delete this->next; this->next = nullptr; }
};

/**
 * 1721. Swapping Nodes in a Linked List
 * You are given the head of a linked list, and an integer k.
 * Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).
 */

class Solution {
public:
	static ListNode* swapNodes(ListNode* head, int k) {
		if (!head || !head->next) return head;
		auto* fast = head;
		for (int i = 1; i < k; ++i)
			fast = fast->next;
		auto* slow = head;
		auto* S1 = fast;
		while (fast->next) {
			fast = fast->next;
			slow = slow->next;
		}
		std::swap(slow->val, S1->val);
		return head;
	}
};
