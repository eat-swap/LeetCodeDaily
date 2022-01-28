#include <vector>
#include <iostream>

class Solution {
public:
	static int numberOfWeakCharacters(std::vector<std::vector<int>>& properties) {
		std::sort(properties.begin(), properties.end(), [](const std::vector<int>& x, const std::vector<int>& y) {
			if (x[0] - y[0])
				return x[0] > y[0];
			return x[1] < y[1];
		});
		int ret = 0, max = -1;
		for (const auto& i : properties)
			if ((max = std::max(i[1], max)) > i[1])
				++ret;
		return ret;
	}
};

int main() {
	std::vector<std::vector<int>> args = {{1,1},{2,1},{2,2},{1,2}};
	std::cout << Solution::numberOfWeakCharacters(args);
	return 0;
}
