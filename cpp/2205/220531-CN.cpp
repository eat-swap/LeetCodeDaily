#include <vector>
#include <string>
#include <iostream>
#include <functional>

/**
 * 269. Alien Dictionary
 *
 * Description is unavailable.
 */

class Solution {
public:
	static std::string alienOrder(const std::vector<std::string>& words) {
		bool G[26][26]{{}}, present[26]{};
		for (int i = 1; i < words.size(); ++i) {
			const std::string& x = words[i - 1];
			const std::string& y = words[i];
			const int k = std::min(x.length(), y.length());
			int j = 0;
			for (; j < k; ++j) {
				if (x[j] == y[j])
					continue;
				G[x[j] - 'a'][y[j] - 'a'] = true;
				std::printf("%c > %c\n", x[j], y[j]);
				break;
			}
			if (j == k && y.length() < x.length())
				return "";
		}
		for (const auto& x : words)
			for (const char c : x)
				present[c - 'a'] = true;

		char tp[26]{}, c[26]{};
		int t = 26;
		std::function<bool(int)> dfs = [&](int x) {
			c[x] = -1;
			for (int i = 0; i < 26; ++i) {
				if (!present[i] || !G[x][i])
					continue;
				if (c[i] < 0 || (!c[i] && !dfs(i)))
					return false;
			}
			c[x] = 1;
			tp[--t] = x + 'a';
			return true;
		};

		for (int i = 0; i < 26; ++i)
			if (present[i] && !c[i] && !dfs(i))
				return "";
		for (int i = 0; i < 26; ++i)
			if (present[i] && !c[i])
				tp[--t] = i + 'a';
		return {tp + t, tp + 26};
	}
};

int main() {
	std::cout << Solution::alienOrder({"ab", "adc"});
	return 0;
}
