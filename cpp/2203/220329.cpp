#include <vector>
#include <bitset>

class Solution {
public:
	static int findDuplicate(const std::vector<int>& nums) {
		std::bitset<100008> s;
		for (int i : nums) {
			if (s[i])
				return i;
			s[i] = true;
		}
		return -1;
	}
};
