#include <queue>
#include <vector>
#include <iostream>

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

struct cmp {
	bool operator()(const ListNode* x, const ListNode* y) {
		return x && (!y || x->val > y->val);
	}
};

/**
 * 23. Merge k Sorted Lists
 *
 * You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
 * Merge all the linked-lists into one sorted linked-list and return it.
 */

class Solution {
public:
	static ListNode* mergeKLists(const std::vector<ListNode*>& lists) {
		if (lists.empty())
			return nullptr;
		std::priority_queue<ListNode*, std::vector<ListNode*>, cmp> q(lists.begin(), lists.end());
		ListNode* ptr = new ListNode(0), * head = ptr;
		for (; !q.empty() && !q.top(); q.pop());
		while (!q.empty()) {
			ListNode* p = q.top();
			q.pop();
			ptr = ptr->next = new ListNode(p->val);
			if (p->next)
				q.push(p->next);
		}
		return head->next;
	}
};

int main() {
	ListNode* h = Solution::mergeKLists({
		construct(1, 4, 5),
		nullptr,
		construct(1, 3, 4),
		construct(2, 6),
		nullptr,
		nullptr
	});
	for (ListNode* ptr = h; ptr; ptr = ptr->next)
		std::cout << ptr->val << "\n";
	return 0;
}
