#include <unordered_map>

struct Node {
	int key, val;
	Node* next;

	explicit Node(int k, int v, Node* n) : key(k), val(v), next(n) {}
};

/**
 * 706. Design HashMap
 * Design a HashMap without using any built-in hash table libraries.
 * Implement the MyHashMap class:
 * MyHashMap() initializes the object with an empty map.
 * void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
 * int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
 * void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.
 *
 */

class MyHashMap {
private:
	static inline const int BUCKET_SIZE = 512;

	Node* bucket[BUCKET_SIZE] = {};

	Node* getPointer(int key) {
		for (Node* ptr = this->bucket[key % BUCKET_SIZE]; ptr; ptr = ptr->next)
			if (ptr->key == key)
				return ptr;
		return nullptr;
	}

public:
	MyHashMap() = default;

	int get(int key) {
		auto* ptr = getPointer(key);
		return ptr ? ptr->val : -1;
	}

	void put(int key, int value) {
		auto* ptr = this->getPointer(key);
		if (ptr)
			ptr->val = value;
		else
			this->bucket[key % BUCKET_SIZE] = new Node(key, value, this->bucket[key % BUCKET_SIZE]);
	}

	void remove(int key) {
		Node* ptr = this->bucket[key % BUCKET_SIZE];
		if (ptr && ptr->key == key) {
			this->bucket[key % BUCKET_SIZE] = ptr->next;
			delete ptr;
			return;
		}
		for (; ptr && ptr->next; ptr = ptr->next) {
			if (ptr->next->key == key) {
				auto* toDelete = ptr->next;
				ptr->next = toDelete->next;
				delete toDelete;
			}
		}
	}
};

class MyHashMapSTL {
private:
	std::unordered_map<int, int> m;
public:
	MyHashMapSTL() = default;

	int get(int key) {
		return m.count(key) ? m[key] : -1;
	}

	void put(int key, int value) {
		m[key] = value;
	}

	void remove(int key) {
		m.erase(key);
	}
};
