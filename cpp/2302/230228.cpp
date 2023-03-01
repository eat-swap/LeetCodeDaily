#include <vector>
#include <unordered_map>
#include <string>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	explicit TreeNode(int x = 0, TreeNode* left = nullptr, TreeNode* right = nullptr) : val(x), left(left), right(right) {}
};

/**
 * 652. Find Duplicate Subtrees
 *
 * Given the root of a binary tree, return all duplicate subtrees.
 * For each kind of duplicate subtrees, you only need to return the root node of any one of them.
 * Two trees are duplicate if they have the same structure with the same node values.
 */

class Solution {
private:
	std::unordered_map<std::string, TreeNode*> strToNode;
	std::unordered_map<std::string, int> strCnt;

	// Pre-order
	std::string toStr(TreeNode* r) {
		if (!r)
			return "";
		auto ret = std::to_string(r->val)
			.append("(")
			.append(toStr(r->left))
			.append(")(")
			.append(toStr(r->right))
			.append(")");
		strToNode[ret] = r;
		++strCnt[ret];
		return ret;
	}

public:
	std::vector<TreeNode*> findDuplicateSubtrees(TreeNode* r) {
		toStr(r);
		std::vector<TreeNode*> ret;
		for (const auto& [str, c] : strCnt) {
			if (c <= 1)
				continue;
			ret.push_back(strToNode[str]);
		}
		return ret;
	}
};

int main() {
	return 0;
}
