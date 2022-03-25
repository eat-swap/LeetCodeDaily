#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    static int twoCitySchedCost(std::vector<std::vector<int>>& costs) {
        int n = costs.size() >> 1, ret = 0;
		std::sort(costs.begin(), costs.end(), [](const std::vector<int>& x, const std::vector<int>& y) { return x[0] - x[1] < y[0] - y[1]; });
		for (int i = 0; i < n; ++i)
			ret += costs[i][0] + costs[i + n][1];
		return ret;
    }
};

int main() {
	std::vector<std::vector<int>> args {{10,20},{30,200},{400,50},{30,20}};
	std::cout << Solution::twoCitySchedCost(args);
	return 0;
}
