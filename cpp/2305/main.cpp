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
	using ULL = unsigned long long;
	int ok = 0, not_ok = 0;
	for (int i : {99, 101, 9999}) {
		int sum = 0;
		std::unordered_set<ULL> vis;
		for (int j = 1, c = 1;; (j = (j * 10) % i), ++c) {
			sum = (sum + j) % i;
			if (sum == 0) {
				std::printf("%6d -> %d\n", i, c);
				++ok;
				break;
			}
			auto key = (ULL(sum) << 32) + j;
			if (vis.contains(key)) {
				std::printf("%6d -> CANNOT\n", i);
				++not_ok;
				break;
			}
			vis.insert(key);
		}
	}
	std::printf("[OK] %d | [FAIL] %d\n", ok, not_ok);
	return 0;
}
