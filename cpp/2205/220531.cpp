#include <string>
#include <bitset>

/**
 * 1461. Check If a String Contains All Binary Codes of Size K
 * Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.
 */

class Solution {
public:
	static bool hasAllCodes(const std::string& s, int k) {
		if (s.length() <= k)
			return false;
		int cur = 0, cnt = 1, mask = (1 << k) - 1;
		for (int i = 0; i < k; ++i)
			cur = (cur << 1) | (s[i] & 1);
		std::bitset<1 << 20> v;
		v.set(cur);
		for (int r = k; r < s.length(); ++r) {
			cur = ((cur << 1) | (s[r] & 1)) & mask;
			if (!v.test(cur)) {
				v.set(cur);
				++cnt;
			}
		}
		return cnt == (1 << k);
	}
};

int main() {
	Solution::hasAllCodes("01", 1);
	return 0;
}
