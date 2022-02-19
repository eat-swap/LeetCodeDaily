#include <vector>
#include <unordered_map>
#include <iostream>

class Solution {
public:
	static int findPairs(const std::vector<int>& nums, int k) {
		std::unordered_map<int, int> m;
		for (int i : nums) {
			++m[i];
		}

		int ret = 0;
		for (auto const& pii : m) {
			if ((k && m.count(pii.first + k) && m[pii.first + k]) || (!k && pii.second > 1)) {
				++ret;
			}
		}
		return ret;
	}
};

int main() {
	std::cout << Solution::findPairs({3,1,4,1,5},2);
	std::cout << Solution::findPairs({1,2,3,4,5},1);
	std::cout << Solution::findPairs({1,3,1,5,4},0);
	std::cout << Solution::findPairs({1,2,4,4,3,3,0,9,2,3},3);
	return 0;
}
