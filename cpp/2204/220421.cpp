struct Node {
	int val;
	Node* next;

	explicit Node(int x, Node* n) : val(x), next(n) {}
};

/**
 * 705. Design HashSet
 * Design a HashSet without using any built-in hash table libraries.
 * Implement MyHashSet class:
 * void add(key) Inserts the value key into the HashSet.
 * bool contains(key) Returns whether the value key exists in the HashSet or not.
 * void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.
 */

class MyHashSetNormal {
private:
	static inline const int BUCKET_SIZE = 512;

	Node* bucket[BUCKET_SIZE] = {};
public:
	MyHashSetNormal() = default;

	void remove(int key) {
		Node* ptr = this->bucket[key % BUCKET_SIZE];
		if (ptr && ptr->val == key) {
			this->bucket[key % BUCKET_SIZE] = ptr->next;
			delete ptr;
			return;
		}
		for (; ptr && ptr->next; ptr = ptr->next) {
			if (ptr->next->val == key) {
				auto* toDelete = ptr->next;
				ptr->next = toDelete->next;
				delete toDelete;
			}
		}
	}

	bool contains(int key) {
		for (Node* ptr = this->bucket[key % BUCKET_SIZE]; ptr; ptr = ptr->next)
			if (ptr->val == key)
				return true;
		return false;
	}

	void add(int key) {
		if (this->contains(key))
			return;
		this->bucket[key % BUCKET_SIZE] = new Node(key, this->bucket[key % BUCKET_SIZE]);
	}
};

#include <bitset>

// Slower...
class MyHashSet {
private:
	std::bitset<1000001> s;
public:
	MyHashSet() = default;

	void remove(int key) {
		s.reset(key);
	}

	bool contains(int key) {
		return s.test(key);
	}

	void add(int key) {
		s.set(key);
	}
};
