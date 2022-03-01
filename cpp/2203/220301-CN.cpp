#include <iostream>
#include <string>

/**
 * 6. Zigzag Conversion
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"

 * Write the code that will take a string and make this conversion given a number of rows:
 * string convert(string s, int numRows);
 */

class Solution {
public:
	static std::string convert(const std::string& s, int numRows) {
		int n = s.length();
		if (n == 1 || numRows == 1)
			return s;

		int interval = (numRows << 1) - 2;
		int spaceH = interval - numRows;

		std::string ret;
		// Line 0
		for (int i = 0; i < n; i += interval) {
		//	if (i)
		//		ret += std::string(spaceH, ' ');
			ret.push_back(s[i]);
		}
	//	ret.push_back('\n');

		// Line [1, n)
		for (int i = 1; i < numRows - 1; ++i) {
			for (int j = i; j < n; j += interval) {
				ret.push_back(s[j]);

				// Check if this group's counterpart is OK.
				int cp = (interval - j % interval) + (j / interval * interval);
				if (cp < n) {
				//	int spaceL = cp % interval - numRows;
				//	int spaceR = spaceH - spaceL - 1;
				//	ret += std::string(spaceL, ' ');
					ret.push_back(s[cp]);
				//	if (spaceR && cp / interval * interval + interval + j % interval < n)
				//		ret += std::string(spaceR, ' ');
				}
			}
		//	ret.push_back('\n');
		}

		// Line n
		for (int i = numRows - 1; i < n; i += interval) {
		//	if (i / interval)
		//		ret += std::string(spaceH, ' ');
			ret.push_back(s[i]);
		}
		return ret;
	}
};

int main() {
	std::cout << Solution::convert("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 6);
	return 0;
}
