#include <cassert>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>

/**
 * Definition for a Node.
 */
class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    explicit Node(int v = 0, std::vector<Node*> arr = std::vector<Node*>()) : val(v), neighbors(std::move(arr)) {}
};


class Solution {
public:
	static Node* cloneGraph(const Node* const node) {
		if (!node)
			return nullptr;

		const Node* original[101]{};
		std::unordered_map<const Node*, int> m;
		Node* pool[101]{};

		std::queue<const Node*> q;
		q.push(original[node->val] = node);
		while (!q.empty()) {
			const Node* t = q.front();
			q.pop();

			for (const Node* nx : t->neighbors) {
				m[nx] = nx->val;
				if (!original[nx->val]) {
					q.push(original[nx->val] = nx);
			//		m[nx] = nx->val;
				}
			}
		}

		for (int i = 0; i < 101; ++i)
			if (original[i])
				pool[i] = new Node(i);
		for (int i = 0; i < 101; ++i) {
			if (original[i]) {
				for (const Node* ptr : original[i]->neighbors) {
					assert(pool[m[ptr]]);
					pool[i]->neighbors.push_back(pool[m[ptr]]);
				}
			}
		}

		return pool[node->val];
	}
};

int main() {
	Node args[4];
	args[0] = Node(1, {args + 1, args + 3});
	args[1] = Node(2, {args, args + 2});
	args[2] = Node(3, {args + 1, args + 3});
	args[3] = Node(4, {args, args + 2});

	Solution::cloneGraph(args);

	return 0;
}
