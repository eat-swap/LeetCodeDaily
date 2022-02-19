#include <cstdio>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	explicit ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	~ListNode() { delete this->next; }
};

class Solution {
public:
	static ListNode* middleNode(const ListNode* const head) {
		const auto* fast = head;
		const auto* slow = fast;
		while (fast && fast->next) {
			fast = fast->next->next;
			slow = slow->next;
		}
		return const_cast<ListNode*>(slow);
	}
};

int main() {
	auto* H = new ListNode(1);
	auto* ptr = H;
	for (int i = 2; i <= 6; ++i) {
		ptr->next = new ListNode(i);
		ptr = ptr->next;
	}
	for (const auto* M = Solution::middleNode(H); M; M = M->next)
		std::printf("%d\n", M->val);
	delete H;
}