#include <vector>

class Solution {
public:
	static void reverseString(std::vector<char>& s) {
		char tmp;
		for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
			tmp = s[i];
			s[i] = s[j];
			s[j] = tmp;
		}
	}
};

int main() {
	const char str[] = "hello";
	std::vector<char> args;
	args.reserve(sizeof str);
	for (auto i : str)
		if (i)
			args.push_back(i);
	Solution::reverseString(args);
	return 0;
}