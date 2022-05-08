#include <vector>
#include <functional>

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
private:
	std::vector<NestedInteger> content;

	int x = 0x7FFFFFFF;

public:
	// Constructor initializes an empty nested list.
	explicit NestedInteger();

	// Constructor initializes a single integer.
	explicit NestedInteger(int value);

	// Return true if this NestedInteger holds a single integer, rather than a nested list.
	bool isInteger() const;

	// Return the single integer that this NestedInteger holds, if it holds a single integer
	// The result is undefined if this NestedInteger holds a nested list
	int getInteger() const;

	// Set this NestedInteger to hold a single integer.
	void setInteger(int value);

	// Set this NestedInteger to hold a nested list and adds a nested integer to it.
	void add(const NestedInteger& ni);

	// Return the nested list that this NestedInteger holds, if it holds a nested list
	// The result is undefined if this NestedInteger holds a single integer
	[[nodiscard]] const std::vector<NestedInteger>& getList() const;
};

/**
 * 341. Flatten Nested List Iterator
 * You are given a nested list of integers nestedList. Each element is either an integer or a list whose elements may also be integers or other lists. Implement an iterator to flatten it.
 *
 * Implement the NestedIterator class:
 *
 * NestedIterator(List<NestedInteger> nestedList) Initializes the iterator with the nested list nestedList.
 * int next() Returns the next integer in the nested list.
 * boolean hasNext() Returns true if there are still some integers in the nested list and false otherwise.
 */

class NestedIterator {
private:
	int v[512];
	int ptr = 0, rear = 0;

	void dfs(const NestedInteger& n) {
		if (n.isInteger())
			v[rear++] = n.getInteger();
		else {
			const auto& list = n.getList();
			const int s = list.size();
			for (int i = 0; i < s; ++i)
				dfs(list[i]);
		}
	}

public:
	explicit NestedIterator(const std::vector<NestedInteger>& list) {
		const int s = list.size();
		for (int i = 0; i < s; ++i)
			dfs(list[i]);
	}

	int next() {
		return v[ptr++];
	}

	bool hasNext() {
		return ptr < rear;
	}
};


int main() {
	return 0;
}

NestedInteger::NestedInteger() = default;

NestedInteger::NestedInteger(int value) : x(value) {}

bool NestedInteger::isInteger() const {
	return x < 0x7FFFFFFE;
}

int NestedInteger::getInteger() const {
	return x;
}

void NestedInteger::setInteger(int value) {
	x = value;
	content.clear();
}

void NestedInteger::add(const NestedInteger& ni) {
	if (!this->isInteger()) {
		content.push_back(ni);
		return;
	}
	content.clear();
	content.emplace_back(x);
	content.push_back(ni);
	x = 0x7FFFFFFF;
}

const std::vector<NestedInteger>& NestedInteger::getList() const {
	return content;
}
