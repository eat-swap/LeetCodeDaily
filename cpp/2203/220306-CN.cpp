#include <vector>
#include <iostream>

class Solution {
public:
	static std::vector<int> goodDaysToRobBank(const std::vector<int>& security, int time) {
		int n = security.size();
		std::vector<int> ret, isNotIncreasingSince(n), isNotDecreasingSince(n);
		for (int i = 1; i < n; ++i) {
			isNotDecreasingSince[i] = (security[i - 1] <= security[i]) ? isNotDecreasingSince[i - 1] : i;
			isNotIncreasingSince[i] = (security[i - 1] >= security[i]) ? isNotIncreasingSince[i - 1] : i;
		}
		for (int i = time; i < n - time; ++i)
			if (isNotIncreasingSince[i] <= i - time && isNotDecreasingSince[i + time] <= i)
				ret.push_back(i);
		return ret;
	}
};

int main() {
	auto ret = Solution::goodDaysToRobBank({1,2,3,4,5,6},2);
	for (int i : ret)
		std::cout << i << ' ';
}
