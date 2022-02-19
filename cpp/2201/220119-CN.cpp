#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

/**
 * Optimising is some sort of art.
 *
 * 219. Contains Duplicate II
 * Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
 */

struct Node {
	int val;
	Node* next;
	explicit Node(int v, Node* n = nullptr) : val(v), next(n) {}
	~Node() { delete this->next; }
};

class Solution {
public:
	static bool containsNearbyDuplicate(const std::vector<int>& nums, int k) {
		Node* hashTable[65536] {};
		int n = nums.size();
		if (!(k = std::min(k, n))) return false;
		int ni, nik;
		for (int i = 0; i < k; ++i) {
			ni = nums[i];
			for (auto* ptr = hashTable[ni & 0xFFFF]; ptr; ptr = ptr->next) {
				if (ptr->val == ni) {
					for (auto*& j : hashTable)
						delete j;
					return true;
				}
			}
			hashTable[ni & 0xFFFF] = new Node(ni, hashTable[ni & 0xFFFF]);
		}
		for (int i = k; i < n; ++i) {
			ni = nums[i];
			nik = nums[i - k];
			for (auto* ptr = hashTable[ni & 0xFFFF]; ptr; ptr = ptr->next) {
				if (ptr->val == ni) {
					for (auto*& j : hashTable)
						delete j;
					return true;
				}
			}
			hashTable[ni & 0xFFFF] = new Node(ni, hashTable[ni & 0xFFFF]);
			for (auto ptr = hashTable[nik & 0xFFFF], prev = (decltype(ptr))(nullptr); ptr; (prev = ptr), (ptr = ptr->next)) {
				if (ptr->val == nik) {
					if (prev)
						prev->next = ptr->next;
					else
						hashTable[nik & 0xFFFF] = ptr->next;
					delete ptr;
					break;
				}
			}
		}
		return false;
	}
};

int main() {
	std::cout << Solution::containsNearbyDuplicate({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 15);
	return 0;
}

class SolutionOld {
public:
	static bool containsNearbyDuplicate(const std::vector<int>& nums, int k) {
		std::unordered_set<int> s;
		int n = nums.size();
		k = std::min(k, n);
		for (int i = 0; i < k; ++i) {
			if (s.count(nums[i]))
				return true;
			s.insert(nums[i]);
		}
		for (int i = k; i < n; ++i) {
			if (s.count(nums[i]))
				return true;
			s.insert(nums[i]);
			s.erase(nums[i - k]);
		}
		return false;
	}
};

class SolutionOlder {
public:
	static bool containsNearbyDuplicate(const std::vector<int>& nums, int k) {
		std::unordered_map<int, int> m;
		int n = nums.size();
		for (int i = 0; i < n; ++i) {
			if (m.count(nums[i]) && i - m[nums[i]] <= k)
				return true;
			m[nums[i]] = i;
		}
		return false;
	}
};
