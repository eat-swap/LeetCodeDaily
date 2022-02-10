#include <vector>
#include <string>
#include <numeric>

class Solution {
private:
	inline static std::string genStr(int x, int y) {
		return std::to_string(x) + "/" + std::to_string(y);
	}
public:
	static std::vector<std::string> simplifiedFractions(int n) {
		std::vector<std::string> ret;
		for (int i = 2; i < n; ++i)
			for (int j = 1; j < i; ++j)
				if (1 == std::gcd(i, j))
					ret.push_back(genStr(j, i));
		return ret;
	}
};