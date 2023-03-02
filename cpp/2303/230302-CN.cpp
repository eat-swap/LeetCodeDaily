#include <string>
#include <iostream>

/**
 * 面试题 05.02. Binary Number to String LCCI
 *
 * Given a real number between 0 and 1 (e.g., 0.72) that is passed in as a double, print the binary representation. If the number cannot be represented accurately in binary with at most 32 characters, print "ERROR".
 */

class Solution {
public:
	static std::string printBin(const double n) {
		const auto b = *reinterpret_cast<const unsigned long long*>(&n);
		const auto d = 1023 - ((b >> 52) & 0x7FF);
		const auto e = b & 0x000FFFFFFFFFFFFF;

		const auto mask = (1ULL << (52 - (31 - d))) - 1;
		if (e & mask)
			return "ERROR";
		auto ret = std::string("0.").append(d - 1, '0').append(1, '1');
		for (int i = 0; i < 31 - d; ++i)
			ret.push_back(((1ULL << (51 - i)) & e) ? '1' : '0');
		for (; '0' == ret.back(); ret.pop_back());
		return ret;
	}
};

int main() {
	std::cout << Solution::printBin(0.1);
	return 0;
}
