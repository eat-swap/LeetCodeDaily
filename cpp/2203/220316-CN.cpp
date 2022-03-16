#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

class AllOne {
private:
	int n = 0;
	std::unordered_map<int, std::string> id2Str;
	std::unordered_map<std::string, int> str2Id;
	std::map<int, std::unordered_set<int>> val2Id;
	std::unordered_map<int, int> id2Val;
public:
	AllOne() = default;

	void inc(const std::string& key) {
		if (str2Id.count(key)) {
			int idx = str2Id[key];
			int& val = id2Val[idx];
			if (val2Id[val].size() == 1) {
				val2Id.erase(val);
			} else {
				val2Id[val].erase(idx);
			}
			val2Id[++val].insert(idx);
		} else {
			int x = str2Id[key] = ++n;
			id2Str[x] = key;
			id2Val[x] = 1;
			val2Id[1].insert(x);
		}
	}

	void dec(const std::string& key) {
		int idx = str2Id[key];
		int& val = id2Val[idx];
		if (val == 1) {
			id2Str.erase(idx);
			if (val2Id[1].size() == 1)
				val2Id.erase(1);
			else
				val2Id[1].erase(idx);
			str2Id.erase(key);
			id2Val.erase(idx);
		} else {
			if (val2Id[val].size() == 1) {
				val2Id.erase(val);
			} else {
				val2Id[val].erase(idx);
			}
			val2Id[--val].insert(idx);
		}
	}

	std::string getMaxKey() {
		return str2Id.empty() ? "" : id2Str[*(val2Id.rbegin()->second.begin())];
	}

	std::string getMinKey() {
		return str2Id.empty() ? "" : id2Str[*(val2Id.begin()->second.begin())];
	}
};

int main() {
	AllOne test;
	test.inc("hello");
	test.inc("hello");
	std::cout << test.getMaxKey() << std::endl;
	std::cout << test.getMinKey() << std::endl;
	test.inc("123");
	std::cout << test.getMaxKey() << std::endl;
	std::cout << test.getMinKey() << std::endl;
	test.dec("hello");
	std::cout << test.getMaxKey() << std::endl;
	std::cout << test.getMinKey() << std::endl;
	test.dec("hello");
	std::cout << test.getMaxKey() << std::endl;
	std::cout << test.getMinKey() << std::endl;
}
