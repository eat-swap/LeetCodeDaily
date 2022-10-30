#include <string>
#include <algorithm>

class Solution {
public:
	bool canConstruct(const std::string& r, const std::string& m) {
		for (char c = 'a'; c <= 'z'; ++c)
			if (std::count(r.begin(), r.end(), c) > std::count(m.begin(), m.end(), c))
				return false;
		return true;
	}
};
