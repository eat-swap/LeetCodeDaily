#include <string>
#include <vector>
#include <iostream>

/**
 * 1239. Maximum Length of a Concatenated String with Unique Characters
 *
 * You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.
 * Return the maximum possible length of s.
 * A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
 */

class Solution {
private:
	static int popcnt(uint32_t i) {
		i = i - ((i >> 1) & 0x55555555);
		i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
		i = (i + (i >> 4)) & 0x0F0F0F0F;
		return (i * 0x01010101) >> 24;
	}

public:
	static int maxLength(const std::vector<std::string>& arr) {
		std::vector<int> s;
		for (const auto& str : arr) {
			int t = 0;
			for (const char ch : str) {
				if (t & (1 << ch - 'a')) {
					t = -1;
					break;
				}
				t |= 1 << ch - 'a';
			}
			if (t > 0)
				s.push_back(t);
		}
		int n = s.size(), ret = 0, ret_pc = 0;
		for (int i = 1 << n; --i; ) {
			bool ok = true;
			int cur = 0;
			for (int j = 0; j < n; ++j) {
				if (!(i & (1 << j)))
					continue;
				if (cur & s[j]) {
					ok = false;
					break;
				}
				cur |= s[j];
			}
			if (ok && ret_pc < popcnt(cur))
				ret_pc = popcnt(ret = cur);
		}
		return ret_pc;
	}
};

int main() {
	std::cout << Solution::maxLength({"un", "iq", "ue"});
	return 0;
}
