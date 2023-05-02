#ifndef LEETCODE_CPP_DEFS_H
#define LEETCODE_CPP_DEFS_H

#include <vector>

class LC230501CN {
public:
	using CVIR = const std::vector<int>&;
	static int numOfMinutes(int, int, CVIR, CVIR);
};

class LC230501 {
public:
	static double average(const std::vector<int>&) noexcept;
};

class LC230502CN {
public:
	static std::vector<int> powerfulIntegers(int, int, int) noexcept;
};


#endif //LEETCODE_CPP_DEFS_H
