#include <iostream>

/**
 * Definition for singly-linked list.
 */
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
 * 24. Swap Nodes in Pairs
 * Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
 */

class Solution {
public:
	static ListNode* swapPairs(ListNode* head) {
		ListNode ret(0, head);
		auto* ptr = &ret;
		while (ptr) {
			ListNode* ptrN = ptr->next;
			if (!ptrN)
				break;

			ListNode* ptrNN = ptrN->next;
			if (!ptrNN)
				break;

			// ptr --> ptrN --> ptrNN --> ptrNNN
			// ListNode* ptrNNN = ptrNN->next;

			// ptr is previous node
			// swap ptrN and ptrNN.
			(ptr = ((ptr->next = ptrNN)->next = ptrN))->next = ptrNN->next;

			// ptr --> ptrNN --> ptrN --> ptrNNN
			// ptr = ptrN;
		}
		return ret.next;
	}
};

int main() {
	auto* head = construct(1, 2, 3, 4, 5, 6);
	head = Solution::swapPairs(head);
	for (auto* ptr = head; ptr; ptr = ptr->next) {
		std::printf("%d ", ptr->val);
	}
	return 0;
}
