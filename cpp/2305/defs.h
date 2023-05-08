#ifndef LEETCODE_CPP_DEFS_H
#define LEETCODE_CPP_DEFS_H

#include <vector>
#include <string>

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

class LC230502 {
public:
	static int arraySign(const std::vector<int>&) noexcept;
};

class LC230503CN {
public:
	static bool isValid(const std::string&) noexcept;
};

class LC230503 {
public:
	template<typename T>
	using V = std::vector<T>;
	using VVI = V<V<int>>;
	using CVIR = const V<int>&;

	static VVI findDifference(CVIR, CVIR) noexcept;
};

class LC230504CN {
public:
	static int maxTotalFruits(const std::vector<std::vector<int>>&, int, int) noexcept;
};

class LC230504 {
public:
	static std::string predictPartyVictory(std::string) noexcept;
};

class LC230505CN {
public:
	static int hardestWorker(int, const std::vector<std::vector<int>>&) noexcept;
};

class LC230505 {
public:
	static int maxVowels(const std::string&, int) noexcept;
};

class LC230506 {
public:
	static int numSubseq(std::vector<int>&, int) noexcept;
};

class LC230506CN {
public:
	static int minNumberOfFrogs(const std::string&) noexcept;
};

class LC230507 {
public:
	static std::vector<int> longestObstacleCourseAtEachPosition(const std::vector<int>&) noexcept;
};

class LC230508 {
public:
	static int diagonalSum(const std::vector<std::vector<int>>&) noexcept;
};

#endif //LEETCODE_CPP_DEFS_H
