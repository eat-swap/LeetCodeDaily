#include <string>
#include <iostream>
#include <random>

class Solution {
public:
	static std::string addBinary(const std::string& a, const std::string& b) {
		char* const ret = new char[std::max(a.length(), b.length()) + 2]{};
		int cin = 0;
		for (int pos = std::max(a.length(), b.length()), posA = a.length() - 1, posB = b.length() - 1; posA >= 0 || posB >= 0; --posA, --posB, --pos) {
			ret[pos] = (((posA < 0 ? 0 : (a[posA] ^ 48)) + (posB < 0 ? 0 : (b[posB] ^ 48)) + cin) & 1) ^ 48;
			cin = ((posA < 0 ? 0 : (a[posA] ^ 48)) + (posB < 0 ? 0 : (b[posB] ^ 48)) + cin) >> 1;
		}
		if (cin)
			*ret = '1';
		std::string r(*ret ? ret : (ret + 1));
		delete[] ret;
		return r;
	}
};

int main() {
	std::cout << Solution::addBinary("0", "1");
	return 0;
}
