#include <bitset>
#include <vector>
#include <stack>

/**
 * 946. Validate Stack Sequences
 *
 * Given two integer arrays pushed and popped each with distinct values, return true if this could have been the result of a sequence of push and pop operations on an initially empty stack, or false otherwise.
 */

class Solution {
public:
	static bool validateStackSequences(const std::vector<int>&, const std::vector<int>&);
};

bool Solution::validateStackSequences(const std::vector<int>& i, const std::vector<int>& o) {
	std::bitset<1024> pushed;
	std::stack<int> s;
	const int n = i.size();
	for (int pi = 0, po = 0; po < n; ++po, s.pop()) {
		for (; !pushed[o[po]]; pushed[i[pi++]] = true)
			s.push(i[pi]);
		if (s.empty() || s.top() != o[po])
			return false;
	}
	return s.empty();
}

int main() {
	Solution::validateStackSequences({1,2,3,4,5},{4,3,5,1,2});
	return 0;
}
