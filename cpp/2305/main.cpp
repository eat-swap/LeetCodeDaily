#include <cstdio>
#include <exception>
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

int* partition(int* L, int* R) {
	int pivot = R - L;
	std::swap(L[rand() % pivot], *R);
	int pivot_index = 0;
	for (int i = 0; i < pivot; ++i)
		if (L[i] < *R)
			std::swap(L[i], L[pivot_index++]);
	std::swap(*R, L[pivot_index]);
	return pivot_index + L;
}

void quick_sort(int* L, int* R) {
	if (L >= R)
		return;
	if (R - L == 1) {
		if (*L > *R)
			std::swap(*L, *R);
		return;
	}
	int* pivot = partition(L, R);
	quick_sort(L, pivot - 1);
	quick_sort(pivot + 1, R);
}

void heapify(int* L, int* R) {
	int len = R - L + 1;
	int* rs = L - 1;
	for (int i = len; i; --i) {
		if (rs[i] > rs[i >> 1])
			std::swap(rs[i], rs[i >> 1]);
	}
}

int main() {
	LC230520::calcEquation(
		{{"a", "b"}, {"b", "c"}},
		{2.0, 3.0},
		{{"a", "c"}, {"b", "a"}}
	);
	return 0;
}
