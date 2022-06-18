struct Node {
	int val;
	Node* next;

	explicit Node(int val = 0, Node* next = nullptr) : val(val), next(next) {}
};

/**
 * 708. Insert into a Sorted Circular Linked List
 *
 * This is a premium problem.
 */

class Solution {
public:
	static Node* insert(Node* head, int insertVal) {
		if (!head) {
			auto* n = new Node(insertVal);
			return n->next = n;
		}

		int cnt = 0;
		for (Node* prev = head, * ptr = head->next; ptr != head || cnt++ < 2; (prev = ptr), (ptr = ptr->next)) {
			if (prev->val <= ptr->val && !(prev->val <= insertVal && insertVal <= ptr->val))
				continue;
			if ((prev->val > ptr->val && (insertVal < ptr->val || insertVal > prev->val)) || (prev->val <= insertVal && insertVal <= ptr->val)) {
				// Can insert
				prev->next = new Node(insertVal, ptr);
				return head;
			}
		}
		// Nowhere to insert.
		head->next = new Node(insertVal, head->next);
		return head;
	}
};

Node* construct(int x) {
	return new Node(x);
}

template<typename T, typename... Ts>
Node* construct(T x, Ts... args) {
	return new Node(x, construct(args...));
}

int main() {
	Node* list = construct(3, 4, 1);
	for (Node* ptr = list; ; ptr = ptr->next) {
		if (!ptr->next) {
			ptr->next = list;
			break;
		}
	}

	Solution::insert(list, 2);

	return 0;
}
