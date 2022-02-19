#include <vector>
#include <cstdio>

class Solution {
public:
	static std::vector<int> pancakeSort(std::vector<int>& arr) {
		std::vector<int> ret;
		int n = arr.size();
		ret.reserve(n << 1);
		for (int i = n; i; --i) {
			auto intervalLast = std::next(arr.begin(), i);
			auto maxElement = std::max_element(arr.begin(), intervalLast);
			ret.push_back(1 + std::distance(arr.begin(), maxElement));
			ret.push_back(i);
			std::reverse(arr.begin(), std::next(maxElement));
			std::reverse(arr.begin(), intervalLast);
		}
		return ret;
	}
};

int main() {
	std::vector<int> args = {1,2,3};
	auto ret = Solution::pancakeSort(args);
	for (int i : ret) {
		std::printf("%d ", i);
	}
	return 0;
}
