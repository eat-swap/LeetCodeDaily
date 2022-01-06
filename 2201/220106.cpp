#include <vector>
#include <iostream>

/**
 * 1094. Car Pooling
 * There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).
 *
 * You are given the integer capacity and an array trips where trip[i] = [numPassengers[i], from[i], to[i]] indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.
 *
 * Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.
 */

struct Node {
	const std::vector<int>* const data;
	Node* next;
	Node(const std::vector<int>* const data, Node* next) : data(data), next(next) {}
	~Node() { delete this->next; }
};

class SolutionOld {
public:
	static bool carPooling(const std::vector<std::vector<int>>& trips, int capacity) {
		Node* bucket[1005]{};
		for (const auto& i : trips) {
			bucket[i[1]] = new Node(&i, bucket[i[1]]);
			bucket[i[2]] = new Node(&i, bucket[i[2]]);
		}
		int current = 0;
		bool ok = true;
		for (int i = 0; i <= 1000; ++i) {
			for (Node* ptr = bucket[i]; ptr; ptr = ptr->next) {
				if ((*ptr->data)[1] == i) { // pick up
					current += (*ptr->data)[0];
				} else { // drop off
					current -= (*ptr->data)[0];
				}
			}
			if (current > capacity) {
				ok = false;
				break;
			}
		}
		for (int i = 0; i <= 1000; ++i)
			delete bucket[i];
		return ok;
	}
};

class Solution {
public:
	static bool carPooling(const std::vector<std::vector<int>>& trips, int capacity) {
		int change[1005]{};
		for (const auto& i : trips) {
			change[i[1]] += i[0];
			change[i[2]] -= i[0];
		}
		int current = 0;
		for (int i = 0; i <= 1000; ++i)
			if (capacity < (current += change[i]))
				return false;
		return true;
	}
};

int main() {
	std::cout << Solution::carPooling({{2,1,5},{3,3,7}}, 5) << std::endl;
	return 0;
}