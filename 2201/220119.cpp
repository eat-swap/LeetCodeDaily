#include <iostream>
#include <cassert>

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
 * 142. Linked List Cycle II
 * Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
 * There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.
 * Do not modify the linked list.
 */

class Solution {
public:
	static ListNode* detectCycle(const ListNode* head) {
		if (!(head && head->next))
			return nullptr;
		const auto* fast = head->next->next;
		const auto* slow = head->next;
		for (; fast && fast->next && fast != slow; ) {
			fast = fast->next->next;
			slow = slow->next;
		}
		if (!(fast && fast->next))
			return nullptr;
		assert(fast == slow);
		int cycleLength = 1;
		for (fast = fast->next; fast != slow; ++cycleLength, (fast = fast->next));
		fast = slow = head;
		for (int i = 0; i < cycleLength; ++i)
			fast = fast->next;
		if (fast == slow) {
			for (int i = 1; i < cycleLength; ++i)
				fast = fast->next;
		} else {
			while (fast->next != slow->next) {
				fast = fast->next;
				slow = slow->next;
			}
		}
		return const_cast<ListNode*>(fast->next);
	}
};

int main() {
	auto* h = new ListNode(3, new ListNode(2, new ListNode(0, new ListNode(-4))));
	h->next->next->next->next = h->next;
	// auto* h = new ListNode(1 /*, new ListNode(2)*/ );
	// h->next->next = h;
	auto* ptr = h;
	for (int i = 0; i < 15 && ptr; ++i) {
		std::cout << ptr->val << ' ';
		ptr = ptr->next;
	}
	ptr = Solution::detectCycle(h);
	std::cout << std::endl;
	if (ptr)
		std::cout << ptr->val;
	else
		std::cout << "nullptr";
	delete h;
	return 0;
}
