#include <vector>
#include <queue>
#include <ostream>
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

/**
 * 1019. Next Greater Node In Linked List
 *
 * You are given the head of a linked list with n nodes.
 * For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.
 * Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0.
 */

class Solution {
public:
	template<typename T>
	using V = std::vector<T>;
	using VI = V<int>;
	using PII = std::pair<int, int>;

	static VI nextLargerNodes(const ListNode*);
};

Solution::VI Solution::nextLargerNodes(const ListNode* head) {
	VI ret;
	std::priority_queue<PII, V<PII>, std::greater<>> q;
	for (const ListNode* ptr = head; ptr; ptr = ptr->next) {
		q.emplace(ptr->val, ret.size());
		ret.push_back(0);
		for (; q.top().first < ptr->val; q.pop())
			ret[q.top().second] = ptr->val;
	}
	return ret;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> vec) {
	for (auto&& x : vec)
		os << x << std::endl;
	return os;
}

int main() {
	std::cout << Solution::nextLargerNodes(construct(2,7,4,3,5));
	return 0;
}
