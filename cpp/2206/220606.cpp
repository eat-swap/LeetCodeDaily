#include <unordered_set>

struct ListNode {
	int val;
	ListNode* next;

	explicit ListNode(int x, ListNode* n = nullptr) : val(x), next(n) {}

	~ListNode() {
		delete this->next;
		this->next = nullptr;
	}
};

/**
 * 160. Intersection of Two Linked Lists
 * Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
 */

class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		std::unordered_set<ListNode*> s;
		for (auto* ptr = headA; ptr; ptr = ptr->next)
			s.insert(ptr);
		for (auto* ptr = headB; ptr; ptr = ptr->next)
			if (s.count(ptr))
				return ptr;
		return nullptr;
	}
};
