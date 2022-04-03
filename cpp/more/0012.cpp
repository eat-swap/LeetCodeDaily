#include <iostream>
#include <string>
#include <vector>

class Solution {
private:
	const inline static std::vector<std::vector<std::string>> RN = {
			{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
			{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
			{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
			{"", "M", "MM", "MMM"}
	};
public:
	static std::string intToRoman(int num) {
		return RN[3][num / 1000] +
			   RN[2][(num / 100) % 10] +
			   RN[1][(num % 100) / 10] +
			   RN[0][num % 10];
	}
};

int main() {
	std::cout << Solution::intToRoman(1994);
	return 0;
}
