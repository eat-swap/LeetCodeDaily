#include <string>

class Solution {
public:
	static bool rotateString(const std::string& s, const std::string& goal) {
		const std::size_t n = s.length();
		for (std::size_t np = goal.find(s[0], 0); np != std::string::npos; np = goal.find(s[0], np + 1))
			if (goal.substr(0, np) == s.substr(n - np) && goal.substr(np) == s.substr(0, n - np))
				return true;
		return false;
	}
};
