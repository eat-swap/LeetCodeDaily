#include <functional>
#include <vector>
#include <string>
#include <bitset>

/**
 * 1268. Search Suggestions System
 * You are given an array of strings products and a string searchWord.
 * Design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.
 * Return a list of lists of the suggested products after each character of searchWord is typed.
 */

class Solution {
private:
	int nodes[20008][26]{};
	std::bitset<20008> terminate;
	int cnt = 1;

	static constexpr inline int id(char c) { return c - 'a'; }

	void insert(const std::string& s) {
		int u = 0;
		for (char ch : s) {
			int c = id(ch);
			if (!nodes[u][c])
				nodes[u][c] = cnt++;
			u = nodes[u][c];
		}
		terminate.set(u);
	}

	std::vector<std::string> m[20008];

public:
	std::vector<std::vector<std::string>> suggestedProducts(const std::vector<std::string>& products, const std::string& searchWord) {
		if (searchWord.empty())
			return {};
		for (const std::string& s : products)
			insert(s);
		std::string buffer {searchWord.front()};
		buffer.reserve(3072);
		std::function<void(int)> dfs = [&](int u) {
			if (terminate.test(u))
				m[u].push_back(buffer);
			for (int i = 0; i < 26; ++i) {
				if (!nodes[u][i])
					continue;
				buffer.push_back(i + 'a');

				dfs(nodes[u][i]);
				m[u].insert(m[u].end(), m[nodes[u][i]].begin(), m[nodes[u][i]].end());

				buffer.pop_back();
			}
		};

		if (!nodes[0][id(searchWord.front())])
			return {searchWord.length(), std::vector<std::string>()};
		dfs(nodes[0][id(searchWord.front())]);
		int u = 0;
		std::vector<std::vector<std::string>> ret;
		for (char ch : searchWord) {
			if (!nodes[u][id(ch)]) {
				while (ret.size() < searchWord.length())
					ret.emplace_back();
				return ret;
			}
			u = nodes[u][id(ch)];
			if (m[u].size() > 3) {
				ret.push_back({m[u][0], m[u][1], m[u][2]});
			} else {
				ret.push_back(m[u]);
			}
		}
		return ret;
	}
};

int main() {
	auto* s = new Solution();
	auto r = s->suggestedProducts({"mobile","mouse","moneypot","monitor","mousepad"}, "mouse");
	return 0;
}
