#include <cstdio>

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	explicit Node(int _val = 0, Node* _left = nullptr, Node* _right = nullptr, Node* _next = nullptr) : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
	static Node* connect(Node* root) {
		if (!root)
			return nullptr;

		Node* qNode[6144] = {root};
		int qLevel[6144] = {0};
		int front = 0, rear = 1;

		while (rear > front) {
			Node* n = qNode[front];
			int level = qLevel[front];
			++front;

			if (rear > front && level == qLevel[front]) {
				n->next = qNode[front];
			}

			if (n->left) {
				qNode[rear] = n->left;
				qLevel[rear] = 1 + level;
				++rear;
			}

			if (n->right) {
				qNode[rear] = n->right;
				qLevel[rear] = 1 + level;
				++rear;
			}
		}

		return root;
	}
};

int main() {
	auto* r = new Node(1, new Node(2, new Node(4), new Node(5)), new Node(3, nullptr, new Node(7)));
	auto h = Solution::connect(r);
	return 0;
}
