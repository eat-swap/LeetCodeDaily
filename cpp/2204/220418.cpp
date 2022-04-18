#include <functional>
#include <queue>
#include <vector>
#include <algorithm>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	explicit TreeNode(int x = 0, TreeNode* l = nullptr, TreeNode* r = nullptr) : val(x), left(l), right(r) {}
};

class Solution {
private:
	static int priorityQueue(TreeNode* root, int k) {
		std::vector<int> val;
		std::function<void(TreeNode*)> f = [&](TreeNode* ptr) {
			if (!ptr) return;
			val.push_back(ptr->val);
			if (ptr->left) f(ptr->left);
			if (ptr->right) f(ptr->right);
		};

		// O(n）
		f(root);

		// O(n)
		std::priority_queue<int, std::vector<int>, std::greater<>> q(val.begin(), val.end());

		// O(k * log(n))
		for (int i = 1; i < k; ++i)
			q.pop();
		return q.top();
	}
public:
	static int kthSmallest(TreeNode* root, int k) {
		return priorityQueue(root, k);
	}
};
