#include <string>

class Solution {
public:
	static int calculate(const std::string& s) {
		int ret = 0;
		char op = '+', prevOp = '+';
		int n = 0, mid = 0;
		for (const char c : s) {
			if (c >= 0x30 && c <= 0x39) { n = (n << 3) + (n << 1) + (c ^ 48); }
			else if (c == '+' || c == '-') {
				switch (op) {
					case '+':
						ret += n; break;
					case '-':
						ret -= n; break;
					case '*':
						mid *= n; ret += prevOp == '+' ? mid : -mid; break;
					case '/':
						mid /= n; ret += prevOp == '+' ? mid : -mid; break;
					default: exit(114514);
				}
				n = 0; op = c;
			} else if (c == '*' || c == '/') {
				switch (op) {
					case '+':
					case '-':
						prevOp = op; mid = n; break;
					case '*':
						mid *= n; break;
					case '/':
						mid /= n; break;
					default: exit(1919810);
				}
				n = 0; op = c;
			}
		}
		switch (op) {
			case '+':
				ret += n; break;
			case '-':
				ret -= n; break;
			case '*':
				mid *= n; ret += prevOp == '+' ? mid : -mid; break;
			case '/':
				mid /= n; ret += prevOp == '+' ? mid : -mid; break;
			default: exit(114514);
		}
		return ret;
	}
};

int main() {
	std::printf("%d\n", Solution::calculate("-1-2*3+4/5"));
	return 0;
}
