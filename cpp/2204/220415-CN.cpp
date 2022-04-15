#include <vector>
#include <string>

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
	const std::vector<NestedInteger>& getList() const;
};

/**
 * 385. Mini Parser
 * Given a string s represents the serialization of a nested list, implement a parser to deserialize it and return the deserialized NestedInteger.
 * Each element is either an integer or a list whose elements may also be integers or other lists.
 */

class Solution {
private:
	static std::vector<std::string> spiltPreservingStructure(const std::string& str, char ch = ',') {
		std::vector<std::string> ret;
		int n = str.length(), prevPos = 0;
		const char* s = str.c_str();

		auto tryPush = [&](int x, int y) {
			auto nx = std::string(s + x, s + y);
			if (!nx.empty())
				ret.push_back(std::move(nx));
		};

		for (int i = 0; i < n; ++i) {
			if (s[i] == ch) {
				tryPush(prevPos, i);
				prevPos = 1 + i;
			}
			if (s[i] != '[')
				continue;

			// s[i] == '['
			for (int stack = 1, dummy = ++i; stack; ++i) {
				if (s[i] == '[')
					++stack;
				else if (s[i] == ']')
					--stack;
			}
			--i;
		}
		tryPush(prevPos, n);
		return ret;
	}

public:
	static NestedInteger deserialize(const std::string& s) {
		// Detect whole number?
		if (std::all_of(s.begin() + 1, s.end(), [](char ch){ return std::isdigit(ch); }) && (s.front() == '-' || std::isdigit(s.front())))
			return NestedInteger(std::stoi(s));

		// Strip surrounding []
		auto ss = s.substr(1);
		ss.pop_back();
		auto sss = spiltPreservingStructure(ss);
		NestedInteger ret;
		for (const auto& ssss : sss) {
			ret.add(deserialize(ssss));
		}
		return ret;
	}

	static auto debug(const std::string& s) {
		return spiltPreservingStructure(s);
	}
};

int main() {
	// auto ans = Solution::deserialize("324");
	auto ret = Solution::debug("123,[456,[789]],1212,[123]");
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
