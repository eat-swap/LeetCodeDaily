#include <vector>
#include <unordered_map>
#include <functional>
#include <iostream>
#include <tuple>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	explicit TreeNode(int x = 0, TreeNode* l = nullptr, TreeNode* r = nullptr) : val(x), left(l), right(r) {}
};

/**
 * This solution passed 161 of 171 test cases,
 * but why it did not work still remains unknown.
 * Further investigation is required.
 */

class Solution_Broken {
private:
	int dp[1005][3]{};

	int L[1005]{}, R[1005]{};

	std::unordered_map<const TreeNode*, int> m;

	int nodeCount = 0;

	int getNodeId(const TreeNode* n) {
		return (this->m.count(n)) ? m[n] : (m[n] = ++nodeCount);
	}

public:
	int minCameraCover(TreeNode* root) {
		if (!root)
			return 0;
		if (!root->left && !root->right)
			return 1;

		std::function<void(const TreeNode*)> traverse = [&](const TreeNode* n) {
			int idn = getNodeId(n);
			if (n->left) {
				L[idn] = getNodeId(n->left);
				traverse(n->left);
			}
			if (n->right) {
				R[idn] = getNodeId(n->right);
				traverse(n->right);
			}
		};
		traverse(root);

		/*
		 * type =
		 * 0 -> I hold a camera
		 * 1 -> My parent holds
		 * 2 -> Neither
		 */
		std::function<int(int, int)> d = [&](int idx, int type) {
			if (dp[idx][type])
				return dp[idx][type];

			int ret = 0;
			if (type == 2) {
				ret = 0x7FFFFFFF;
				if (L[idx])
					ret = std::min(ret, d(idx, 1) - d(L[idx], 2) + d(L[idx], 0));
				if (R[idx])
					ret = std::min(ret, d(idx, 1) - d(R[idx], 2) + d(R[idx], 0));
				ret = ret == 0x7FFFFFFF ? 1 : ret;
			} else if (type) { // == 1
				if (L[idx])
					ret += d(L[idx], 2);
				if (R[idx])
					ret += d(R[idx], 2);
			} else { // type == 0
				if (L[idx])
					ret += std::min(d(L[idx], 0), d(L[idx], 1));
				if (R[idx])
					ret += std::min(d(R[idx], 0), d(R[idx], 1));
				++ret;
			}

			return dp[idx][type] = ret;
		};

		return std::min(d(1, 0), d(1, 2));
	}
};

/**
 * 968. Binary Tree Cameras
 * You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.
 * Return the minimum number of cameras needed to monitor all nodes of the tree.
 */

class Solution {
public:
	static int minCameraCover(TreeNode* root) {
		std::function<std::tuple<int, int, int>(const TreeNode*)> s = [&](const TreeNode* n) {
			if (!n)
				return std::make_tuple(0, 0, 0x7FFFFFF);
			auto [L1, L2, L3] = s(n->left);
			auto [R1, R2, R3] = s(n->right);
			return std::make_tuple(L2 + R2, std::min(L3 + std::min(R2, R3), R3 + std::min(L2, L3)), 1 + std::min(L1, std::min(L2, L3)) + std::min(R1, std::min(R2, R3)));
		};
		auto [_, A1, A2] = s(root);
		return std::min(A1, A2);
	}
};

int main() {
	Solution s;
	std::cout << s.minCameraCover(new TreeNode(0, new TreeNode(0, new TreeNode(0, new TreeNode(0, new TreeNode(0))))));
	return 0;
}
