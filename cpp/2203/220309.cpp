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
 * 82. Remove Duplicates from Sorted List II
 * Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.
 */

class Solution {
public:
	static ListNode* deleteDuplicates(ListNode* head) {
		ListNode ret(0, head);
		ListNode* prev = &ret;
		ListNode* ptr = head;
		while (ptr) {
			if (ptr->next && ptr->next->val == ptr->val) {
				while (ptr && ptr->next && ptr->next->val == ptr->val)
					ptr = ptr->next;
				if (!ptr || !ptr->next) {
					prev->next = nullptr;
					return ret.next;
				}
				prev->next = ptr->next;
			} else {
			//	prev->next = ptr;
				prev = ptr;
			}
			ptr = ptr->next;
		}
		return ret.next;
	}
};

int main() {
	ListNode* h = construct(1,1,1,2,2,3,3,3,3,3);
	ListNode* ret = Solution::deleteDuplicates(h);
	for (ListNode* ptr = ret; ptr; ptr = ptr->next)
		std::cout << ptr->val << std::endl;
	return 0;
}
