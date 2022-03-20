#include <vector>
#include <iostream>

/**
 * 393. UTF-8 Validation
 * Given an integer array data representing the data, return whether it is a valid UTF-8 encoding.
 * A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:
 * - For a 1-byte character, the first bit is a 0, followed by its Unicode code.
 * - For an n-bytes character, the first n bits are all one's, the n + 1 bit is 0, followed by n - 1 bytes with the most significant 2 bits being 10.
 * Note: The input is an array of integers. Only the least significant 8 bits of each integer is used to store the data. This means each integer represents only 1 byte of data.
 */

class Solution {
public:
	static bool validUtf8(const std::vector<int>& data) {
		int state = 0;
		for (int i : data) {
			if (state) {
				if (i < 0x80 || i > 0xBF)
					return false;
				--state;
			} else {
				if (i < 0x80) continue;
				for (int j = 0x80; i & j; j >>= 1)
					++state;
				if ((!--state) || (state > 3))
					return false;
			}
		}
		return state == 0;
	}
};

int main() {
	std::cout << Solution::validUtf8({235, 140, 4});
	return 0;
}
