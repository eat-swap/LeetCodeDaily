#include <vector>
#include <cstdio>

class Solution {
public:
	static int maximumWealth(const std::vector<std::vector<int>>& accounts) {
		int ret = 0;
		for (const auto& i : accounts) {
			int t = 0;
			std::for_each(i.begin(), i.end(), [&t](const int& v) { t += v; });
			ret = std::max(t, ret);
		}
		return ret;
	}
};

int main() {
	std::printf("%d\n", Solution::maximumWealth({{1,2,3},{3,2,1}}));
}
