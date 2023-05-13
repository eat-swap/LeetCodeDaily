#include <cstdio>
#include <iostream>
#include <ostream>
#include <unordered_set>
#include <vector>

#include "defs.h"

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& x) noexcept {
	for (auto&& i : x)
		os << i << ", ";
	return os;
}

int main() {
	std::cout << LC230513::countGoodStrings(2,3,1,2);
	return 0;
}
