#include <vector>
#include <string>
#include <iostream>

/**
 * 443. String Compression
 *
 * Given an array of characters chars, compress it using the following algorithm:
 *
 * Begin with an empty string s. For each group of consecutive repeating characters in chars:
 *
 * If the group's length is 1, append the character to s.
 * Otherwise, append the character followed by the group's length.
 * The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.
 *
 * After you are done modifying the input array, return the new length of the array.
 *
 * You must write an algorithm that uses only constant extra space.
 */

class Solution {
public:
	static int compress(std::vector<char>& c) {
		const int n = c.size();
		int pos = 0, ct = 1;
		for (int i = 0; i < n; ++i) {
			// Look ahead
			if (i + 1 < n && c[i] == c[1 + i]) {
				++ct;
			} else {
				c[pos++] = c[i];
				if (ct > 1)
					for (char x : std::to_string(ct))
						c[pos++] = x;
				ct = 1;
			}
		}
		return pos;
	}
};

int main() {
	const char* s = "abbbbbbbbbbbb";
	std::vector<char> c;
	for (const char* ptr = s; *ptr; ++ptr)
		c.push_back(*ptr);
	int n = Solution::compress(c);
	for (int i = 0; i < n; ++i)
		std::cout << c[i];
	return 0;
}
