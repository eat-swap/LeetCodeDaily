#include <vector>

class Solution {
public:
	static int countKDifference(const std::vector<int>& nums, int k) {
		int ret = 0;
		for (auto it = nums.begin(); it != nums.end(); ++it)
			for (auto jt = std::next(it); jt != nums.end(); ++jt)
				if (std::abs(*it - *jt) == k)
					++ret;
		return ret;
	}
};

int main() {
	return 0;
}
