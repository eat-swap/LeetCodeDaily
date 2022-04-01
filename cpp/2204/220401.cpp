#include <vector>
#include <algorithm>

/**
 * 344. Reverse String
 * Write a function that reverses a string. The input string is given as an array of characters s.
 * You must do this by modifying the input array in-place with O(1) extra memory.
 */

class Solution {
public:
	static void reverseString(std::vector<char>& s) {
		std::reverse(s.begin(), s.end());
	}
};
