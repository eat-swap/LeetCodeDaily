#include <string>
#include <iostream>

/**
 * 208. Implement Trie (Prefix Tree)
 *
 * A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.
 *
 * Implement the Trie class:
 *
 * Trie() Initializes the trie object.
 * void insert(String word) Inserts the string word into the trie.
 * boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
 * boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 */

struct TrieNode {
	TrieNode* p[26] = {};
	bool terminate = false;
};

class Trie {
private:
	TrieNode r;

public:
	Trie() = default;

	void insert(const std::string& word) {
		TrieNode* ptr = &this->r;
		for (char i : word) {
			if (!ptr->p[i - 'a'])
				ptr->p[i - 'a'] = new TrieNode;
			ptr = ptr->p[i - 'a'];
		}
		ptr->terminate = true;
	}

	bool search(const std::string& word) const {
		const TrieNode* ptr = &this->r;
		for (char i : word) {
			if (!ptr->p[i - 'a'])
				return false;
			ptr = ptr->p[i - 'a'];
		}
		return ptr && ptr->terminate;
	}

	bool startsWith(const std::string& prefix) const {
		const TrieNode* ptr = &this->r;
		for (char i : prefix) {
			if (!ptr->p[i - 'a'])
				return false;
			ptr = ptr->p[i - 'a'];
		}
		return ptr;
	}
};

int main() {
	Trie trie;
	trie.insert("apple");
	std::cout << trie.search("apple");   // return True
	std::cout << trie.search("app");     // return False
	std::cout << trie.startsWith("app"); // return True
	trie.insert("app");
	std::cout << trie.search("app");     // return True
	return 0;
}
