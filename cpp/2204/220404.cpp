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
