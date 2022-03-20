#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <iostream>

/**
 * 720. Longest Word in Dictionary
 * Given an array of strings words representing an English Dictionary, return the longest word in words that can be built one character at a time by other words in words.
 * If there is more than one possible answer, return the longest word with the smallest lexicographical order. If there is no answer, return the empty string.
 */

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
