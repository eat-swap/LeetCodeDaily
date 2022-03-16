#include <stack>
#include <vector>
#include <unordered_map>
#include <iostream>

class Solution {
public:
	static bool validateStackSequences(const std::vector<int>& pushed, const std::vector<int>& popped) {
		const int n = pushed.size();

		std::unordered_map<int, int> m;
		for (int i = 0; i < n; ++i)
			m[pushed[i]] = i;

		std::vector<int> processed(n);
		for (int i = 0; i < n; ++i)
			processed[i] = m[popped[i]];

		int currentPushed = -1;
		std::stack<int> s;
		for (int i = 0; i < n; ++i) {
			if (processed[i] > currentPushed) {
				// == Push to current, and pop current immediately
				for (++currentPushed; currentPushed < processed[i]; ++currentPushed) {
					s.push(currentPushed);
				}
			} else {
				if (s.empty() || s.top() != processed[i])
					return false;
				s.pop();
			}
		}
		return true;
	}
};

int main() {
	std::cout << Solution::validateStackSequences({1,2,3,4,5}, {1,2,3,4,5});
	return 0;
}
