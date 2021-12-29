#include <iostream>
#include <queue>

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    explicit Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
	static Node* connect(Node* root) {
		Node* queue[1 << 12] {root};
		for (int front = 0, rear = 1; front < rear && queue[front]; ++front) {
			if (!(front + 1 & front + 2))
				queue[front]->next = nullptr;
			else
				queue[front]->next = queue[1 + front];
			if (queue[front]->left)
				queue[rear++] = queue[front]->left;
			if (queue[front]->right)
				queue[rear++] = queue[front]->right;
		}
		return root;
	}
};

void printTree(const Node* const root) {
	std::queue<const Node*> q;
	q.push(root);
	while (!q.empty()) {
		const auto* const t = q.front();
		q.pop();
		printf("V->%d ", t->val);
		if (t->left) {
			printf("L->%d ", t->left->val);
			q.push(t->left);
		}
		if (t->right) {
			printf("R->%d ", t->right->val);
			q.push(t->right);
		}
		if (t->next)
			printf("N->%d", t->next->val);
		printf("\n");
	}
}

int main() {
	Node r(1);
	std::queue<Node*> q;
	q.push(&r);
	while (!q.empty()) {
		auto* const t = q.front();
		q.pop();
		if (t->val < 16) {
			q.push(t->left = new Node(t->val << 1));
			q.push(t->right = new Node((t->val << 1) + 1));
		}
	}
	Solution::connect(&r);
	printTree(&r);
	return 0;
}