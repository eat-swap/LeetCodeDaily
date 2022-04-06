#include <string>

class Solution {
public:
	static bool rotateString(const std::string& s, const std::string& g) {
		const std::size_t n = s.length();
		for (std::size_t np = g.find(s[0], 0); np != std::string::npos; np = g.find(s[0], np + 1))
			if (g.substr(np) + g.substr(0, np) == s)
				return true;
		return false;
	}
};
