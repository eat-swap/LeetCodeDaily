#include <queue>
#include <iostream>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x = 0, ListNode* next = nullptr) : val(x), next(next) {}
	~ListNode() { delete this->next; }
};

struct NodeCompare {
	bool operator()(const ListNode* const x, const ListNode* const y) const {
		return x->val > y->val;
	}
};

class Solution {
public:
	static ListNode* mergeKLists(const std::vector<ListNode*>& lists) {
		std::priority_queue<ListNode*, std::vector<ListNode*>, NodeCompare> q;
		for (ListNode* const& ptr : lists) {
			if (ptr)
				q.push(ptr);
		}
		if (q.empty())
			return nullptr;
		ListNode* const head = q.top();
		ListNode* tail = head;
		if (head->next)
			q.push(head->next);
		q.pop();
		while (!q.empty()) {
			ListNode* const t = q.top();
			q.pop();
			if (t->next)
				q.push(t->next);
			tail->next = t;
			tail = t;
		}
		return head;
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
	std::vector<ListNode*> args {construct(1, 4, 5), construct(1, 3, 4), construct(2, 6)};
	ListNode* ret = Solution::mergeKLists(args);
	for (ListNode* ptr = ret; ptr; ptr = ptr->next) {
		std::cout << ptr->val << ' ';
	}
	return 0;
}
