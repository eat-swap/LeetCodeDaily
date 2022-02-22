#include <iostream>
#include <string>

/**
 * 171. Excel Sheet Column Number
 * Given a string columnTitle that represents the column title as appear in an Excel sheet, return its corresponding column number.
 */

class Solution {
public:
	static int titleToNumber(const std::string& columnTitle) {
		int ret = 0;
		for (char ch : columnTitle)
			ret = 26 * ret - 'A' + ch + 1;
		return ret;
	}
};

int main() {
	return 0;
}
