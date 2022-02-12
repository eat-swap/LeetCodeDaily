#include <string>
#include <vector>
#include <queue>
#include <iostream>

/**
 * 127. Word Ladder
 * A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s[1] -> s[2] -> ... -> s[k] such that:
 * Every adjacent pair of words differs by a single letter.
 * Every s[i] for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
 * s[k] == endWord
 * Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
 */

class Solution {
private:
	// Assume s is same length as t.
	static inline bool isDist1(const std::string& s, const std::string& t) {
		int n = s.length();
		bool c = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] != t[i]) {
				if (c)
					return false;
				else
					c = true;
			}
		}
		return c;
	}
public:
	static int ladderLength(const std::string& beginWord, const std::string& endWord, const std::vector<std::string>& wordList) {
		int reachable = -1, n = wordList.size();
		for (int i = 0; i < n; ++i) {
			if (wordList[i] == endWord) {
				reachable = i;
				break;
			}
		}
		if (reachable == -1)
			return 0;

		std::vector<std::vector<int>> G;
		G.reserve(wordList.size());
		for (int i = 0; i < n; ++i)
			G.emplace_back();
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (isDist1(wordList[i], wordList[j])) {
					G[j].push_back(i);
					G[i].push_back(j);
				}
			}
		}

		bool* const vis = new bool[n]{};
		std::queue<int> q;
		for (int i = 0; i < n; ++i) {
			if (isDist1(beginWord, wordList[i])) {
				q.push(i);
				q.push(2);
				vis[i] = true;
			}
		}

		while (!q.empty()) {
			int idx = q.front();
			q.pop();
			int depth = q.front();
			q.pop();
			if (reachable == idx) {
				delete[] vis;
				return depth;
			}
			for (int i : G[idx]) {
				if (!vis[i]) {
					q.push(i);
					q.push(1 + depth);
					vis[i] = true;
				}
			}
		}

		delete[] vis;
		return 0;
	}
};

int main() {
	std::cout << Solution::ladderLength("hit", "cog", {"hot","dot","dog","lot","log","cog"});
	return 0;
}