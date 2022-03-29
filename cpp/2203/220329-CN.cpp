#include <string>
#include <functional>
#include <iostream>

class Solution {
public:
	static int maxConsecutiveAnswers(const std::string& answerKey, int k) {
		int n = answerKey.length();
		std::function<int(char)> solve = [&](char ch) {
			int L = 0, R = 0, cnt = 0;
			// Interval: [L, R)
			// Initial
			for (; R < n && cnt < k; ++R)
				if (answerKey[R] != ch)
					++cnt;
			int ret = R - L;
			for (; R < n; ++R) {
				if (answerKey[R] != ch) {
					ret = std::max(ret, R - L);
					while (answerKey[L] == ch)
						++L;
					++L;
				}
			}
			return std::max(ret, R - L);
		};
		return std::max(solve('T'), solve('F'));
	}
};

int main() {
	std::cout << Solution::maxConsecutiveAnswers("TFFT", 1);
	return 0;
}
