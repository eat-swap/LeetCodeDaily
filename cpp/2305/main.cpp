#include <iostream>
#include <ostream>
#include <vector>

#include "defs.h"

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& x) noexcept {
	for (auto&& i : x)
		os << i << ", ";
	return os;
}

int main() {
	std::cout << LC230501::average({1, 2, 3, 4}) << std::endl;
	std::cout << LC230501CN::numOfMinutes(1, 0, {-1}, {0}) << std::endl;
	std::cout << LC230502CN::powerfulIntegers(2, 1, 10) << std::endl;
	return 0;
}
