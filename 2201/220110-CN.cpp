#include <string>

class Solution {
private:
	inline static unsigned long long readStr(const char* const str, int L, int R) {
		unsigned long long ret = 0;
		for (int i = L; str[i] && i < R; ++i)
			ret = (ret << 3) + (ret << 1) + (str[i] ^ 48);
		return ret;
	}
public:
	static bool isAdditiveNumber(const std::string& num) {
		int len = num.length();
		const char* const str = num.c_str();
		for (int i = 1, stop = 0; !stop && i + i <= len; ++i) {
			// i: length of 1st number
			// printf("+ 1st num has length %d\n", i);
			for (int j = 1, stopJ = 0; !stopJ && i + j + j <= len; ++j) {
				// j: length of 2nd number
				// printf("++ 2nd num has length %d\n", j);
				unsigned long long n1 = readStr(str, 0, i);
				unsigned long long n2 = readStr(str, i, i + j);
				for (int pos = i + j; pos < len; ) {
					unsigned long long n3 = n1 + n2;
					int n3L = 0;
					for (unsigned long long tmp = n3; tmp; tmp /= 10, ++n3L);
					if (n3 == 0) n3L = 1;
					// printf("+++ next num should be %lld, has length %d, should at %d\n", n3, n3L, pos);
					if (pos + n3L > len) {
						// printf("+++ next num length exceeded, abort j.\n");
						stopJ = 1;
						break;
					}
					unsigned long long readNum = readStr(str, pos, pos + n3L);
					// printf("+++ next num is %lld.\n", readNum);
					if (readNum == n3) {
						// printf("+++ next num is validated.\n");
						if (pos + n3L == len)
							return true;
						pos = pos + n3L;
						n1 = n2;
						n2 = n3;
						// printf("+++ next position is %d.\n", pos);
					} else {
						// printf("+++ next num is not validated, try next j.\n");
						break;
					}
				}
				if (*(str + i) == '0') break;
			}
			if (*str == '0') break;
		}
		return false;
	}
};

int main() {
	// printf("%s\n", Solution::isAdditiveNumber("123") ? "true" : "false");
	return 0;
}