#include <queue>
#include <iostream>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x, TreeNode* left = nullptr, TreeNode* right = nullptr) : val(x), left(left), right(right) {}
};

class Solution2 {
private:
	inline static const int N = 10005;
public:
	static int maxDepth(TreeNode* root) {
		if (!root)
			return 0;

		auto** ptrQueue = new TreeNode*[N]{root};
		auto* intQueue = new int[N]{1};
		int front = 0, rear = 1;

		int ret;
		while (front < rear) {
			ret = intQueue[front];

			if (ptrQueue[front]->left) {
				ptrQueue[rear] = ptrQueue[front]->left;
				intQueue[rear] = 1 + ret;
				++rear;
			}
			if (ptrQueue[front]->right) {
				ptrQueue[rear] = ptrQueue[front]->right;
				intQueue[rear] = 1 + ret;
				++rear;
			}
			++front;
		}

		delete[] ptrQueue;
		delete[] intQueue;
		return ret;
	}
};

class Solution {
public:
	static int maxDepth(const TreeNode* const root) {
		if (!root)
			return 0;

		std::queue<std::pair<const TreeNode* const, int>> q;
		q.push({root, 1});

		int ret;
		while (!q.empty()) {
			const auto t = q.front();
			q.pop();

			ret = t.second;

			if (t.first->left)
				q.push({t.first->left, t.second + 1});
			if (t.first->right)
				q.push({t.first->right, t.second + 1});
		}

		return ret;
	}
};

int main() {
	return 0;
}
