#include <string>
#include <iostream>

class Solution {
public:
	static std::string longestPalindrome(const std::string& s) {
		int n = s.length(), centre, len = 0;
		for (int i = 0; i < n; ++i) {
			int L = i, R = i;
			while (L - 1 >= 0 && R + 1 < n && s[L - 1] == s[R + 1]) {
				--L, ++R;
			}
			if (len < R - L + 1) {
				centre = i;
				len = R - L + 1;
			}
		}
		for (int i = 1; i < n; ++i) {
			if (s[i] != s[i - 1]) continue;
			int L = i - 1, R = i;
			while (L - 1 >= 0 && R + 1 < n && s[L - 1] == s[R + 1]) {
				--L, ++R;
			}
			if (len < R - L + 1) {
				centre = i;
				len = R - L + 1;
			}
		}
		return s.substr(centre - len / 2, len);
	}
};

int main() {
	std::cout << Solution::longestPalindrome("eabcb");
	return 0;
}
