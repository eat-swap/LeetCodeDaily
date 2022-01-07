#include <cstdio>
#include <string>

class Solution {
public:
	static int maxDepth(const std::string& s) {
		int ret = 0, current = 0;
		for (const char* ptr = s.c_str(); *ptr; ++ptr)
			switch (*ptr) {
				case '(':
					++current;
					ret = current > ret ? current : ret;
					break;
				case ')':
					--current;
			}
		return ret;
	}
};

int main() {
	std::printf("%d\n", Solution::maxDepth("()()()(()())"));
	return 0;
}
