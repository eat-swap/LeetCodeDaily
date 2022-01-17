#include <string>
#include <sstream>

class Solution {
public:
	static bool wordPattern(const std::string& pattern, const std::string& s) {
		std::string mode[26], t;
		std::stringstream sin(s);
		for (const auto& i : pattern) {
			if (!(sin >> t))
				return false;
			if (mode[i - 'a'].empty())
				mode[i - 'a'] = t;
			if (mode[i - 'a'] != t)
				return false;
			int cnt = 0;
			for (const auto& j : mode) {
				if (j == t)
					++cnt;
			}
			if (cnt > 1)
				return false;
		}
		return !(sin >> t);
	}
};

int main() {
	return !Solution::wordPattern("abba", "dog cat cat dog");
}