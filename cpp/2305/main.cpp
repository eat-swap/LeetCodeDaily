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
	std::cout << LC230504CN::maxTotalFruits({
												{0,3},{6,4},{8,5}
	}, 3,2);
	return 0;
}
