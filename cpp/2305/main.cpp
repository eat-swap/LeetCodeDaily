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
	std::cout << LC230511CN::queryString("0110", 3);
	return 0;
}
