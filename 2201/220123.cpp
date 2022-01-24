#include <vector>
#include <cstdio>

template<int L, int R>
struct TableGenerator {
	int answer[50] {};
	int size = 0;

	constexpr TableGenerator() : answer(), size(0) {
		auto gen = [](int begin, int digits) {
			int ret = begin;
			for (int i = 1; i < digits; ++i) {
				ret = 10 * ret + (i + begin);
			}
			return ret;
		};
		int digitsL = 0, beginL, ans = 0;
		for (int i = L; i; i /= 10) {
			++digitsL;
			beginL = i;
		}
		for (int d = digitsL, lim = std::min(R, 123456789); ans < lim; ++d) {
			for (int b = (d == digitsL) ? beginL : 1; ans < lim && b + d <= 10; ++b) {
				answer[size++] = ans = gen(b, d);
			}
		}
	}
};

class Solution {
private:
	inline static constexpr TableGenerator<10, 1000000000> table;
public:
	static std::vector<int> sequentialDigits(int low, int high) {
		return {std::lower_bound(table.answer, table.answer + table.size, low), std::lower_bound(table.answer, table.answer + table.size, 1 + high)};
	}
};

int main() {
	auto ret = Solution::sequentialDigits(1000, 123456789);
	for (int i : ret)
		std::printf("%d\n", i);
	return 0;
}
