#include <string>

class Solution {
public:
	static bool rotateString(const std::string& s, const std::string& goal) {
		char ch = s[0];
		std::size_t n = s.length();

		auto verify = [&](std::size_t p) {
			for (std::size_t i = 0; i < n; ++i, p = (1 + p) % n)
				if (s[i] != goal[p])
					return false;
			return true;
		};

		for (std::size_t nextPos = goal.find(ch, 0); nextPos != std::string::npos; nextPos = goal.find(ch, nextPos + 1))
			if (verify(nextPos))
				return true;
		return false;
	}
};
