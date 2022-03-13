#include <vector>
#include <unordered_map>

class Node {
public:
	int val;
	Node* next;
	Node* random;

	explicit Node(int _val = 0, Node* _next = nullptr, Node* _random = nullptr) : val(_val), next(_next), random(_random) {}
};

/**
 * 138. Copy List with Random Pointer
 * A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.
 * Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.
 * For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.
 * Return the head of the copied linked list.
 * The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:
 *
 * val: an integer representing Node.val
 * random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
 * Your code will only be given the head of the original linked list.
 */

class Solution {
public:
	static Node* copyRandomList(Node* head) {
		std::vector<int> values;
		std::unordered_map<Node*, Node*> ptrRandom;
		std::unordered_map<Node*, std::size_t> ptrIndex;
		std::unordered_map<std::size_t, Node*> indexPtr;

		for (auto* ptr = head; ptr; ptr = ptr->next) {
			indexPtr[ptrIndex[ptr] = values.size()] = ptr;
			values.push_back(ptr->val);
			ptrRandom[ptr] = ptr->random;
		}

		auto n = values.size();
		Node ret(0);
		Node* ptr = &ret;
		std::vector<Node*> newPointers(n);
		for (int i = 0; i < n; ++i)
			newPointers[i] = ptr = ptr->next = new Node(values[i]);
		for (int i = 0; i < n; ++i)
			newPointers[i]->random = ptrRandom[indexPtr[i]] ? newPointers[ptrIndex[ptrRandom[indexPtr[i]]]] : nullptr;

		return ret.next;
	}
};
