#include <iostream>
#include <vector>

class Solution {
public:
	static int numPairsDivisibleBy60(const std::vector<int>& time) {
		int bucket[61]{0};
		for (const auto& i : time)
			++bucket[i % 60];
		int ret = bucket[0] * (bucket[0] - 1) / 2 + bucket[30] * (bucket[30] - 1) / 2;
		for (int i = 1; i < 30; ++i)
			ret += bucket[i] * bucket[60 - i];
		return ret;
	}
};

int main() {
	std::cout << Solution::numPairsDivisibleBy60({60,60,60});
	return 0;
}
