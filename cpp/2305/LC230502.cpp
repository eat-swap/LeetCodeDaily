#include <numeric>
#include <vector>

/**
 * 1822. Sign of the Product of an Array
 *
 * There is a function signFunc(x) that returns:
 *
 * 1 if x is positive.
 * -1 if x is negative.
 * 0 if x is equal to 0.
 * You are given an integer array nums. Let product be the product of all values in the array nums.
 *
 * Return signFunc(product).
 */

class LC230502 {
public:
	static int arraySign(const std::vector<int>&) noexcept;
};

inline constexpr int sgn(int x) noexcept { return (x >> 31) | !!x; }

int LC230502::arraySign(const std::vector<int>& n) noexcept {
	return std::reduce(n.begin(), n.end(), 1, [](int x, int y) {
		return sgn(x) * sgn(y);
	});
}
