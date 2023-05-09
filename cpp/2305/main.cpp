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
	std::cout << LC230509::spiralOrder({
		{2,3,4},
		{5,6,7},
		{8,9,10},
		{11,12,13}
	});
	return 0;
}
