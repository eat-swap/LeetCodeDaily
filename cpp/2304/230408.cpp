#include <bitset>
#include <queue>
#include <unordered_set>
#include <vector>

class Node {
public:
	int val;
	std::vector<Node*> neighbors;
	Node() {
		val = 0;
		neighbors = std::vector<Node*>();
	}
	explicit Node(int _val) {
		val = _val;
		neighbors = std::vector<Node*>();
	}
	Node(int _val, std::vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};

/**
 * 133. Clone Graph
 *
 * Given a reference of a node in a connected undirected graph.
 * Return a deep copy (clone) of the graph.
 * Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.
 */

class Solution {
public:
	static Node* cloneGraph(Node*);
};

Node* Solution::cloneGraph(Node* node) {
	if (!node)
		return nullptr;
	Node* s = new Node[102];
	std::bitset<102> vis;
	for (int i = 0; i < 102; ++i)
		s[i].val = i;
	std::queue<Node*> q;
	q.push(node);
	vis[node->val] = true;
	while (!q.empty()) {
		auto* ptr = q.front();
		q.pop();
		for (auto&& np : ptr->neighbors) {
			s[ptr->val].neighbors.push_back(s + np->val);
			if (!vis[np->val]) {
				vis[np->val] = true;
				q.push(np);
			}
		}
	}
	return s + node->val;
}
