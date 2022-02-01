#include <vector>
#include <cstdio>

class Solution {
public:
	static int maxProfit(const std::vector<int>& prices) {
		int toBuy = 0x7FFFFFFF, ret = 0;
		for (int price : prices) {
			ret = std::max(price - toBuy, ret);
			toBuy = std::min(price, toBuy);
		}
		return ret;
	}
};

int main() {
	std::printf("%d\n", Solution::maxProfit({7,6,4,3,1}));
	return 0;
}
