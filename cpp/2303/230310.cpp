#include <cstdlib>
#include <ctime>
#include <vector>

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
 * 382. Linked List Random Node
 * Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.
 *
 * Implement the Solution class:
 *
 * Solution(ListNode head) Initializes the object with the head of the singly-linked list head.
 * int getRandom() Chooses a node randomly from the list and returns its value. All the nodes of the list should be equally likely to be chosen.
 */

class Solution {
private:
	std::vector<short> s;

public:
	explicit Solution(ListNode* head) {
		for (auto* ptr = head; ptr; ptr = ptr->next)
			s.push_back(ptr->val);
		std::srand(std::time(nullptr));
	}

	int getRandom() const {
		int r = rand();
		for (; r >= RAND_MAX / s.size() * s.size(); r = rand());
		return s[r % s.size()];
	}
};
