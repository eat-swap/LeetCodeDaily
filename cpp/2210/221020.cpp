#include <string>
#include <iostream>

/**
 * 12. Integer to Roman
 *
 * No desc since clear
 */

class Solution {
public:
	static std::string intToRoman(int num) {
		static const char* s = "IVXLCDM";
		std::string ret;
		for (int i = 0; i < 6; i += 2, num /= 10) {
			int n = num % 10;
			if (n == 4 || n == 9) {
				ret.push_back(s[i + 1 + (n > 5)]);
				ret.push_back(s[i]);
			} else {
				ret.append(n % 5, s[i]);
				if (n >= 5) ret.push_back(s[i + 1]);
			}
		}
		ret.append(num, 'M');
		std::reverse(ret.begin(), ret.end());
		return ret;
	}
};

int main() {
	for (int i = 1; i <= 50; ++i) {
		std::cout << Solution::intToRoman(i) << "\n";
	}
	std::cout << Solution::intToRoman(3) << "\n";
	std::cout << Solution::intToRoman(58) << "\n";
	std::cout << Solution::intToRoman(1994) << "\n";
	return 0;
}
