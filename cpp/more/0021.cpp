#include <cstdio>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	ListNode* next;

	explicit ListNode(int x = 0, ListNode* next = nullptr) : val(x), next(next) {}
};

/**
 * 21. Merge Two Sorted Lists
 * You are given the heads of two sorted linked lists list1 and list2.
 * Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
 * Return the head of the merged linked list.
 */

class Solution {
public:
	static ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode node;
		ListNode* ptr = &node;
		while (list1 && list2) {
			if (list1->val < list2->val) {
				list1 = (ptr->next = list1)->next;
			} else {
				list2 = (ptr->next = list2) ->next;
			}
			ptr = ptr->next;
		}
		ptr->next = list1 ? list1 : list2;
		return node.next;
	}
};

ListNode* construct(int x) {
	return new ListNode(x);
}

template<typename... Ts>
ListNode* construct(int x, Ts... xs) {
	return new ListNode(x, construct(xs...));
}

int main() {
	ListNode* list1 = construct(1, 2, 4);
	ListNode* list2 = construct(1, 3, 4);
	ListNode* head = Solution::mergeTwoLists(list1, list2);
	for (ListNode* ptr = head; ptr; ptr = ptr->next) {
		std::printf("%d ", ptr->val);
	}
	return 0;
}
