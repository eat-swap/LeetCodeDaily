#include <string>
#include <algorithm>

class Solution {
public:
	static int lengthLongestPath(const std::string& input) {
		int max = 0;
		short partLen[5001]{};

		for (const char* ptr = input.c_str(); *ptr; ++ptr) {
			short level = 0, len = 0, current = 0, ok = 0;
			for (; *ptr && *ptr == '\t'; ++ptr)
				++level;
			for (; *ptr && *ptr != '\n'; ++ptr, ++len)
				ok |= (*ptr == '.');
			partLen[level] = len;

			if (!ok)
				continue;

			for (int i = level; i >= 0; --i)
				current += partLen[i];
			max = std::max(max, current + level);

			if (!*ptr)
				break;
		}
		return max;
	}
};

int main() {
	auto x = Solution::lengthLongestPath("a");
	return 0;
}
