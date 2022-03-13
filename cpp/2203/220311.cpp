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
 * 61. Rotate List
 * Given the head of a linked list, rotate the list to the right by k places.
 */

class Solution {
public:
    static ListNode* rotateRight(ListNode* head, int k) {
		if (!head || !head->next)
			return head;

        int n = 0;
		for (auto* ptr = head; ptr; ptr = ptr->next)
			++n;
		int adv = (n - (k % n)) % n;

		auto* ptr = head;
		for (int i = 0; i < adv; ++i)
			ptr = ptr->next;
		auto* ptr2 = ptr;
		while (ptr2->next)
			ptr2 = ptr2->next;
		ptr2->next = head;
		for (auto* ptr3 = head;; ptr3 = ptr3->next) {
			if (ptr3->next == ptr) {
				ptr3->next = nullptr;
				break;
			}
		}
		return ptr;
    }
};

int main() {
	auto* head = construct(1,2);
	head = Solution::rotateRight(head, 0);
	for (auto* ptr = head; ptr; ptr = ptr->next)
		std::cout << ptr->val << " ";
	return 0;
}
