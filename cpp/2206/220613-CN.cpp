#include <vector>
#include <algorithm>

class Solution {
public:
	static int heightChecker(const std::vector<int>& h) {
		auto x = h;
		std::stable_sort(x.begin(), x.end());
		int ret = 0;
		for (int i = 0; i < x.size(); ++i)
			ret += (x[i] != h[i]);
		return ret;
	}
};
