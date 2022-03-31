#include <vector>

template<int N>
class AnswerTable {
public:
	bool isNotAnswer[N]{};

	explicit constexpr AnswerTable() {
		for (int i = 1; i < N; ++i) {
			for (int j = i; j; j /= 10) {
				if (!(j % 10) || i % (j % 10)) {
					isNotAnswer[i] = true;
					break;
				}
			}
		}
	}
};

/**
 * 728. Self Dividing Numbers
 * A self-dividing number is a number that is divisible by every digit it contains.
 * - For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
 * A self-dividing number is not allowed to contain the digit zero.
 * Given two integers left and right, return a list of all the self-dividing numbers in the range [left, right].
 */

class Solution {
private:
	static constexpr AnswerTable<10001> ans = AnswerTable<10001>();
public:
	static std::vector<int> selfDividingNumbers(int left, int right) {
		std::vector<int> ret;
		for (int i = left; i <= right; ++i)
			if (!ans.isNotAnswer[i])
				ret.push_back(i);
		return ret;
	}
};
