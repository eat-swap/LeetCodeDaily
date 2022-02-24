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


/**
 * 133. Clone Graph
 * Given a reference of a node in a connected undirected graph.
 * Return a deep copy (clone) of the graph.
 * Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

 * [ Definition of `Node` is shown above. ]

 * Test case format:
 * For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.
 * An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.
 * The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.
 */

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
