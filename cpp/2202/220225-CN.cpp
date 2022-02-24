#include <complex>
#include <cstdio>
#include <string>

/**
 * 537. Complex Number Multiplication
 * A complex number can be represented as a string on the form "real+imaginaryi" where:
 * real is the real part and is an integer in the range [-100, 100].
 * imaginary is the imaginary part and is an integer in the range [-100, 100].
 * i2 == -1.
 * Given two complex numbers num1 and num2 as strings, return a string of the complex number that represents their multiplications.
 */

class Solution {
public:
	static std::string complexNumberMultiply(const std::string& num1, const std::string& num2) {
		int r1, r2, i1, i2;
		std::sscanf(num1.c_str(), "%d+%d", &r1, &i1);
		std::sscanf(num2.c_str(), "%d+%d", &r2, &i2);
		std::complex<int> c1(r1, i1), c2(r2, i2);
		auto ans = c1 * c2;
		char ret[50]{};
		std::sprintf(ret, "%d+%di", ans.real(), ans.imag());
		return ret;
	}
};

int main() {
	// too simple to test
	return 0;
}
