#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <iostream>

class Solution {
public:
	static std::string longestWord(const std::vector<std::string>& words) {
		std::unordered_set<std::string> s(words.begin(), words.end());
		std::string ans = "";
		int ansLen = 0;

		std::queue<std::string> q;
		q.push("");
		while (!q.empty()) {
			std::string x = q.front();
			q.pop();
			int xLen = x.length();
			for (char c = 'a'; c <= 'z'; ++c) {
				std::string nx = x + c;
				if (s.count(nx)) {
					if (nx.length() > ansLen) {
						ans = nx;
						ansLen = nx.length();
					}
					q.push(nx);
				}
			}
		}

		return ans;
	}
};

int main() {
	std::cout << Solution::longestWord({"a","banana","app","appl","ap","apply","apple"});
	return 0;
}
