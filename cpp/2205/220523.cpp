#include <vector>
#include <string>
#include <cstdint>
#include <algorithm>
#include <iostream>

/**
 * 474. Ones and Zeroes
 * You are given an array of binary strings strs and two integers m and n.
 * Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
 * A set x is a subset of a set y if all elements of x are also elements of y.
 */

class Solution {
public:
	static int findMaxForm(const std::vector<std::string>& strs, int m, int n) {
		std::vector<uint16_t> s;
		s.reserve(strs.size());
		for (const std::string& str : strs) {
			s.push_back((std::count(str.begin(), str.end(), '0') << 8) | std::count(str.begin(), str.end(), '1'));
		}

		int ans[101][101]{};

		for (int c : s) {
			int cm = c >> 8, cn = c & 0xFF;
			for (int im = m; im >= cm; --im) {
				for (int in = n; in >= cn; --in) {
					ans[im][in] = std::max(ans[im][in], 1 + ans[im - cm][in - cn]);
				}
			}
		}

		return ans[m][n];
	}
};

int main() {
	std::cout << Solution::findMaxForm({"10","0001","111001","1","0"}, 5, 3);
	return 0;
}
