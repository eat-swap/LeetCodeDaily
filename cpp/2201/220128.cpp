#include <string>
#include <queue>
#include <iostream>

struct Node {
	 Node* children[27] {};

	 Node() = default;

	 ~Node() {
		 for (auto*& ptr : this->children) {
			 delete ptr;
		 }
	 }
};

/**
 * 211. Design Add and Search Words Data Structure
 * Design a data structure that supports adding new words and finding if a string matches any previously added string.
 *
 * Implement the WordDictionary class:
 *
 * WordDictionary() Initializes the object.
 * void addWord(word) Adds word to the data structure, it can be matched later.
 * bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 */

class WordDictionary {
private:
	Node root;
public:
	WordDictionary() = default;

	void addWord(const std::string& word) {
		Node* ptr = &this->root;
		for (char ch : word)
			ptr = ptr->children[ch - 'a'] = ((ptr->children[ch - 'a']) ? (ptr->children[ch - 'a']) : new Node());
		ptr->children[26] = new Node();
	}

	bool search(const std::string& word) const {
		int n = word.length();
		std::queue<std::pair<const Node*, int>> q;
		q.push({&this->root, 0});
		while (!q.empty()) {
			const auto t = q.front();
			q.pop();
			if (!t.first)
				continue;
			if (t.second == n) {
				if (t.first->children[26])
					return true;
				continue;
			}
			if (word[t.second] == '.') {
				for (const auto* const& ptr : t.first->children) {
					q.push({ptr, 1 + t.second});
				}
			} else {
				q.push({t.first->children[word[t.second] - 'a'], 1 + t.second});
			}
		}
		return false;
	}
};

int main() {
	{
		WordDictionary wordDictionary;
		wordDictionary.addWord("bad");
		wordDictionary.addWord("dad");
		wordDictionary.addWord("mad");
		std::cout << wordDictionary.search("pad"); // return False
		std::cout << wordDictionary.search("bad"); // return True
		std::cout << wordDictionary.search(".ad"); // return True
		std::cout << wordDictionary.search("b.."); // return True
	}
	std::cout << std::endl;
	{
		WordDictionary wordDictionary;
		wordDictionary.addWord("at");
		wordDictionary.addWord("and");
		wordDictionary.addWord("an");
		wordDictionary.addWord("add");
		// wordDictionary.addWord("a");
		std::cout << wordDictionary.search("a"); // return False
	}
	{
		WordDictionary wordDictionary;
		wordDictionary.addWord("ran");
		wordDictionary.addWord("rune");
		wordDictionary.addWord("runner");
		wordDictionary.addWord("runs");
		wordDictionary.addWord("add");
		wordDictionary.addWord("adds");
		wordDictionary.addWord("adder");
		wordDictionary.addWord("addee");
		wordDictionary.search("add.");
	}
	return 0;
}
