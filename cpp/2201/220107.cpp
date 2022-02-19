#include <random>
#include <iostream>
#include <ctime>

/**
 * 382. Linked List Random Node
 * Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.
 * Implement the Solution class:
 * Solution(ListNode head) Initializes the object with the integer array nums.
 * int getRandom() Chooses a node randomly from the list and returns its value. All the nodes of the list should be equally likely to be choosen.
 */

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
	~ListNode() { delete this->next; }
};

class Solution {
private:
	inline static std::mt19937 r = std::mt19937(std::time(nullptr));
	int nums[10005]{};
	int n = 0;
public:
	explicit Solution(ListNode* head) {
		do {
			nums[n++] = head->val;
		} while (head = head->next);
	}

	int getRandom() {
		return nums[r() % n];
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
int main() {
	auto* head = new ListNode(1, new ListNode(2, new ListNode(3)));
	auto* instance = new Solution(head);
	std::cout << instance->getRandom() << std::endl;
	std::cout << instance->getRandom() << std::endl;
	std::cout << instance->getRandom() << std::endl;
	return 0;
}