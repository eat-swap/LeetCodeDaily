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
	std::vector<int> arr {2,3,3,4,6,7};
	std::cout << LC230506::numSubseq(arr,12);
	return 0;
}
