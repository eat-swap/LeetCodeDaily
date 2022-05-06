#include <string>
#include <vector>
#include <chrono>
#include <iostream>

template<typename T>
struct ListNode {
	T data;
	ListNode<T>* prev;
	ListNode<T>* next;

	explicit ListNode(T d, ListNode<T>* p = nullptr, ListNode<T>* n = nullptr) : data(std::move(d)), prev(p), next(n) {}
	ListNode(ListNode<T>* p, ListNode<T>* n) : prev(p), next(n) {}
};

template<typename T>
struct LinkedList {
	unsigned long long size = 0;
	ListNode<T>* front = nullptr;
	ListNode<T>* rear = nullptr;

	LinkedList() {
		front = new ListNode((ListNode<T>*)nullptr, (ListNode<T>*)nullptr);
		rear = new ListNode(front, (ListNode<T>*) nullptr);
		front->next = rear;
	}

	void push_back(T data) {
		auto* node = new ListNode(data, rear->prev, rear);
		rear->prev = rear->prev->next = node;
		++size;
	}

	ListNode<T>* erase(ListNode<T>* node) {
		auto ret = node->next;
		node->prev->next = node->next;
		node->next->prev = node->prev;
		delete node;
		--size;
		return ret;
	}

	bool empty() const {
		return !size;
	}

	ListNode<T>* begin() {
		return front->next;
	}

	ListNode<T>* end() {
		return rear;
	}
};

/**
 * 1209. Remove All Adjacent Duplicates in String II
 * You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.
 * We repeatedly make k duplicate removals on s until we no longer can.
 * Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.
 */

class Solution {
public:
	static std::string removeDuplicates(const std::string& s, int k) {
		if (s.empty())
			return {};

		LinkedList<std::pair<char, int>> cnt;
		{
			int c = 1;
			char current = *s.c_str();
			for (const char* ptr = s.c_str() + 1; *ptr; ++ptr) {
				if (*ptr == current) {
					++c;
					continue;
				}
				cnt.push_back({current, c});
				c = 1;
				current = *ptr;
			}
			cnt.push_back({current, c});
		}

		// Remove & Merge
		for (auto ptr = cnt.begin(); ptr != cnt.end();) {
			// Now, nothing can be merged.

			// Eliminate at once
			ptr->data.second %= k;

			// Check if totally removed
			if (ptr->data.second) {
				ptr = ptr->next;
				continue;
			}

			// Totally removed!
			// possible to be merged
			ptr = cnt.erase(ptr);
			if (cnt.empty())
				break;
			if (ptr != cnt.begin())
				ptr = ptr->prev;
			auto prevPtr = ptr;
			ptr = ptr->next;
			while (ptr != cnt.end() && prevPtr->data.first == ptr->data.first) {
				prevPtr->data.second += ptr->data.second;
				ptr = cnt.erase(ptr);
			}

			ptr = prevPtr;
		}

		std::string ret;
		for (auto* ptr = cnt.begin(); ptr != cnt.end(); ptr = ptr->next) {
			const auto [ch, n] = ptr->data;
			ret.append(n, ch);
		}
		return ret;
	}
};

class Stopwatch {
private:
	std::chrono::high_resolution_clock::time_point start;
public:
	Stopwatch() {
		this->start = std::chrono::high_resolution_clock::now();
	}

	~Stopwatch() {
		std::printf("Time elapsed: %.6lf ms\n", std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - start).count() / 1000000.0);
	}
};

int main() {
	std::string arg;
	arg.reserve(100000);
	for (int i = 0; i < 1923; ++i)
		arg += "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < 1923; ++i)
		arg += "zyxwvutsrqponmlkjihgfedcba";
	{
		Stopwatch s;
		std::cout << Solution::removeDuplicates(arg, 2) << "\n";
	}
	return 0;
}
