#include <string>

/**
 * 1189. Maximum Number of Balloons
 * Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.
 * You can use each character in text at most once. Return the maximum number of instances that can be formed.
 */

class Solution {
public:
	static int maxNumberOfBalloons(const std::string& text) {
		int b = 0, a = 0, l = 0, o = 0, n = 0;
		for (char ch : text) {
			switch (ch) {
				case 'b':
					++b;
					break;
				case 'a':
					++a;
					break;
				case 'l':
					++l;
					break;
				case 'o':
					++o;
					break;
				case 'n':
					++n;
					break;
				default:;
			}
		}
		l /= 2;
		o /= 2;
		return std::min(b, std::min(a, std::min(l, std::min(o, n))));
	}
};

int main() {
	return 0;
}
