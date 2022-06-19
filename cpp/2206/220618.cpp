#include <ranges>
#include <vector>
#include <string>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

struct Trie {
private:
	static const int MAX_NODE = 150001;

	static constexpr inline int id(char ch) {
		return ch - 'a';
	}

	std::unordered_map<int, std::vector<int>> m;

	std::vector<int> traverse(int idx) {
		if (m.count(idx))
			return m[idx];
		std::vector<int>& ret = m[idx];
		if (val[idx])
			ret.push_back(val[idx]);
		for (int i = 0; i < 26; ++i) {
			if (!nodes[idx][i])
				continue;
			auto nx = traverse(nodes[idx][i]);
			ret.insert(ret.end(), nx.begin(), nx.end());
		}
		return ret;
	}

public:
	int nodes[MAX_NODE][26]{};
	int val[MAX_NODE]{};
	int cnt = 1;

	Trie() = default;

	void insert(const std::string& str, int v) {
		int u = 0;
		for (char ch : str) {
			int c = id(ch);
			if (!nodes[u][c])
				nodes[u][c] = cnt++;
			u = nodes[u][c];
		}
		val[u] = v;
	}

	void insertRev(const std::string& str, int v) {
		int u = 0;
		for (char ch : std::ranges::reverse_view(str)) {
			int c = id(ch);
			if (!nodes[u][c])
				nodes[u][c] = cnt++;
			u = nodes[u][c];
		}
		val[u] = v;
	}

	std::vector<int> find(const std::string& prefix) {
		int u = 0;
		for (char ch : prefix) {
			int c = id(ch);
			if (!nodes[u][c])
				return {};
			u = nodes[u][c];
		}
		return traverse(u);
	}

	std::vector<int> findRev(const std::string& revPrefix) {
		int u = 0;
		for (auto it = revPrefix.crbegin(); it != revPrefix.crend(); ++it) {
			int c = id(*it);
			if (!nodes[u][c])
				return {};
			u = nodes[u][c];
		}
		return traverse(u);
	}
};

/**
 * 745. Prefix and Suffix Search
 * Design a special dictionary with some words that searches the words in it by a prefix and a suffix.
 * Implement the WordFilter class:
 * - WordFilter(string[] words) Initializes the object with the words in the dictionary.
 * - f(string prefix, string suffix) Returns the index of the word in the dictionary, which has the prefix prefix and the suffix suffix. If there is more than one valid index, return the largest of them. If there is no such word in the dictionary, return -1.
 */

class WordFilter {
private:
	Trie p, s;

public:
	explicit WordFilter(const std::vector<std::string>& words) {
		const int n = words.size();
		for (int i = 0; i < n; ++i) {
			p.insert(words[i], i + 1);
			s.insertRev(words[i], i + 1);
		}
	}

	int f(const std::string& prefix, const std::string& suffix) {
		auto pf = p.find(prefix), sf = s.findRev(suffix);
		std::unordered_set<int> pfs(pf.begin(), pf.end());
		int ret = -1;
		for (int i : sf)
			if (pfs.count(i))
				ret = std::max(ret, i - 1);
		return ret;
	}
};

int main() {
	auto* s = new WordFilter({"apple"});
	std::cout << s->f("a", "e");
	return 0;
}
