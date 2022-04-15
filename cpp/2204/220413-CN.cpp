#include <ctime>
#include <unordered_map>
#include <vector>

/**
 * 380. Insert Delete GetRandom O(1)
 * Implement the RandomizedSet class:
 * RandomizedSet() Initializes the RandomizedSet object.
 * bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
 * bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
 * int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.
 * You must implement the functions of the class such that each function works in average O(1) time complexity.
 */

class RandomizedSet {
	// m[number] -> idx
	std::unordered_map<int, int> m;

	// v[idx] -> number
	std::vector<int> v;
public:
	RandomizedSet() {
		std::srand(std::time(nullptr));
	}

	bool insert(int val) {
		if (m.count(val))
			return false;
		m[val] = v.size();
		v.push_back(val);
		return true;
	}

	bool remove(int val) {
		if (!m.count(val))
			return false;
		v[m[val]] = v.back();
		m[v.back()] = m[val];
		v.pop_back();
		m.erase(val);
		return true;
	}

	int getRandom() const {
		return v[std::rand() % v.size()];
	}
};

int main() {
	auto s = new RandomizedSet;

	s->insert(0);
	s->insert(1);
	s->remove(0);
	s->insert(2);
	s->remove(1);
	int x = s->getRandom();

	return 0;
}
