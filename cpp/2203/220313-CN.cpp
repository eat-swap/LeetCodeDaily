#include <vector>
#include <iostream>

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
