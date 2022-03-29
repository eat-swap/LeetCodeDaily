#include <string>
#include <functional>
#include <iostream>

/**
 * 2024. Maximize the Confusion of an Exam
 * A teacher is writing a test with n true/false questions, with 'T' denoting true and 'F' denoting false. He wants to confuse the students by maximizing the number of consecutive questions with the same answer (multiple trues or multiple falses in a row).
 * You are given a string answerKey, where answerKey[i] is the original answer to the ith question. In addition, you are given an integer k, the maximum number of times you may perform the following operation:
 * Change the answer key for any question to 'T' or 'F' (i.e., set answerKey[i] to 'T' or 'F').
 * Return the maximum number of consecutive 'T's or 'F's in the answer key after performing the operation at most k times.
 */

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
