#include <string>
#include <queue>
#include <iostream>

/**
 * 211. Design Add and Search Words Data Structure
 * Design a data structure that supports adding new words and finding if a string matches any previously added string.
 *
 * Implement the WordDictionary class:
 *
 * WordDictionary() Initializes the object.
 * void addWord(word) Adds word to the data structure, it can be matched later.
 * bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 *
 * Refer: 220128.cpp (it does not accept this solution now. 19/03/'23)
 * And it should not fail, since the time complexity of BFS and DFS are the same (O(n), where n is the number of nodes)
 */

struct TrieNode {
	TrieNode* p[26] = {};
	bool terminate = false;
};

class WordDictionary {
private:
	TrieNode r;

	static bool dfs(const TrieNode* const ptr, const char* const str) {
		if (!*str)
			return ptr->terminate;
		if (*str == '.') {
			for (const TrieNode* const i : ptr->p)
				if (i && dfs(i, str + 1))
					return true;
		} else if (ptr->p[*str - 'a'] && dfs(ptr->p[*str - 'a'], str + 1))
			return true;
		return false;
	}

public:
	WordDictionary() = default;

	void addWord(const std::string& word) {
		TrieNode* ptr = &r;
		for (char i : word) {
			if (!ptr->p[i - 'a'])
				ptr->p[i - 'a'] = new TrieNode;
			ptr = ptr->p[i - 'a'];
		}
		ptr->terminate = true;
	}

	bool search(const std::string& word) const {
		const char* const str = word.c_str();
		return dfs(&r, str);
	}
};

int main() {
	WordDictionary wordDictionary;
	wordDictionary.addWord("bad");
	wordDictionary.addWord("dad");
	wordDictionary.addWord("mad");
	std::cout << wordDictionary.search("pad"); // return False
	std::cout << wordDictionary.search("bad"); // return True
	std::cout << wordDictionary.search(".ad"); // return True
	std::cout << wordDictionary.search("b.."); // return True
	return 0;
}
